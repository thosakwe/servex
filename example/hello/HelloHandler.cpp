// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <iostream>
#include "HelloHandler.h"

bool hello::HelloHandler::CanAccept(const servex::Client &client) const {
    std::cout << "hmmm" << std::endl;

    for (auto &name : client.request.GetHeaders().GetKeys()) {
        std::cout << name << ": " << client.request.GetHeaders().Join(name);
    }

    return false;
}

void hello::HelloHandler::Handle(const servex::Request &request, servex::Response &response) const {
    // TODO: Implement this
    response.SetStatus(404);
}