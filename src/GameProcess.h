//
// Created by bukvar on 16.03.23.
//

#ifndef SRC_GAMEPROCESS_H
#define SRC_GAMEPROCESS_H

#include "Project.h"

class Game {
  Game();
  void start();


 private:
  bool run;
  int start_time; //время начала в мс
//Graphics* graphics;
  Input* input;
  Map* map;

};

#endif //SRC_GAMEPROCESS_H
