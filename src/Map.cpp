//
// Created by bukvar on 16.03.23.
//

#include"Map.h"

ConstantPoints const_points;

Map::Map() = default; // переделатб

void Map::CreateMap() {
  pl_obj = Pl_ObjCreator::CreateObj(
          new Point(center->x - GameConstants::play_zone_h + 1, center->y));
  int i = GameConstants::obstacle_start;
  while (i < GameConstants::screen_height) {
    if (std::rand() % GameConstants::treeline_spawn_rate == 0) {
      lines.push_back(LineStruct(LineIndicators::treeline_ind, static_objs_h.size()));
      static_objs_h.push_back(i);
      static_objs.push_back(std::vector<Object*>());
      i += GameConstants::obstacle_line_min_dist;
      for (int t = 1; t < GameConstants::obstacle_line_min_dist; ++t) {
        lines.push_back(LineStruct());
      }
      int j = center->x - GameConstants::screen_width + ObjConstants::tree_w;
      while (j < GameConstants::play_zone_w - ObjConstants::tree_w) {
        if (std::rand() % GameConstants::tree_spawn_rate == 0) {
          (static_objs.end() - 1)->push_back(TreeCreator::CreateObj(
                  new Point(i, j)));
          j+= GameConstants::tree_spawn_min_dist;
        }
      }
    } else if (std::rand() % GameConstants::road_spawn_rate == 0) {
      lines.push_back(LineStruct(LineIndicators::road_ind, mov_objs_h.size()));
      mov_objs_h.push_back(i);
      movable_objs.push_back(std::deque<Object*>());
      i += GameConstants::obstacle_line_min_dist;
      for (int t = 1; t < GameConstants::obstacle_line_min_dist; ++t) {
        lines.push_back(LineStruct());
      }
    } else {
      lines.push_back(LineStruct());
    }
  }
}

void Map::Update(Input* input) {
  std::vector<LineStruct>::const_iterator vit;
  for (vit = lines.cbegin(); vit != lines.cend(); ++vit) {
    if (vit->indicator!= LineIndicators::road_ind) {
      continue;
    }
    int index = vit->index;
    std::deque<Object*>::reverse_iterator it;
    for (it = movable_objs[index].rbegin(); it != movable_objs[index].rend(); ++it) {
      (*it)->Boost();
      if ((*it)->isOutOfBorder()) {
        delete *it;
        movable_objs[index].pop_back();
      }
    }
    if ((movable_objs[index].empty() || (*movable_objs[index].begin())->GetX() >
    center->x - GameConstants::play_zone_w + GameConstants::car_spawn_min_dist) &&
        std::rand() % GameConstants::car_spawn_rate == 0) {
      movable_objs[index].push_front(CarCreator::CreateObj(
                 new Point(center->x - GameConstants::play_zone_w + ObjConstants::car_w, mov_objs_h[index])));
    }
  }
  if (input != nullptr) {
    if (input->IsKeyUp()) {
      pl_obj->Move(const_points.up);
    }
    if (input->IsKeyDown()) {
      pl_obj->Move(const_points.down);
    }
    if (input->IsKeyLeft()) {
      pl_obj->Move(const_points.left);
    }
    if (input->IsKeyRight()) {
      pl_obj->Move(const_points.right);
    }
  }
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
  delete center;
}