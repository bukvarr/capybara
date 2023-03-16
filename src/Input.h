//
// Created by bukvar on 16.03.23.
//

#ifndef SRC_INPUT_H
#define SRC_INPUT_H

#include "Project.h"
#include <cstddef>

class Input {
 public:
  void Update();

  bool IsKeyUp();
  bool IsKeyDown();
  bool IsKeyLeft();
  bool IsKeyRight();

  bool IsExit();

 private:
  SDL_Event event;
};

#endif //SRC_INPUT_H
