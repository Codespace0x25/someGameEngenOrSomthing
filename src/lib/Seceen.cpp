#include "Seceen.hpp"
#include "Lib.hpp"
#include "TopLayer.hpp"
#include <charconv>
#include <sstream>
#include <vector>

namespace Engen {
  Seceen::Seceen(TopLayer& toplayer,std::string name):
    engenHook(toplayer),Name(name){}
  Seceen::~Seceen(){}
  void Seceen::Ready(){
    std::stringstream temp("");
    temp << engenHook.getTitle() << Name;
    engenHook.setTitle(temp.str());
  }
  void Seceen::Start(){
  }

} // namespace Engen
