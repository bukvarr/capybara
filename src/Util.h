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

namespace ObjConstants {
    const int car_w = 228;
    const int car_h = 228;
    const Point* car_speed = new Point(228, 228);
    const int Pl_Obj_w = 228;
    const int Pl_Obj_h = 228;
    const int tree_w = 228;
    const int tree_h = 228;
    const Point* zero_speed = new Point(0, 0);
}

namespace GameConstants {
    const int play_zone_h = 228;
    const int play_zone_w = 228;
    const int screen_height = 228;
    const int screen_width = 228;
    const int update_delay = 20; //задержка в мс
    const int movable_spawn_min_dist = 2288;
    const int static_spawn_min_dist = 228;
}


#endif //SRC_UTIL_H
