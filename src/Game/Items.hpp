#pragma once
#include <string>
#include "../lib/Lib.hpp"

namespace Game {
using namespace Engen;
  typedef enum {
    ITEMTYPE_NATRAL,
    ITEMTYPE_TOOL,
    ITEMTYPE_FOOD_DRINK,
    ITEMTYPE_EXTEINSHION,
  }ItemType_e;


class Item:public RenderAble{
public:
  Item(std::string name,int maxStack=32);
  ~Item();
  void render(SDL_Renderer *renderer)override;

  void toggleDrop();

protected:
  std::string name;
  int MaxStack;
  bool CanBrake;
  
};
} // namespace Game
