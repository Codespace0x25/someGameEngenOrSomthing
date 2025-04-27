#include "Spritesheets.hpp"
#include "Lib.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

namespace Engen {

std::unordered_map<std::string, SheetData> SpriteSheet::sheets_;

void Sprite::render(SDL_Renderer *renderer, int x, int y) const {
  SDL_Rect dest;
  dest.x = x - src.w / 2; // center on x
  dest.y = y - src.h / 2; // center on y
  dest.w = src.w;
  dest.h = src.h;

  SDL_RenderCopy(renderer, texture, &src, &dest);
}
void SpriteSheet::InitSheet(SDL_Renderer *renderer, const std::string path,
                            int spriteW, int spriteH, const std::string name) {
  SDL_Surface *surface = IMG_Load(path.c_str());
  if (!surface) {
    std::cerr << "error unable to load image \n";
    return;
  }
  SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  if (!texture) {
    std::cerr << "error unable to make texture \n";
    return;
  }
  sheets_[name] = {.texture = texture, .spriteW = spriteW, .spriteH = spriteH};
}
void SpriteSheet::render(SDL_Renderer *renderer, int x, int y, int w, int h,
                         std::string spritesheet_, int Sx, int Sy, int spriteSize) {
  SDL_Texture *texture = IMG_LoadTexture(renderer, spritesheet_.c_str());
  if (!texture) {
    SDL_Log("Failed to load texture: %s", IMG_GetError());
    return;
  }
  SDL_Rect srcRect = {Sx*spriteSize, Sy*spriteSize, spriteSize, spriteSize}; // Example: 16x16 sprite size
  SDL_Rect destRect = {x, y, w,
                       h}; // Draw at player's position with width and height

  SDL_RenderCopy(renderer, texture, &srcRect, &destRect);

  SDL_DestroyTexture(texture);
}

} // namespace Engen
