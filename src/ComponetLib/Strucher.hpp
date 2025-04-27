#pragma once
#include "../lib/Lib.hpp"
#include "./player.hpp"

namespace Componets {
using namespace Engen;
class Strucher : public GameObject, public EventHandler {
public:
  Strucher(Player &player);
  void render(SDL_Renderer *renderer) override;
  void handleEvent(const SDL_Event &e) override;

private:
  int startX_, startY_;
  Player &player_;
};
} // namespace Componets
