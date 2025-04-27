#include "PlayerStats.hpp"
#include "../lib/Colour.hpp"
#include "../lib/GameObject.hpp"
#include "../lib/Lib.hpp"
#include "Shapes.hpp"
#include "player.hpp"
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>

namespace Componets {
using namespace Engen;

PlayerHud::PlayerHud(Player &player)
    : GameObject("Hud", 0, 0, 0, 0), player(player) {}
PlayerHud::~PlayerHud() {}

void PlayerHud::Update(Uint32 delta) {}
void PlayerHud::Ready() {}
void PlayerHud::render(SDL_Renderer *renderer) {
  int ww, wh;
  SDL_GetRendererOutputSize(renderer, &ww, &wh);

  // heath
  Shape::filledCircle(renderer, ww - 62 - (60 / 2), 62, 30,
                      Colour::Colour::gray);
  Shape::filledCircalPresent(renderer, ww - 62 - (60 / 2), 62, 30,
                             (double)player.getHeath(),
                             (double)player.getMaxHeath(), Colour::Colour::red);
  SpriteSheet::render(renderer, ww - 62 - (63 / 2) - (63 / 2), 62 - (63 / 2),
                      63, 63, "assets/Ui.png", 0, 0, 32);

  // hunger
  Shape::filledCircle(renderer, ww - 62, 62 + (1 * 62), 30,
                      Colour::Colour::gray);
  Shape::filledCircalPresent(
      renderer, ww - 62, 62 + (1 * 62), 30, (double)player.getHeath(),
      (double)player.getMaxHeath(), Colour::Colour::gold);
  SpriteSheet::render(renderer, ww - 62 - (63 / 2), 62 / 2 + (1 * 63), 63, 63,
                      "assets/Ui.png", 0, 0, 32);

  // thurst
  Shape::filledCircle(renderer, ww - 62 - (30 * 2 + 3), 62 + (1 * 62), 30,
                      Colour::Colour::gray);
  Shape::filledCircalPresent(renderer, ww - 62 - (30 * 2 + 3), 62 + (1 * 62),
                             30, (double)player.getHeath(),
                             (double)player.getMaxHeath(),
                             Colour::Colour::blue);
  SpriteSheet::render(renderer, ww - 62 - (63 / 2) - (30 * 2 + 3),
                      62 / 2 + (1 * 63), 63, 63, "assets/Ui.png", 0, 0, 32);

  // inventory
  for (int i = 0; i != player.inventoryData.maxItem; i++) {
    SpriteSheet::render(renderer, ww - 60, wh / 2 + (i * 60), 60, 60,
                        "assets/Ui.png", 1, 0, 32);
  }
}
} // namespace Componets
