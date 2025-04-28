#include "../ComponetLib/ConsumableItems.hpp"
#include "Apple.hpp"

namespace GameObject {
  Apple::Apple():Componets::ConsumableItem("apple", "assets/spriteSheet.png", Componets::ITEMTYPE_FOOD_DRINK,
					   10,5, 15){}
} // namespace GameObject
