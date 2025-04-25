#pragma once
#include "../lib/Lib.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>

namespace Engen {
typedef struct Vec2 Vec2;
class Camera {
public:
  static Camera& GetInstance(){
    static Camera instance;
    return instance;
  }
  void Move(int dx,int dy){
    x += dx;
    y += dy;
  }


  void Set(int dx,int dy){
    x = dx;
    y = dy;
  }


  int getX(){return x;}
  int getY(){return y;}
    

private:
  Camera() = default;
  int x = 0;
  int y = 0;
};
} // namespace Componets
