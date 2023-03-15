//
// Created by sergey on 16.03.23.
//

#include "Util.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

Point::operator std::pair<int, int>() { return std::make_pair(x, y); }