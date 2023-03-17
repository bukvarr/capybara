//
// Created by sergey on 17.03.2023.
//

#include "GameProcess.h"

Game::Game() : run(true), input(new Input), map(new Map) {
  map->CreateMap();
}

Game::~Game() {
  delete map;
  delete input;
}

void Game::GameProcess() {
  while (run) {
    input->Update();
    if (input->IsExit()) { // передалать скорее всего
      Exit();
    }
    map->Update(input);
    if (CheckWin()) { // передалать скорее всего
      run = false;
      Won();
      break;
    }
    if (CheckLose()) { // передалать скорее всего
      run = false;
      Lost();
      break;
    }
    SDL_Delay(GameConstants::update_delay);
  }
}

bool Game::CheckWin() {
  return map->pl_obj->GetY() >= GameConstants::play_zone_h;
}

bool Game::CheckLose() { //сначала проверять на вин))
  if (map->pl_obj->isOutOfBorder()) {
    return true;
  }
  int h = map->pl_obj->GetY() + map->center->y;
  if (map->lines[h].indicator == LineIndicators::freeline_ind) {
    return false;
  }
  if (map->lines[h].indicator == LineIndicators::treeline_ind) {
    std::vector<Object*>::const_iterator it;
    for (it = map->static_objs[map->lines[h].index].cbegin();
         it != map->static_objs[map->lines[h].index].cend(); ++it) {
      if (map->pl_obj->Intersects(**it)) {
        return true;
      }
    }
  }
  if (map->lines[h].indicator == LineIndicators::road_ind) {
    std::deque<Object*>::const_iterator it;
    for (it = map->movable_objs[map->lines[h].index].cbegin();
         it != map->movable_objs[map->lines[h].index].cend(); ++it) {
      if (map->pl_obj->Intersects(**it)) {
        return true;
      }
    }
  }
}