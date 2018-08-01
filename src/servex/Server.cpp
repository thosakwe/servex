// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "InternalServerError.h"
#include "Server.h"

using namespace servex;

servex::Server::Server(servex::Driver *driver) {
    this->driver = driver;
}

void servex::Server::AddHandler(const servex::Handler *handler) {
    handlers.push_back(handler);
}

void servex::Server::Listen() {
    bool success = true;
    while (!driver->IsDone()) {
        try {

            auto _client = driver->Accept(&success);

            if (success) {
                auto *client = &_client;
                for (auto &handler : handlers) {
                    if (handler->CanAccept(*client)) {
                        auto *old = client;
                        client = handler->Transform(client);

                        if (old != client) {
                            // TODO: Handle new destructor, etc.
                            delete old;
                        }

                        handler->Handle(client->request, client->response);
                    }
                }
            }
        } catch (HttpException &exc) {
            // TODO: Handle this
        }
    }
}
