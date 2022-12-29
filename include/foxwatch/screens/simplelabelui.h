#ifndef FOXWATCH_SIMPLELABELUI_H_
#define FOXWATCH_SIMPLELABELUI_H_

#include "foxwatch/ui/baseuiobject.h"

namespace foxwatch {

class SimpleLabelUI : public BaseUIObject {
public:
  SimpleLabelUI();
  void composeScreen(lv_obj_t *scr);
};

}

#endif
