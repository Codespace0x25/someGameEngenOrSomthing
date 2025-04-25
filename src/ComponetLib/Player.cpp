#include "./player.hpp"
#include "../lib/Lib.hpp"
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <ostream>

namespace Componets {
using namespace Engen;
Player::Player(int x, int y, int w, int h, std::string spritesheet)
    : GameObject("player", x, y, w, h), PlayerControlerDefalt(),
      spritesheet_(spritesheet) {
  Camera::GetInstance().Set(x, y);
}

Player::~Player() {}
void Player::Update(Uint32 delta) {
  // Center camera on player
  Camera::GetInstance().Set(
      x - ViewPort::GetInstance().getScreenW() / 2 + w / 2,
      y - ViewPort::GetInstance().getScreenH() / 2 + h / 2);

auto cam = Camera::GetInstance();
 std::cout << "Camera: " << cam.getX() << "," << cam.getY() << std::endl;
 std::cout << "Player world: " << x << "," << y << std::endl;

}
void Player::Ready() {}
void Player::render(SDL_Renderer *renderer) { drawbody(renderer); }

void Player::drawbody(SDL_Renderer *renderer) {
  SDL_Rect screenRect = ViewPort::GetInstance().WorldToScreen(to_Rect());

  // Only draw at screen position, don't modify player world pos!
  SpriteSheet::render(renderer, screenRect.x, screenRect.y, w, h, spritesheet_,
                      3, 8);
}
void Player::setSpeed(int amount) { speed = amount; }
void Player::forwards() { y -= speed; }
void Player::backwards() { y += speed; }
void Player::left() { x -= speed; }
void Player::right() { x += speed; }
void Player::tp(int mx, int my) { Camera::GetInstance().Set(mx, my); }
int Player::getHeath() { return heath; }
int Player::getMaxHeath() { return maxHeath; }
void Player::setMaxHeath(int amount) { maxHeath = amount; }
void Player::setHeath(int amount) { heath = amount; }
void Player::addHeath(int amount) { heath += amount; }
void Player::subHeath(int amount) { heath -= amount; }

} // namespace Componets
