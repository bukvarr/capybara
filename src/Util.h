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

class LineStruct {
 public:
  LineStruct();
  LineStruct(int indicator, int index);

  int indicator;
  int index; // индекс в массиве объектов
};

enum LineIndicators {freeline_ind = 0, treeline_ind = 1, road_ind = 2};

namespace ObjConstants {
    const int car_w = 228;
    const int car_h = 228;
    const int Pl_Obj_w = 228;
    const int Pl_Obj_h = 228;
    const int tree_w = 228;
    const int tree_h = 228;
}

namespace GameConstants {
    const int play_zone_h = 228;
    const int play_zone_w = 228;
    const int obstacle_start = 228;

    const int screen_height = 2288;
    const int screen_width = 2288;
    const int update_delay = 20; //задержка в мс

    const int car_spawn_min_dist = 2288;
    const int tree_spawn_min_dist = 228;
    const int obstacle_line_min_dist = 228;

    const int treeline_spawn_rate = 2;
    const int tree_spawn_rate = 3;
    const int road_spawn_rate = 4;
    const int car_spawn_rate = 3;

}

namespace moves {

}

class ConstantPoints {
 public:
  ConstantPoints();
  const Point* up;
  const Point* down;
  const Point* left;
  const Point* right;
  const Point* car_speed;
  const Point* zero_speed;
  ~ConstantPoints();
};

#endif //SRC_UTIL_H