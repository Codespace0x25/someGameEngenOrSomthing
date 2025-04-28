#pragma once
#include "../ComponetLib/Strucher.hpp"
#include "../ComponetLib/player.hpp"
#include "../lib/Lib.hpp"
#include <string>

namespace Game {
class Bush : public Componets::Strucher {
public:
  Bush(Componets::Player &player, int x, int y, int w, int h, std::string SpriteSheet);
  void render(SDL_Renderer *renderer) override;
  void handleEvent(const SDL_Event &e) override;
  void Update(Uint32 delta) override;
  void Ready() override;
private:
  bool hasBarys = true;
};
} // namespace Game
