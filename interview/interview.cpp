//
// Created by wcj on 1/23/18.
//

#include "interview.hpp"
#include <string>

using namespace interview;

const std::string& version() {
    static std::string ver{"1.0"};
    return ver;
}
