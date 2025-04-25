#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>

namespace Engen {
namespace Colour {

class Colour {
public:
  inline static const SDL_Color red = {255, 0, 0, 255};
  inline static const SDL_Color green = {0, 255, 0, 255};
  inline static const SDL_Color blue = {0, 0, 255, 255};
  inline static const SDL_Color yellow = {255, 255, 0, 255};
  inline static const SDL_Color magenta = {255, 0, 255, 255};
  inline static const SDL_Color cyan = {0, 255, 255, 255};
  inline static const SDL_Color orange = {255, 165, 0, 255};
  inline static const SDL_Color purple = {128, 0, 128, 255};
  inline static const SDL_Color white = {255, 255, 255, 255};
  inline static const SDL_Color black = {0, 0, 0, 255};
  inline static const SDL_Color gray = {128, 128, 128, 255};
  inline static const SDL_Color pink = {255, 192, 203, 255};
  inline static const SDL_Color brown = {165, 42, 42, 255};
  inline static const SDL_Color lime = {50, 205, 50, 255};
  inline static const SDL_Color teal = {0, 128, 128, 255};
  inline static const SDL_Color navy = {0, 0, 128, 255};
  inline static const SDL_Color gold = {255, 215, 0, 255};
  inline static const SDL_Color olive = {128, 128, 0, 255};
  inline static const SDL_Color plum = {147, 112, 153, 255};
  inline static const SDL_Color glass = {0, 1, 255, 50};
  static void setRendererColor(SDL_Renderer *render, SDL_Color color);
};
} // namespace Colour
} // namespace Basic
