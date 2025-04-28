#include "Envimerment.hpp"
#include "../lib/Lib.hpp"
#include "../lib/std/random.hpp"
#include "../Game/Bush.hpp"
#include "Purlen.hpp"
#include "player.hpp"
#include <algorithm> // for std::shuffle
#include <cmath>
#include <iostream>
#include <random> // for std::mt19937
#include <unordered_map>
#include <vector>
#include <string>

namespace Componets {
using namespace Engen;

enum Bioms {
  Plains = 0,
  Forist = 1,
  Deserts = 2,
  Shallow_Water = 3,
  Deep_Water = 4,
  lava = 5
};

Environment::Environment(Player &player, int w, int h, int spriteSize,
                         std::string spriteSheet, int scale)
    : RenderAble(), player_(player), w_(w), h_(h), spriteSize_(spriteSize),
      spriteSheet_(spriteSheet), scale_(scale) {
  // Create a texture to render the environment to
  texture_ =
      SDL_CreateTexture(ViewPort::GetInstance().getRenderer(),
                        SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET,
                        w_ * spriteSize_ * scale_, h_ * spriteSize_ * scale_);
  if (!texture_) {
    std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    return;
  }

  // Set the texture as the render target
  SDL_SetRenderTarget(ViewPort::GetInstance().getRenderer(), texture_);
  int xs = Engen_std::randIntRange(1, 255);
  int ys = Engen_std::randIntRange(1, 255);
  // Render all tiles to the texture
  for (int i = 0; i < w_; ++i) {
    for (int j = 0; j < h_; ++j) {
      int ma = perlin2d(i, j, 32, 93);
      Vec2 tilePos = {i * spriteSize_ * scale_, j * spriteSize_ * scale_};
      SDL_Rect rect = {tilePos.x, tilePos.y, spriteSize_ * scale_,
                       spriteSize_ * scale_};
      std::cout << "Sprite added to texture: x:" << i << " y:" << j << " = "
                << ma << std::endl;

      SpriteSheet::render(ViewPort::GetInstance().getRenderer(), rect.x, rect.y,
                          rect.w, rect.h, spriteSheet_,
                          Engen_std::randIntRange(0, 1), ma , 16);
    }
  }
  
  // Reset render target to default (screen)
  SDL_SetRenderTarget(ViewPort::GetInstance().getRenderer(), nullptr);
}

void Environment::addStrucher(Strucher *data) { struchers.push_back(data); }

void Environment::render(SDL_Renderer *renderer) {
  Vec2 cameraPos = {Camera::GetInstance().getX(), Camera::GetInstance().getY()};

  SDL_Rect dstRect;
  dstRect.x = -cameraPos.x;
  dstRect.y = -cameraPos.y;
  dstRect.w = w_ * spriteSize_ * scale_;
  dstRect.h = h_ * spriteSize_ * scale_;

  SDL_RenderCopy(renderer, texture_, nullptr, &dstRect);
}

} // namespace Componets
