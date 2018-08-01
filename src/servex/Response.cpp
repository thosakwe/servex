// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Response.h"

int servex::Response::GetStatus() const {
    return status;
}

servex::Headers &servex::Response::GetHeaders() {
    return headers;
}

std::ostream &servex::Response::GetBody() {
    return body;
}

void servex::Response::SetStatus(int status) {
    this->status = status;
}
