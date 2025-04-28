#pragma once
#include "../lib/Lib.hpp"
#include <string>

namespace Componets {  // <-- matches below
using namespace Engen;

class Player;

typedef enum {
  ITEMTYPE_NATRAL,
  ITEMTYPE_TOOL,
  ITEMTYPE_FOOD_DRINK,
  ITEMTYPE_EXTEINSHION,
} ItemType_e;

class Item : public RenderAble,
             public EventHandler,
             public Updatable,
             public POS {
public:
  Item(std::string name, std::string spriteSheet, ItemType_e itemType,
      int maxStack = 32);
  ~Item();


  virtual void renderInInventory(SDL_Renderer *renderer, int x_, int y_);
  virtual void Drop(Player* player);
  virtual void Pickup(Player* player);
  
  int Stack_;
protected:
  ItemType_e itemType_;
  std::string spriteSheet_;
  std::string name_;
  int MaxStack_;
};
} // namespace Componets
