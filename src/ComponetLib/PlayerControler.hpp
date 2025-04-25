#pragma once
#include "../lib/Lib.hpp"
#include <SDL2/SDL.h>

namespace Componets {
using namespace Engen;
class PlayerControlerDefalt : public EventHandler {
public:
  PlayerControlerDefalt();
  virtual void handleEvent(const SDL_Event &e);
  virtual void forwards(){};
  virtual void backwards(){};
  virtual void left(){};
  virtual void right(){};
  protected:
  bool isUp,isDown,isLeft,isRight;
};
} // namespace Component
