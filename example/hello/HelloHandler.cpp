// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "HelloHandler.h"

void hello::HelloHandler::Handle(const servex::Request &request, servex::Response &response) {
    // TODO: Implement this
    response.SetStatus(404);
}

bool hello::HelloHandler::CanAccept(const servex::Client &client) const {
    return false;
}
