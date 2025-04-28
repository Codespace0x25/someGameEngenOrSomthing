#include "Lib.hpp"
#include "camra.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_timer.h>
#include <cstddef>
#include <cstdint>
#include <mutex>
#include <pthread.h>

namespace Engen {
class TimeKeeper {
public:
  static TimeKeeper &GetInstance() {
    static TimeKeeper instance;
    return instance;
  }

  // Start the timekeeping thread

  // Method to stop the time thread
  void Stop() {
    isRunning = false;
    pthread_join(timeThread, NULL); // Join the thread
  }

  uint64_t GetTime() {
    std::lock_guard<std::mutex> lock(timeMutex);
    return time;
  }
  void init() {
    pthread_create(&timeThread, NULL, timeKeeper,
                   NULL); // Start the timekeeping thread
  }
  void *timeKeeper(void *t) {
    while (isRunning) {
      {
        std::lock_guard<std::mutex> lock(timeMutex);
        time++;
      }
      SDL_Delay(1000); // Sleep for 1 second
    }
    return NULL;
  }
  ~TimeKeeper() {
    Stop(); // Clean up thread before destruction
  }

private:
  pthread_t timeThread;
  bool isRunning = true;
  uint64_t time = 0;
  std::mutex timeMutex; // Mutex to protect access to the time variable

  TimeKeeper() {}
};

} // namespace Engen
