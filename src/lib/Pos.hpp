#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>

namespace Engen {

typedef void *Pointer_t;

class POS {
public:
  POS(int x, int y,int w, int h) : x(x), y(y),w(w), h(h) {}
  virtual int getY() { return y; }
  virtual int getW() { return w; }
  virtual int getH() { return h; }
  virtual int getX() { return x; }
  virtual void setY(int amount) { y = amount; }
  virtual void setX(int amount) { x = amount; }
  virtual void addY(int amount) { y += amount; }
  virtual void addX(int amount) { x += amount; }
  virtual void subY(int amount) { y -= amount; }
  virtual void subX(int amount) { x -= amount; }
  virtual void setW(int amount) { w = amount; }
  virtual void setH(int amount) { h = amount; }
  virtual void addW(int amount) { w += amount; }
  virtual void addH(int amount) { h += amount; }
  virtual void subW(int amount) { w -= amount; }
  virtual void subH(int amount) { h -= amount; }
  virtual SDL_Rect to_Rect() {
    SDL_Rect temp = {x, y, w, h};
    return temp;
  }
  virtual void setFromRect(SDL_Rect rect){
    y = rect.y;
    x = rect.x;
    w = rect.w;
    h = rect.h;
  }
  virtual SDL_Point getCenter(){
    SDL_Point temp = {x+w,y-h};
    return temp;
  }
  virtual bool IsIntersecting(POS &slave) {
    int sx = slave.getX();
    int sy = slave.getY();
    int sw = slave.getW();
    int sh = slave.getH();
    return (x < sx + sw && x + w > sx && y < sy + sh && y + h > sy);
  }
protected:
  int x, y;
  int w, h;
};
} // namespace Basic
