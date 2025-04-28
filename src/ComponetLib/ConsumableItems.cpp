#include "Items.hpp"
#include "ConsumableItems.hpp"

namespace Componets { // <-- matches below
using namespace Engen;
class Player;
  ConsumableItem::ConsumableItem(std::string name, std::string spriteSheet, ItemType_e itemType,
                 int HungerGive, int ThrustGive, int HealthGive,
				 int maxStack): Item(name, spriteSheet, itemType), HungerGive_(HungerGive),
						ThrustGive_(ThrustGive),HealthGive_(HealthGive){}
  void ConsumableItem::Consume(Player& player){}


} // namespace Componets
