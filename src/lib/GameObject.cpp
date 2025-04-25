#include "GameObject.hpp"

namespace Engen {

GameObject::GameObject(std::string name,int x, int y, int w, int h)
  : POS(x, y, w, h), RenderAble(), Updatable(),nam(name) {}

  std::string GameObject::getName() {
  return nam;
}
} // namespace Basic
