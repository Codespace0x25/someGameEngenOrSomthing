#include "Envimerment.hpp"
#include "../lib/Lib.hpp"
#include "../lib/std/random.hpp"
#include "player.hpp"
#include <iostream>
#include <unordered_map>

namespace Componets {
using namespace Engen;

Environment::Environment(Player &player, int w, int h, int spriteSize,
                         std::string spriteSheet, int scale)
    : RenderAble(), player_(player), w_(w), h_(h), spriteSize_(spriteSize),
      spriteSheet_(spriteSheet), scale_(scale) {
  // Create a texture to render the environment to
  texture_ = SDL_CreateTexture(
      ViewPort::GetInstance().getRenderer(), SDL_PIXELFORMAT_RGBA8888,
      SDL_TEXTUREACCESS_TARGET, w_ * spriteSize_ * scale_, h_ * spriteSize_ * scale_);
  if (!texture_) {
    std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    return;
  }

  // Set the texture as the render target
  SDL_SetRenderTarget(ViewPort::GetInstance().getRenderer(), texture_);

  // Render all tiles to the texture
  for (int i = 0; i < w_; ++i) {
    for (int j = 0; j < h_; ++j) {
      int tilex = Engen_std::randIntRange(0, 1);
      int tiley = Engen_std::randIntRange(0, 5);
      Vec2 tilePos = {i * spriteSize_ * scale_, j * spriteSize_ * scale_};
      SDL_Rect rect = {tilePos.x, tilePos.y, spriteSize_ * scale_, spriteSize_ * scale_};
      std::cout << "Sprite added to texture: x:" << i << " y:" << j << std::endl;
      SpriteSheet::render(ViewPort::GetInstance().getRenderer(), rect.x, rect.y,
                          rect.w, rect.h, spriteSheet_, tilex,tiley);
    }
  }

  // Reset render target to default (screen)
  SDL_SetRenderTarget(ViewPort::GetInstance().getRenderer(), nullptr);
}


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
