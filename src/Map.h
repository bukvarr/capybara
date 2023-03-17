//
// Created by bukvar on 16.03.23.
//

#ifndef SRC_MAP_H
#define SRC_MAP_H

#include "Project.h"

class Point;
class Object;
class Input;
class LineStruct;

class Map {
 public:
  Map();
  void CreateMap();
  void Update(Input* input);

  std::vector<std::deque<Object*>> movable_objs;
  std::vector<int> mov_objs_h;
  std::vector<int> static_objs_h;
  std::vector<std::vector<Object*>> static_objs;

  std::vector<LineStruct> lines;

  Object* pl_obj;

  Point* center = new Point(GameConstants::screen_width + 1,
                            GameConstants::screen_height + 1);

  ~Map();
};


#endif //SRC_MAP_H
