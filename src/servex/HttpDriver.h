// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HTTPDRIVER_H
#define SERVEX_HTTPDRIVER_H

#include <mutex>

namespace servex
{
    class HttpDriver
    {
    private:
        std::mutex serverLock;
    };
}

#endif //SERVEX_HTTPDRIVER_H
