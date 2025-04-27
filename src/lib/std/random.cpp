#include <SDL2/SDL.h>
#include "random.hpp"
#include <cstdlib>
#include <ctime>

namespace Engen_std {

int randIntRange(int min, int max) {
  srand(rand()*SDL_GetTicks());
  if (min > max)
    std::swap(min, max);
  return min + rand() % (max - min + 1);
}

} // namespace Engen_std
