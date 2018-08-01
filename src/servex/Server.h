// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_SERVER_H
#define SERVEX_SERVER_H

#include <vector>
#include "Handler.h"
#include "Driver.h"

namespace servex
{
    class Server
    {
    public:
        explicit Server(Driver *driver);

        void AddHandler(const Handler &handler);

        void AddHandler(const Handler &&handler);

        void Listen();

    private:
        Driver *driver;
        std::vector<Handler> handlers;
    };
}

#endif //SERVEX_SERVER_H
