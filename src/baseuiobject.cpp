#include "foxwatch/ui/baseuiobject.h"

namespace foxwatch {

void BaseUIObject::setLoad(std::function<void (SCIndex)> load) {
  this->load_ptr = load;
}

void BaseUIObject::load(SCIndex index) {
  load_ptr(index);
}

void BaseUIObject::loop() {}

}
