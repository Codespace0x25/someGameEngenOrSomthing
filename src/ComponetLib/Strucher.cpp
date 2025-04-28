#include "Strucher.hpp"
#include "../lib/Lib.hpp"
#include "./player.hpp"

namespace Componets {
using namespace Engen;
Strucher::Strucher(std::string name, Player &player, int x, int y, int w, int h,
                   std::string SpriteSheet, int startx, int starty, int endx,
                   int endy)
    : GameObject(name, x, y, w, h), EventHandler(), player_(player),
      SpriteSheet_(SpriteSheet), startX_(startx), startY_(starty), endX_(endx),
      endY_(endy) {}
void Strucher::render(SDL_Renderer *renderer) {}
void Strucher::handleEvent(const SDL_Event &e) {}

void Strucher::Update(Uint32 delta) {}
void Strucher::Ready() {}
} // namespace Componets
