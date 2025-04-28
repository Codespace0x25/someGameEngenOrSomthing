#include "../lib/Lib.hpp"
#include "../lib/std/random.hpp"
#include "Envimerment.hpp"
#include "player.hpp"
#include <algorithm> // for std::shuffle
#include <cmath>
#include <iostream>
#include <random> // for std::mt19937
#include <unordered_map>
#include <vector>

namespace Componets {
using namespace Engen;

int HASH[512];

bool hasInit = false;
void initHash() {
  if (hasInit) {
    return;
  } else {
    hasInit = true;
  }

  std::vector<int> p(256);
  for (int i = 0; i < 256; ++i) {
    p[i] = i;
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::shuffle(p.begin(), p.end(), gen);

  // Copy the permutation twice
  for (int i = 0; i < 256; ++i) {
    HASH[i] = p[i];
    HASH[256 + i] = p[i];
  }
}

int noise2(int x, int y) {
  int yindex = (y * Engen_std::randIntRange(1, 255)) % 256;
  if (yindex < 0)
    yindex += 256;
  int xindex = (HASH[yindex] + x) % 256;
  if (xindex < 0) {
    xindex += 256;
  }
  const int result = HASH[xindex];
  return result;
}
double lin_inter(double x, double y, double s) { return x + s * (y - x); }

double smooth_inter(double x, double y, double s) {
  return lin_inter(x, y, s * s * (3 - 2 * s));
}
double noise2d(double x, double y) {
  const int x_int = floor(x);
  const int y_int = floor(y);
  const double x_frac = x - x_int;
  const double y_frac = y - y_int;
  const int s = noise2(x_int, y_int);
  const int t = noise2(x_int + 1, y_int);
  const int u = noise2(x_int, y_int + 1);
  const int v = noise2(x_int + 1, y_int + 1);
  const double low = smooth_inter(s, t, x_frac);
  const double high = smooth_inter(u, v, x_frac);
  const double resolt = smooth_inter(low, high, x_frac);
  return resolt;
}

int perlin2d(double x, double y, double freq, int depth) {
  double xa = x * freq;
  double ya = y * freq;
  double amp = 1.0;
  double fin = 0;
  double dev = 0.0;
  for (int i = 0; i < depth; i++) {
    dev += 256 * amp;
    fin += noise2d(xa, ya) * amp;
    amp /= 2;
    xa *= 2;
    xa *= 2;
  }
  return (int)fin / dev;
}
} // namespace Componets
