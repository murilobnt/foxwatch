#ifndef FOXWATCH_SIMPLEBUTTONUI_H_
#define FOXWATCH_SIMPLEBUTTONUI_H_

#include "foxwatch/ui/baseuiobject.h"
#include "foxwatch/requester.h"
#include "foxwatch/wifi.h"

namespace foxwatch {

class SimpleButtonUI : public BaseUIObject {
public:
  explicit SimpleButtonUI(Requester *requester);
  void composeScreen(lv_obj_t *scr);

private:
  Requester *requester;
};

}

#endif
