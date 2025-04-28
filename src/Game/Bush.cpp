#include "Bush.hpp"
#include "../ComponetLib/Strucher.hpp"
#include "../lib/Lib.hpp"
#include <string>

namespace Game {

Bush::Bush(Componets::Player &player, int x, int y, int w, int h, std::string SpriteSheet)
    : Componets::Strucher("bush", player, x, y, w, h, SpriteSheet, 0, 0, 0, 0) {
}

void Bush::render(SDL_Renderer *renderer) {
  for (int i = 0; i != 3; i++) {
    for (int j = 0; j != 2; j++) {
      Engen::SpriteSheet::render(renderer, x+i, y+i, 2, 2, SpriteSheet_, i, j);
    }
  }
}

void Bush::handleEvent(const SDL_Event &e) {}
void Bush::Update(Uint32 delta) {}
void Bush::Ready() {}

} // namespace Game
