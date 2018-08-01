// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_REQUEST_H
#define SERVEX_REQUEST_H

#include "Headers.h"
#include "Injector.h"

namespace servex
{
    class Request
    {
    public:
        const Headers &GetHeaders() const;

        const Injector &GetInjector() const;

        Injector &GetMutableInjector();

        Headers &GetMutableHeaders();

    private:
        Headers headers;
        Injector injector;
    };
}

#endif //SERVEX_REQUEST_H
