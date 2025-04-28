#include "ComponetLib/Envimerment.hpp"
#include "ComponetLib/PlayerStats.hpp"
#include "ComponetLib/player.hpp"
#include "lib/Lib.hpp"
#include "lib/std/random.hpp"
#include "lib/Renderable.hpp"
#include "lib/TopLayer.hpp"
#include <SDL2/SDL_stdinc.h>
#include <cstddef>
#include <iostream>
#include <pthread.h>
#include <string>
#include "Game/Bush.hpp"

int main() {
  std::string title = "Cotw - ";
  int errorReturn;

  static Engen::TopLayer engenHook(title, &errorReturn, {900, 600});

  Componets::Player player(20, 20, 16 * 10, 16 * 10, "assets/spriteSheet.png");
  Componets::Environment env(player, 20,20, 16, "assets/spriteSheet.png",10);
  Componets::PlayerHud hud(player);
  engenHook.addRenderAble(&env);
  engenHook.addGameObject(&hud);
  engenHook.addGameObject(&player);
  engenHook.addEventHandlers(&player);
  player.tp(500, 500);
  engenHook.run();

  return 0;
}
