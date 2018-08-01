// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "HttpException.h"
#include "Server.h"

servex::Server::Server(const servex::Driver *driver) {
    this->driver = driver;
}

void servex::Server::Listen() {
    while (!driver->IsDone()) {
        auto &client = driver->Accept();

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
}
