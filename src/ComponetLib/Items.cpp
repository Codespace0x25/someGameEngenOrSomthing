#include "Items.hpp"
#include "../lib/Lib.hpp"
#include "player.hpp"
#include <string>

namespace Componets {
using namespace Engen;

Item::Item(std::string name, std::string spriteSheet, ItemType_e itemType,
           int maxStack)
    : RenderAble(), EventHandler(), Updatable(), POS(0, 0, 0, 0), name_(name),
      spriteSheet_(spriteSheet), itemType_(itemType), MaxStack_(maxStack) {}

Item::~Item() = default;

void Item::handleEvent(const SDL_Event &e) {}
void Item::render(SDL_Renderer *renderer) {}
void Item::Ready() {}
void Item::Update(Uint32 delta) {}
void Item::renderInInventory(SDL_Renderer *renderer, int x_, int y_) {}
void Item::Drop(Player* player) {}
void Item::Pickup(Player* player) {}

} // namespace Componets
