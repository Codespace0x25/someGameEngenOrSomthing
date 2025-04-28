#pragma once
#include "Items.hpp"

namespace Componets { // <-- matches below
using namespace Engen;

class Player;
class ConsumableItem : public Item {
public:
  ConsumableItem(std::string name, std::string spriteSheet, ItemType_e itemType,
                 int HungerGive, int ThrustGive, int HealthGive,
                 int maxStack = 32);
  ~ConsumableItem() = default;
  virtual void Consume(Player& player);
  void Drop(Player *player) override;
  void Pickup(Player *player) override;

protected:
  int HealthGive_;
  int ThrustGive_;
  int HungerGive_;
};

} // namespace Componets
