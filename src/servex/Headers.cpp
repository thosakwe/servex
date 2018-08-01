// Copyright (c) 2018, Tobechukwu Osakwe.
//
// All rights reserved.
//
// Use of this source code is governed by an
// MIT-style license that can be found in the LICENSE file.
#include <sstream>
#include "Headers.h"

servex::Headers::Headers() = default;

servex::Headers::Headers(const servex::Headers &other) {
    if (this != &other) {
        headers.insert(other.headers.begin(), other.headers.end());
    }
}

servex::Headers::Headers(const servex::Headers &&other) {
    if (this != &other) {
        headers.insert(other.headers.begin(), other.headers.end());
    }

    other.headers.clear();
}

bool servex::Headers::Contains(const std::string &name) const {
    return headers.find(name) != headers.end();
}

const std::vector<std::string> &servex::Headers::Get(const std::string &name) const {
    if (Contains(name)) {
        return headers.at(name);
    } else {
        // TODO
    }
}

std::string servex::Headers::Join(const std::string &name) const {
    std::ostringstream oss;

    unsigned long i = 0;

    for (auto &value : Get(name)) {
        if (i++ > 0) oss << ",";
        oss << name;
    }

    return oss.str();
}

void servex::Headers::Add(const std::string &name, const std::string &value) {
    Get(name).push_back(value);
}

void servex::Headers::Overwrite(const std::string &name, const std::string &value) {
    auto &values = Get(name);
    values.clear();
    values.push_back(value);
}

void servex::Headers::Clear() {
    headers.clear();
}
