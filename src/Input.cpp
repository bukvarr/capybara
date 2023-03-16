//
// Created by sergey on 16.03.23.
//

#include "Input.h"

void Input::Update() {
    SDL_PollEvent(&event);
}

bool Input::IsKeyDown() {
    return (event.type == SDLK_DOWN);
}

bool Input::IsKeyUp() {
    return (event.type == SDLK_UP);
}

bool Input::IsKeyLeft() {
    return (event.type == SDLK_LEFT);
}

bool Input::IsKeyRight() {
    return (event.type == SDLK_RIGHT);
}