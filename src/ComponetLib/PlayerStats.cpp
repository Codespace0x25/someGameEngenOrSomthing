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

  Shape::filledCircle(renderer, ww - 62,62  , 30,Colour::Colour::gray);
  Shape::filledCircalPresent(renderer, ww - 62,62  , 30,
                             (double)player.getHeath(),
                             (double)player.getMaxHeath(),
			     Colour::Colour::red);
}
} // namespace Call_Of_The_Dark

