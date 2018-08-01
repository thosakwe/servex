// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include <stack>
#include "http_parser.h"
#include "HttpDriver.h"
#include "HttpDriverException.h"
#include "HttpRequest.h"
#include "HttpResponse.h"

void servex::HttpDriver::BindIpv4(const sockaddr_in &address, int backlog) {
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    Bind((const sockaddr *) &address, backlog);
}

void servex::HttpDriver::BindIpV6(const sockaddr_in6 &address, int backlog) {
    sockfd = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
    Bind((const sockaddr *) &address, backlog);
}

void servex::HttpDriver::Bind(const sockaddr *address, int backlog) {
    if (sockfd < 0) {
        std::string message(strerror(errno));
        throw HttpDriverException(errno, message);
    }

    // Enable address reuse.
    int result;
    result = setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &result, sizeof(result));

    if (result < 0) {
        std::string message(strerror(errno));
        throw HttpDriverException(errno, message);
    }

    // Now, bind the socket.
    result = bind(sockfd, address, sizeof(*address));

    if (result < 0) {
        std::string message(strerror(errno));
        throw HttpDriverException(errno, message);
    }

    // Start listening.
    if (listen(sockfd, backlog) < 0) {
        std::string message(strerror(errno));
        throw HttpDriverException(errno, message);
    }
}

const char *copyString(const char *str, size_t length) {
    auto *s = new char[length + 1];
    memcpy(s, str, length);
    s[length] = 0;
    return s;
}

servex::Client servex::HttpDriver::Accept(bool *success) {
    // TODO: Save last acceptance
    ClientInfo info{};
    int lastSocket = accept(sockfd, &info.address, &info.length);

    if (lastSocket < 0) {
        *success = false;
    } else {
        info.sockfd = lastSocket;
        *success = true;
    }

    HttpRequest request(info);
    HttpResponse response(info);

    std::stack<std::string> headerStack;

    http_parser parser;
    http_parser_init(&parser, HTTP_REQUEST);

    http_parser_settings settings;

    typedef struct
    {
        HttpRequest *request;
        HttpResponse *response;
        std::stack<std::string> *headerStack;
    } ParseState;

    ParseState state;
    parser.data = &state;
    state.request = &request;
    state.response = &response;
    state.headerStack = &headerStack;

    // TODO: Other callbacks

    settings.on_header_field = [](http_parser *parser, const char *msg, size_t length) {
        auto *state = (ParseState *) parser->data;
        auto s = copyString(msg, length);
        state->headerStack->push(s);
        return 0;
    };

    settings.on_header_value = [](http_parser *parser, const char *msg, size_t length) {
        auto *state = (ParseState *) parser->data;
        if (!state->headerStack->empty()) {
            auto &key = state->headerStack->top();
            auto value = copyString(msg, length);
            state->headerStack->pop();
            std::cout << key << " => " << value << std::endl;
            state->request->GetMutableHeaders().Add(key, value);
        }

        return 0;
    };

    unsigned int isUpgrade = 0;
    size_t len = 100 * 1024, nparsed;
    char buf[len];
    ssize_t recved;
    memset(buf, 0, len);

    //std::cout << "start" << std::endl;
    while ((recved = recv(info.sockfd, buf, len, 0)) >= 0)
    {
        if (isUpgrade)
        {
            //send_string(&parser, buf, (size_t)recved, 7, true);
        }
        else
        {
            /* Start up / continue the parser.
             * Note we pass recved==0 to signal that EOF has been received.
             */
            nparsed = http_parser_execute(&parser, &settings, buf, (size_t)recved);

            if ((isUpgrade = parser.upgrade) == 1)
            {
                //send_notification(&parser, 6);
            }
            else if (nparsed != recved)
            {
                //std::cout << "Hm what" << std::endl;
                close(info.sockfd);

                // TODO: Throw an exception? Display an error? etc.?
                *success = false;
            }
        }

        memset(buf, 0, len);
    }

    Client client = {request, response};
    return client;
}

bool servex::HttpDriver::IsDone() const {
    return false;
}
