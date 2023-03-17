//
// Created by bukvar on 16.03.23.
//

#include"Map.h"

Map::Map() = default; // переделатб

void Map::CreateMap() {
  pl_obj = Pl_ObjCreator::CreateObj(
          new Point(center->x - GameConstants::play_zone_h + 1, center->y));
  int i = GameConstants::obstacle_start;
  while (i < GameConstants::screen_height) {
    if (std::rand() % GameConstants::treeline_spawn_rate == 0) {
      lines.push_back(LineStruct(GameConstants::treeline_ind, static_objs_h.size()));
      static_objs_h.push_back(i);
      static_objs.push_back(std::vector<Object*>());
      i += GameConstants::obstacle_line_min_dist;
      int j = center->x - GameConstants::screen_width + ObjConstants::tree_w;
      while (j < GameConstants::screen_width - ObjConstants::tree_w) {
        if (std::rand() % GameConstants::tree_spawn_rate == 0) {
          (static_objs.end() - 1)->push_back(TreeCreator::CreateObj(
                  new Point(i, j)));
          j+= GameConstants::tree_spawn_min_dist;
        }
      }
    } else if (std::rand() % GameConstants::road_spawn_rate == 0) {
      lines.push_back(LineStruct(GameConstants::road_ind, mov_objs_h.size()));
      mov_objs_h.push_back(i);
      movable_objs.push_back(std::deque<Object*>());
      i += GameConstants::obstacle_line_min_dist;
    } else {
      lines.push_back(LineStruct());
    }
  }
}

void Map::Update(Input* input) {
  std::vector<std::deque<Object*>>::iterator vit;
  for (vit = movable_objs.begin(); vit != movable_objs.end(); ++vit) {
    std::deque<Object*>::reverse_iterator it;
    for (it = vit->rbegin(); it != vit->rend(); ++it) {
      (*it)->Boost();
      if ((*it)->isOutOfBorder()) {
        delete *it;
        movable_objs.pop_back();
      }
    }
    if ((vit->empty() || (*(vit->begin()))->GetW() > GameConstants::car_spawn_min_dist) &&
        std::rand() % GameConstants::car_spawn_rate == 0) {
      vit->push_front(CarCreator::CreateObj(
                 new Point(0, mov_objs_h[vit - movable_objs.begin()])));
    }
  }
  if (input->IsKeyLeft()) {
      //
  }
  if (input->IsKeyDown()) {
      //
  }
  if (input->IsKeyRight()) {
      //
  }
  if (input->IsKeyUp()) {
      //
  }

}

const std::vector<std::deque<Object*>>& Map::GetMov() const {
  return movable_objs;
}
const std::vector<std::vector<Object*>>& Map::GetStatic() const {
  return static_objs;
}
const Object* Map::GetPl_0bj() const{
  return pl_obj;
}

const std::vector<int>& Map::GetMovH() const {
  return mov_objs_h;
}
const std::vector<int>& Map::GetStaticH() const {
  return static_objs_h;
}

const std::vector<LineStruct> Map::GetLines() const {
  return lines;
}

Map::~Map() {
  std::vector<std::deque<Object*>>::iterator vit1;
  for (vit1 = movable_objs.begin(); vit1 != movable_objs.end(); ++vit1) {
    std::deque<Object*>::iterator it;
    for (it = vit1->begin(); it != vit1->end(); ++it) {
      delete *it;
    }
  }
  std::vector<std::vector<Object*>>::iterator vit2;
  for (vit2 = static_objs.begin(); vit2 != static_objs.end(); ++vit2) {
    std::vector<Object*>::iterator it;
    for (it = vit2->begin(); it != vit2->end(); ++it) {
      delete *it;
    }
  }
  delete pl_obj;
}