//
// Created by wcj on 1/16/18.
//

#include "version.hpp"

namespace algorithm {

const std::string &version() {
  static std::string ver = "1.0";
  return ver;
}

}
