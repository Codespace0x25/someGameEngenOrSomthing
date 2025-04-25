#pragma once

#include "../lib/GameObject.hpp"
#include "../lib/Lib.hpp"
#include "player.hpp"

namespace Componets {
using namespace Engen;

class PlayerHud :public GameObject {
public:
  PlayerHud(Player &player);
  ~PlayerHud();

  void Update(Uint32 delta) override;
  void Ready() override;
  void render(SDL_Renderer *renderer) override;
  private:
  Player &player;
};
} // namespace Call_Of_The_Dark
