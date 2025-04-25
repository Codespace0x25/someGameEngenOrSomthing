#include "TopLayer.hpp"
#include "Colour.hpp"
#include "Lib.hpp"
#include "LightSystem.hpp"
#include "Renderable.hpp"
#include "Spritesheets.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <cstdio>

namespace Engen {
std::stringstream TopLayer::ErrorMessage;

TopLayer::TopLayer(std::string name, int *errorReturn, Vec2 size) {
  *errorReturn = 0;
  title = name;
  diminshion = {.W = size.x, .H = size.y};

  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    ErrorMessage << "Error at init in " << __FUNCTION__ << " : "
                 << SDL_GetError() << "\n";
    ++(*errorReturn);
    return;
  }

  sdlData.window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED, size.x, size.y,
                                    SDL_WINDOW_SHOWN);
  if (!sdlData.window) {
    ErrorMessage << "Error at window creation in " << __FUNCTION__ << " : "
                 << SDL_GetError() << "\n";
    ++(*errorReturn);
    return;
  }

  sdlData.render =
      SDL_CreateRenderer(sdlData.window, -1, SDL_RENDERER_ACCELERATED);
  if (!sdlData.render) {
    ErrorMessage << "Error at renderer creation in " << __FUNCTION__ << " : "
                 << SDL_GetError() << "\n";
    ++(*errorReturn);
    return;
  }

  ViewPort::GetInstance().Set(size.x,size.y);
  ViewPort::GetInstance().setRenderer(sdlData.render);
}
TopLayer::~TopLayer() {
  SDL_DestroyRenderer(sdlData.render);
  SDL_DestroyWindow(sdlData.window);
  SDL_Quit();
}
// user fushoins, for the engen hook
void TopLayer::run() {
  while (isRunning) {
    runEvents();
    runUpdaters();
    runRender();
    SDL_Delay(16);
  }
}
void TopLayer::runEvents() {
  while (SDL_PollEvent(&sdlData.event)) {
    if (sdlData.event.type == SDL_QUIT)
      isRunning = false;

    for (auto handler : ComponetStor.eventHandlers) {
      handler->handleEvent(sdlData.event);
    }
  }
}
void TopLayer::runRender() {
  Colour::Colour::setRendererColor(sdlData.render, backGroundColour);
  SDL_RenderClear(sdlData.render);
  for (auto handler : ComponetStor.renderAbles) {
    handler->render(sdlData.render);
  }

  SDL_RenderPresent(sdlData.render); // <<=== FIX
}
void TopLayer::runUpdaters() {
  for (auto handler : ComponetStor.updatAbles) {
    handler->Update(0);
  }
}

// adders

void TopLayer::addEventHandlers(EventHandler *data) {
  ComponetStor.eventHandlers.push_back(data);
}
void TopLayer::addRenderAble(RenderAble *data) {
  ComponetStor.renderAbles.push_back(data);
}
void TopLayer::addUpdatable(Updatable *data) {
  data->Ready();
  ComponetStor.updatAbles.push_back(data);
}

void TopLayer::addGameObject(GameObject *data) {
  // if true then it will be added to
  // the event handlers as well.
  addRenderAble(data);
  addUpdatable(data);
}
// seters

void TopLayer::setTitle(std::string title) {
  SDL_SetWindowTitle(sdlData.window, title.c_str());
  this->title = title;
}
void TopLayer::setBackGroundColor(SDL_Color color) {
  Colour::Colour::setRendererColor(sdlData.render, color);
}

// geters
std::string TopLayer::GetError() { return ErrorMessage.str(); }

std::string TopLayer::getTitle() { return title; }

SDL_Renderer *TopLayer::GetRenderer() { return sdlData.render; }
int TopLayer::Width() { return diminshion.W; }
int TopLayer::Height() { return diminshion.H; }

} // namespace Engen
