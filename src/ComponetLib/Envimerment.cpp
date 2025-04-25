#include "Envimerment.hpp"
#include "../lib/Lib.hpp"
#include "player.hpp"
#include <unordered_map>
#include <iostream>

namespace Componets {
using namespace Engen;

Environment::Environment(Player &player, int w, int h, int spriteSize, std::string spriteSheet)
    : RenderAble(), player_(player), w_(w), h_(h), spriteSize_(spriteSize), spriteSheet_(spriteSheet) {
  
  // Create a texture to render the environment to
  texture_ = SDL_CreateTexture(ViewPort::GetInstance().getRenderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, w_ * spriteSize_, h_ * spriteSize_);
  if (!texture_) {
    // Handle texture creation failure (log error, etc.)
    std::cerr << "Failed to create texture: " << SDL_GetError() << std::endl;
    return;
  }

  // Set the texture as the render target
  SDL_SetRenderTarget(ViewPort::GetInstance().getRenderer(), texture_);

  // Render all tiles to the texture
  for (int i = -w; i < w; ++i) {
    for (int j = -h; j < h; ++j) {
      Vec2 tilePos = {i * spriteSize_, j * spriteSize_};
      SDL_Rect rect = {tilePos.x, tilePos.y, spriteSize_, spriteSize_};
      
      std::cout << "sprite added to texture: x:" << i << " y:" << j << std::endl;
      SpriteSheet::render(ViewPort::GetInstance().getRenderer(), rect.x, rect.y, rect.w, rect.h, spriteSheet_, 0, 0);
    }
  }

  // Reset render target to default (screen)
  SDL_SetRenderTarget(ViewPort::GetInstance().getRenderer(), nullptr);
}

void Environment::render(SDL_Renderer *renderer) {
  Vec2 cameraPos = {Camera::GetInstance().getX(),Camera::GetInstance().getY()};

    for (int i = 0; i < w_; ++i) {
        for (int j = 0; j < h_; ++j) {
            Vec2 tilePos = {i * spriteSize_, j * spriteSize_};

            tilePos.x -= cameraPos.x;
            tilePos.y -= cameraPos.y;

            SDL_Rect rect = {tilePos.x, tilePos.y, spriteSize_, spriteSize_};
            SDL_Rect screen = ViewPort::GetInstance().WorldToScreen(rect);

            SpriteSheet::render(renderer, screen.x, screen.y, screen.w, screen.h, spriteSheet_, 0, 0);
        }
    }
}


} // namespace Componets
