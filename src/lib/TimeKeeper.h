#include "Lib.hpp"
#include "camra.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <cstdint>
#include <pthread.h>

namespace Engen {
class TimeKepper {
public:
  static TimeKepper &GetInstance() {
    static TimeKepper instance;
    return instance;
  }

private:
  pthread_t timeThread;
  bool isRuning = 0;
  TimeKepper() {}
  uint64_t time;
    
  void* timeKeepe(void*){
    while () {
      
	}
  }
};
} // namespace Engen
