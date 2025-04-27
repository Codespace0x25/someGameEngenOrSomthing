#include "./player.hpp"

#include "../lib/Lib.hpp"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_rect.h>
#include <iostream>
#include <ostream>

namespace Componets {
using namespace Engen;

Player::Player(int x, int y, int w, int h, std::string spritesheet)
    : GameObject("player", x, y, w, h), PlayerControlerDefalt(),
      spritesheet_(spritesheet) {
  Camera::GetInstance().Set(x, y);
  inventoryData.maxItem=4;
}

Player::~Player() {}
void Player::Update(Uint32 delta) {
  // Center camera on player
  Camera::GetInstance().Set(
      x - ViewPort::GetInstance().getScreenW() / 2 + w / 2,
      y - ViewPort::GetInstance().getScreenH() / 2 + h / 2);

  // auto cam = Camera::GetInstance();
  // std::cout << "Camera: " << cam.getX() << "," << cam.getY() << std::endl;
  // std::cout << "Player world: " << x << "," << y << std::endl;
}
void Player::Ready() {}
void Player::render(SDL_Renderer *renderer) { drawbody(renderer); }

void Player::drawbody(SDL_Renderer *renderer) {
  SDL_Rect screenRect = ViewPort::GetInstance().WorldToScreen(to_Rect());

  SpriteSheet::render(renderer, screenRect.x - 2, screenRect.y + 25, w, h,
                      spritesheet_, 3, 8,16); // body

  switch (direshion) {

  case Move_Left:
    SpriteSheet::render(renderer, screenRect.x + 35, screenRect.y + 5, w / 2,
                        h / 2, spritesheet_, 1, 7,16); // head
    break;

  case Move_Right:
    SpriteSheet::render(renderer, screenRect.x + 105, screenRect.y + 5, -w / 2,
                        h / 2, spritesheet_, 1, 7,16); // head
    break;

  case Move_Forward:
    SpriteSheet::render(renderer, screenRect.x + 33, screenRect.y + 10, w / 2,
                        h / 2, spritesheet_, 3, 7); // head
    break;
  case Move_Back:
    SpriteSheet::render(renderer, screenRect.x + 33, screenRect.y + 15, w / 2,
                        h / 2, spritesheet_, 2, 7,16); // head
    break;
  }
}
void Player::setSpeed(int amount) { speed = amount; }
void Player::forwards() {
  y -= speed;
  direshion = Move_Forward;
}
void Player::backwards() {
  y += speed;
  direshion = Move_Back;
}
void Player::left() {
  x -= speed;
  direshion = Move_Left;
}
void Player::right() {
  x += speed;
  direshion = Move_Right;
}
void Player::tp(int mx, int my) { Camera::GetInstance().Set(mx, my); }
// heath
int Player::getHeath() { return heath; }
int Player::getMaxHeath() { return maxHeath; }
void Player::setMaxHeath(int amount) { maxHeath = amount; }
void Player::setHeath(int amount) { heath = amount; }
void Player::addHeath(int amount) { heath += amount; }
void Player::subHeath(int amount) { heath -= amount; }
// hunger

int Player::getHunger() { return hunger; }
int Player::getMaxHunger() { return maxHunger; }
void Player::setMaxHunger(int amount) { maxHunger = amount; }
void Player::setHunger(int amount) { hunger = amount; }
void Player::addHunger(int amount) { hunger += amount; }
void Player::subHunger(int amount) { hunger -= amount; }
// therst

int Player::getTherst() { return therst; }
int Player::getMaxTherst() { return maxTherst; }
void Player::setMaxTherst(int amount) { maxHunger = amount; }
void Player::setTherst(int amount) { therst = amount; }
void Player::addTherst(int amount) { therst += amount; }
void Player::subTherst(int amount) { therst -= amount; }

} // namespace Componets
