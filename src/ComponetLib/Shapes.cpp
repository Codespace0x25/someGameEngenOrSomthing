#include "Shapes.hpp"
#include "../lib/Colour.hpp"
#include "../lib/Lib.hpp"
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <cmath>
#include <cstdio>

namespace Componets {
using namespace Engen;
void Shape::filledCircle(SDL_Renderer *renderer, int cx, int cy, int radius,
                         SDL_Color color) {
  SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
  Colour::Colour::setRendererColor(renderer, color);
  for (int w = 0; w < radius * 2; w++) {
    for (int h = 0; h < radius * 2; h++) {
      int dx = radius - w;
      int dy = radius - h;
      if ((dx * dx + dy * dy) <= (radius * radius)) {
        SDL_RenderDrawPoint(renderer, cx + dx, cy + dy);
      }
    }
  }
}

void Shape::filledCircalPresent(SDL_Renderer *renderer, int cx, int cy,
                                int radius, double percentage, double maxValue,
                                SDL_Color color) {
  if (percentage <= 0.0 || maxValue <= 0.0 || percentage > maxValue)
    return;

  // Set render color
  Colour::Colour::setRendererColor(renderer, color);

  // Compute how much of the circle to draw (as angle)
  double angleMax = (percentage / maxValue) * 2.0 * M_PI;
  const int segments = 100; // More = smoother
  double step = angleMax / segments;

  for (int i = 0; i < segments; ++i) {
    double angle1 = i * step;
    double angle2 = (i + 1) * step;

    // Triangle points: center, point on edge1, point on edge2
    int x1 = cx + (int)(radius * cos(angle1));
    int y1 = cy + (int)(radius * sin(angle1));
    int x2 = cx + (int)(radius * cos(angle2));
    int y2 = cy + (int)(radius * sin(angle2));

    // Draw filled triangle manually with lines
    SDL_RenderDrawLine(renderer, cx, cy, x1, y1);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    SDL_RenderDrawLine(renderer, x2, y2, cx, cy);
  }
}

bool Shape::isIntersectingSurCircle(Engen::POS Object, int cx, int cy, int radeos)
{
    int objectCx = Object.getX() + Object.getW() / 2;
    int objectCy = Object.getY() - Object.getH() / 2;

    int dx = objectCx - cx;
    int dy = objectCy - cy;

    int distanceSquared = dx * dx + dy * dy;
    int radiusSquared = radeos * radeos;

    return distanceSquared <= radiusSquared;
}
} // namespace Componets
