// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#ifndef SERVEX_INJECTOR_H
#define SERVEX_INJECTOR_H

#include <string>
#include <unordered_map>

namespace servex
{
    // TODO: Custom entries that support destructors
    class Injector
    {
    public:
        template<typename T>
        T *Get(const std::string &name) const {
            return (T *) data.at(name);
        }

        template<typename T>
        void Put(const std::string &name, const T *value) {
            auto it = data.find(name);

            if (it == data.end()) {
                data.insert(std::make_pair(name, (void *) value));
            } else {
                it->second = (void *) value;
            }
        }

    private:
        std::unordered_map<std::string, void *> data;
    };
}

#endif //SERVEX_INJECTOR_H
