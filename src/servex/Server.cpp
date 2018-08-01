// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "InternalServerError.h"
#include "Server.h"

servex::Server::Server(servex::Driver *driver) {
    this->driver = driver;
}

void servex::Server::AddHandler(const servex::Handler &handler) {
    handlers.push_back(handler);
}

void servex::Server::AddHandler(const servex::Handler &&handler) {
    handlers.push_back(handler);
}

void servex::Server::Listen() {
    bool success = true;
    do {
        auto &client = driver->Accept(&success);

        if (success) {
            try {
                for (auto &handler : handlers) {
                    if (handler.CanAccept(client)) {
                        client = handler.Transform(client);
                        handler.Handle(client.request, client.response);
                    }
                }
            } catch (HttpException &exc) {
                // TODO: Handle this
            }
        }
    } while (success);
}
