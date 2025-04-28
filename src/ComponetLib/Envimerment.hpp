#pragma once

#include "../lib/Lib.hpp"
#include "Strucher.hpp"
#include "player.hpp"
#include <SDL2/SDL_render.h>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>

namespace Componets {
using namespace Engen;

class Environment : public RenderAble {
public:
  Environment(Player &player, int w, int h, int spriteSize,
              std::string spriteSheet, int scale);
  void render(SDL_Renderer *renderer) override;
  void addStrucher(Strucher* data);

private:
  std::map<std::string, std::map<std::pair<int, int>,float>> Maps;
  int scale_;
  SDL_Texture *texture_;
  std::string spriteSheet_;
  std::map<std::pair<int, int>, Vec2> data;
  std::vector<Strucher*> struchers; 
  Player &player_;
  int w_;
  int h_;
  int spriteSize_;
};

} // namespace Componets
