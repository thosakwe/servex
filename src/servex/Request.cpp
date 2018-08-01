// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include "Request.h"

const servex::Headers &servex::Request::GetHeaders() const {
    return headers;
}

const servex::Injector &servex::Request::GetInjector() const {
    return injector;
}

servex::Injector &servex::Request::GetMutableInjector() {
    return injector;
}

servex::Headers &servex::Request::GetMutableHeaders() {
    return headers;
}
