//
// Created by bukvar on 16.03.23.
//

#include"Map.h"


Map::Map() = default;

void Map::Update() {
  std::vector<std::deque<Object*>>::iterator vit;
  for (vit = movable_objs.begin(); vit != movable_objs.end(); ++vit) {
    std::deque<Object*>::reverse_iterator it;
    for (it = vit->rbegin(); it != vit->rend(); ++it) {
      (*it)->Boost();
      if ((*it)->isOutOfBorder()) {
        movable_objs.pop_back();
      }
    }
    if ((*(vit->begin()))->GetW() > GameConstants::movable_spawn_min_dist &&
        std::rand() % 3 == 0) {
      vit->push_front(CarCreator::CreateObj(
                 new Point(0, mov_objs_h[vit - movable_objs.begin()]), center));
    }
  }
  // сдвиг капибары

}