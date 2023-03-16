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

  bool IsKeyUp(int key);
  bool IsKeyDown(int key);
  bool IsKeyLeft(int key);
  bool IsKeyRight(int key);

  bool IsExit();

 private:
  SDL_event event
};

#endif //SRC_INPUT_H
