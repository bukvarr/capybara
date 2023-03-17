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
  void Update(Input* input);

  const std::vector<std::deque<Object*>>& GetMov() const;
  const std::vector<std::vector<Object*>>& GetStatic() const;
  const Object* GetPl_0bj() const;

  const std::vector<int>& GetMovH() const;
  const std::vector<int>& GetStaticH() const;

  const std::vector<LineStruct> GetLines() const;

  ~Map();

 private:
  std::vector<std::deque<Object*>> movable_objs;
  std::vector<int> mov_objs_h;
  std::vector<int> static_objs_h;
  std::vector<std::vector<Object*>> static_objs;

  std::vector<LineStruct> lines;

  Object* pl_obj;

  Point* center;
};


#endif //SRC_MAP_H
