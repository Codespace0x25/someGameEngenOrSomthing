#pragma once
#include "Pos.hpp"
#include "Renderable.hpp"
#include "Updater.hpp"
#include <string>

namespace Engen {
class GameObject : public POS, public RenderAble, public Updatable {
public:
  GameObject(std::string name,int x, int y, int w, int h);
  std::string getName();
private:
  std::string nam;
};
} // namespace Basic
