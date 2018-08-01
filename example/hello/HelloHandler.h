// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HELLOHANDLER_H
#define SERVEX_HELLOHANDLER_H

#include <servex/servex.h>

namespace hello
{
    class HelloHandler : public servex::Handler
    {
        bool CanAccept(const servex::Request &request) const override;

        void Handle(const servex::Request &request, servex::Response &response) override;
    };
}

#endif //SERVEX_HELLOHANDLER_H
