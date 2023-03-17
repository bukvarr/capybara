//
// Created by sergey on 17.03.2023.
//

#include "GameProcess.h"


void Game::GameProcess() {
  while (run) {
    input->Update();
    map->Update(input);
    SDL_Delay(5);
  }
}