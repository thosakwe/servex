// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_HTTPDRIVER_H
#define SERVEX_HTTPDRIVER_H

#include <mutex>
#include "../Driver.h"
#include "../net.h"

namespace servex
{
    class HttpDriver : public Driver
    {
    public:
        void BindIpv4(const sockaddr_in &address, int backlog = SOMAXCONN);

        void BindIpV6(const sockaddr_in6 &address, int backlog = SOMAXCONN);

        bool IsDone() const override;

        Client Accept(bool *success) override;

        struct ClientInfo
        {
            int sockfd;
            sockaddr address;
            socklen_t length;
        };

    private:
        std::mutex serverLock;
        int sockfd;

        void Bind(const sockaddr *address, int backlog);
    };
}

#endif //SERVEX_HTTPDRIVER_H
