#include "PlayerControler.hpp"
#include "../lib/Lib.hpp"
#include <cctype>
#include <iostream>

namespace Componets {
using namespace Engen;
PlayerControlerDefalt::PlayerControlerDefalt() : EventHandler() {

  isUp = false;
  isDown = false;
  isLeft = false;
  isRight = false;
}
void PlayerControlerDefalt::handleEvent(const SDL_Event &e) {
  if (e.type == SDL_KEYDOWN && !e.key.repeat) {
    switch (e.key.keysym.sym) {
    case SDLK_w:
      forwards();
      isUp = true;
      break;
    case SDLK_s:
      backwards();
      isDown = true;
      break;
    case SDLK_a:
      left();
      isLeft = true;
      break;
    case SDLK_d:
      right();
      isRight = true;
      break;
    default:
      break;
    }
  } else {
    if (isUp) {
      forwards();
    }
    if (isDown) {
      backwards();
    }
    if (isLeft) {
      left();
    }
    if (isRight) {
      right();
    }
  }
  if (e.type == SDL_KEYUP && !e.key.repeat) {
    switch (e.key.keysym.sym) {
    case SDLK_w:
      forwards();
      isUp = false;
      break;
    case SDLK_s:
      backwards();
      isDown = false;
      break;
    case SDLK_a:
      left();
      isLeft = false;
      break;
    case SDLK_d:
      right();
      isRight = false;
      break;
    default:
      break;
    }
  }

  if (e.type == SDL_MOUSEBUTTONDOWN) {
    int x, y;
    SDL_GetMouseState(&x, &y);
    std::cout << "you clicked at x:" << x << " y:" << y << "\n";
  }
}

} // namespace Componets
