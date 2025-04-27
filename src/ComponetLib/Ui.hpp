#pragma once

#include "../lib/Lib.hpp"
#include "player.hpp"


namespace Componets {
  using namespace Engen;
  class UI: public GameObject, public EventHandler{
    public:
    UI(Player& player);
    void render(SDL_Renderer *renderer) override;
    void handleEvent(const SDL_Event &e)override;

    private:
    Player& player_;
    
  };
}
