// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "HttpDriver.h"
#include "HttpDriverException.h"

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

bool servex::HttpDriver::IsDone() const {
    // TODO: Save last acceptance
    //int lastSocket = accept(sockfd);
}

servex::Client &servex::HttpDriver::Accept() const {
    return <#initializer#>;
}
