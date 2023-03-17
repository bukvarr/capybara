//
// Created by bukvar on 16.03.23.
//

#ifndef SRC_GAMEPROCESS_H
#define SRC_GAMEPROCESS_H

#include "Project.h"
class Map;

class Game {
  Game();

  void GameProcess();
  bool CheckLose();
  bool CheckWin();
  void Exit();
  void Won();
  void Lost();

 private:
  bool run;
//Graphics* graphics;
  Input* input;
  Map* map;

  ~Game();
};

#endif //SRC_GAMEPROCESS_H
