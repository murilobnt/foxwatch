#ifndef FOXWATCH_BASE_UI_OBJECT_H_
#define FOXWATCH_BASE_UI_OBJECT_H_

#include <functional>

#include "config.h"
#include "foxwatch/screens/scindex.h"

namespace foxwatch {

class BaseUIObject {
public:
  virtual ~BaseUIObject() = default;
  virtual void composeScreen(lv_obj_t *scr) = 0;

  void setLoad(std::function<void(SCIndex)> load);
  void load(SCIndex index);
  virtual void loop();
private:
  std::function<void(SCIndex)> load_ptr;
};

}

#endif
