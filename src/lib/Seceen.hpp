#pragma once
#include "Lib.hpp"
#include "TopLayer.hpp"
#include <sstream>
#include <vector>

namespace Engen {
class Seceen {
public:
  Seceen(TopLayer& toplayer,std::string name);
  virtual ~Seceen();
  virtual void Ready();
  virtual void Start();

protected:
  std::string Name;
  pthread_t prosses;
  TopLayer& engenHook;
};
} // namespace Engen
