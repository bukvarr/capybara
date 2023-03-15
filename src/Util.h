//
// Created by sergey on 16.03.23.
//

#ifndef SRC_UTIL_H
#define SRC_UTIL_H

#include "Project.h"

class Point {
 public:
  Point();
  Point(int x, int y);
  operator std::pair<int, int>();

  int x;
  int y;
};

#endif //SRC_UTIL_H
