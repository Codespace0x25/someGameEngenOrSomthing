#include "../ComponetLib/ConsumableItems.hpp"

namespace GameObject {
class Player;

class Apple : public Componets::ConsumableItem {
public:
  Apple();
  
  void handleEvent(const SDL_Event &e) override;
  void render(SDL_Renderer *renderer) override;
  void Ready() override;
  void Update(Uint32 delta) override;

  void renderInInventory(SDL_Renderer *renderer, int x_, int y_)override;
  void Drop(Player *player) override;
  void Pickup(Player *player) override;
};
} // namespace GameObject
