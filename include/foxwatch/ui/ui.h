#ifndef FOXWATCH_UI_H_
#define FOXWATCH_UI_H_

#include <functional>

#include "foxwatch/ui/baseuiobject.h"
#include "foxwatch/screens/scindex.h"

namespace foxwatch {

class UI {
public:
  UI();
  ~UI();
  void start(std::function<void(SCIndex)> loader);
  void load(BaseUIObject *baseUI);

  void loop();
  
private:
  BaseUIObject *baseUIRef;
  lv_obj_t *scr;
  std::function<void(SCIndex)> loader;
};

}

#endif
