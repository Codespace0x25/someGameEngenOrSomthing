#pragma  once
#include "../lib/GameObject.hpp"
#include "../lib/Colour.hpp"
#include "PlayerControler.hpp"
#include <string>
#include <vector>

namespace Componets {
using namespace Engen;

  typedef enum {
    Move_Left,
    Move_Forward,
    Move_Right,
    Move_Back
  }MOVE_e;
  
class Player : public GameObject, public PlayerControlerDefalt {
public:
  Player(int x, int y, int w, int h,std::string spritesheet);
  ~Player();

  void drawbody(SDL_Renderer *render);

  void Update(Uint32 delta) override;
  void Ready() override;
  void render(SDL_Renderer *renderer) override;
  void forwards() override;
  void backwards() override;
  void left() override;
  void right() override;
  void tp(int mx,int my);
  // heath
  int getHeath();
  int getMaxHeath();
  void setMaxHeath(int amount);
  void setHeath(int amount);
  void addHeath(int amount);
  void subHeath(int amount);

  // hunger

  int getHunger();
  int getMaxHunger();
  void setMaxHunger(int amount);
  void setHunger(int amount);
  void addHunger(int amount);
  void subHunger(int amount);
  // thurst
  int getTherst();
  int getMaxTherst();
  void setMaxTherst(int amount);
  void setTherst(int amount);
  void addTherst(int amount);
  void subTherst(int amount);
  void setSpeed(int amount);
private:
  MOVE_e direshion;
  std::string spritesheet_;
  std::string username;
  int speed = 1;
  int maxHeath = 20;
  int heath = maxHeath;
  int maxHunger = 20;
  int hunger = maxHunger;
  int maxTherst = 20;
  int therst = maxTherst;

};


}
