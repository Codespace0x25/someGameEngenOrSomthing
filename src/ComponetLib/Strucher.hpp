#pragma once
#include "../lib/Lib.hpp"
#include "./player.hpp"

namespace Componets {
using namespace Engen;
class Strucher : public GameObject, public EventHandler {
public:
  Strucher(std::string name,Player &player, int x, int y, int w, int h, std::string SpriteSheet,
		     int startx, int starty, int endx, int endy);
  void Update(Uint32 delta)override;
  void Ready()override;
  void render(SDL_Renderer *renderer) override;
  void handleEvent(const SDL_Event &e) override;

protected:
  int startX_, startY_, endX_, endY_;
  std::string SpriteSheet_;
  Player &player_;
};
} // namespace Componets
