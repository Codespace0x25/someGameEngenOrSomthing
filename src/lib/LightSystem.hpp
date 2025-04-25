#pragma once
#include "Lib.hpp"
#include "TopLayer.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_stdinc.h>
#include <vector>

namespace Engen {

struct PointLight {
  float x, y;
  float radius;
  SDL_Color color;
};

class LightingSystem {
public:
  static void Init(SDL_Renderer *renderer, int width, int height);
  static void Shutdown();

  static void AddLight(float x, float y,
		       float radius, SDL_Color color);
  static void ClearLights();

  static void RenderLights();
  static SDL_Texture *GetLightTexture();

private:
  static inline std::vector<PointLight> lights;
  static inline SDL_Renderer *renderer = nullptr;
  static inline SDL_Texture *lightTexture = nullptr;
  static inline int screenWidth = 0;
  static inline int screenHeight = 0;

  static void DrawLight(const PointLight &light);
};
} // namespace Engen
