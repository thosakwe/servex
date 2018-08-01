// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <servex/servex.h>
#include <iostream>
#include <memory>
#include <thread>
#include "HelloHandler.h"

using namespace servex;

void threadMain(const std::shared_ptr<HttpDriver> &driver);

int main() {
    auto driver = std::make_shared<HttpDriver>();
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(3000);

    try {
        driver->BindIpv4(address);

        std::vector<std::thread*> threads;

        for (unsigned int i = 0; i < std::thread::hardware_concurrency(); i++) {
            auto * thread = new std::thread(threadMain, driver);
            threads.push_back(thread);
        }

        std::cout << "Listening at http://127.0.0.1:3000" << std::endl;

        for (auto &thread : threads) {
            thread->join();
        }

        return 0;
    } catch (HttpDriverException &exc) {
        std::cerr << exc.what() << std::endl;
        return 1;
    }
}

void threadMain(const std::shared_ptr<HttpDriver> &driver) {
    Server server(driver.get());
    server.AddHandler(new hello::HelloHandler());
    server.Listen();
}