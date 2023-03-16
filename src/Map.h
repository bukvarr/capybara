//
// Created by bukvar on 16.03.23.
//

#ifndef SRC_MAP_H
#define SRC_MAP_H

#include "Project.h"

class Map {
 public:
  Map();
  void CreateMap();
  void Update();

  const std::vector<std::deque<Object*>>& GetMov() const;
  const std::vector<Object*>& GetStatic() const;
  const PlayableObj*& GetPl_0bj() const;

  ~Map();

 private:
  std::vector<std::deque<Object*>> movable_objs;
  std::vector<int> mov_objs_h;
  std::vector<Object*> static_objs;
  PlayableObj* pl_obj;
  Point* center;
};


#endif //SRC_MAP_H
