#pragma once

#include "../lib/Lib.hpp"
#include "player.hpp"
#include <SDL2/SDL_render.h>
#include <map>
#include <unordered_map>
#include <vector>

namespace Componets {
using namespace Engen;

class Environment : public RenderAble {
public:
  Environment(Player &player, int w, int h, int spriteSize,
              std::string spriteSheet, int scale);
  void render(SDL_Renderer *renderer) override;

private:
  int scale_;
  SDL_Texture *texture_;
  std::string spriteSheet_;
  std::map<std::pair<int, int>, Vec2> data;
  Player &player_;
  int w_;
  int h_;
  int spriteSize_;
};

} // namespace Componets
