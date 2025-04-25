#include "LightSystem.hpp"

namespace Engen {
void LightingSystem::Init(SDL_Renderer *r, int width, int height) {
  renderer = r;
  screenWidth = width;
  screenHeight = height;
  lightTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
                                   SDL_TEXTUREACCESS_TARGET, width, height);
  SDL_SetTextureBlendMode(lightTexture, SDL_BLENDMODE_ADD);
}

void LightingSystem::Shutdown() {
  if (lightTexture) {
    SDL_DestroyTexture(lightTexture);
    lightTexture = nullptr;
  }
  lights.clear();
}

void LightingSystem::AddLight(float x, float y, float radius, SDL_Color color) {
  lights.push_back({x, y, radius, color});
}

void LightingSystem::ClearLights() { lights.clear(); }

void LightingSystem::RenderLights() {
  SDL_SetRenderTarget(renderer, lightTexture);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  for (const auto &light : lights) {
    DrawLight(light);
  }

  SDL_SetRenderTarget(renderer, nullptr);
}

SDL_Texture *LightingSystem::GetLightTexture() { return lightTexture; }

void LightingSystem::DrawLight(const PointLight &light) {
  // Simple radial gradient: draw concentric transparent circles
  int steps = 32;
  for (int i = 0; i < steps; ++i) {
    float t = static_cast<float>(i) / steps;
    float r = light.radius * (1.0f - t);
    Uint8 alpha = static_cast<Uint8>((1.0f - t) * light.color.a);

    SDL_SetRenderDrawColor(renderer, light.color.r, light.color.g,
                           light.color.b, alpha);
    for (int angle = 0; angle < 360; angle += 10) {
      float rad = angle * (M_PI / 180.0f);
      int px = static_cast<int>(light.x + cosf(rad) * r);
      int py = static_cast<int>(light.y + sinf(rad) * r);
      SDL_RenderDrawPoint(renderer, px, py);
    }
  }
}
} // namespace Engen
