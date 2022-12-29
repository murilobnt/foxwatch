#include "foxwatch/ui/ui.h"

namespace foxwatch {

UI::UI() {}

void UI::start(std::function<void(SCIndex)> loader) {
  scr = lv_obj_create(NULL, NULL);
  lv_scr_load(scr);
  this->loader = loader;
}

UI::~UI() {
  if (baseUIRef != nullptr)
    delete baseUIRef;
}

void UI::loop(){
  this->baseUIRef->loop();
}

void UI::load(BaseUIObject *baseUI) {
  if(baseUIRef != nullptr)
    delete baseUIRef;

  baseUI->setLoad(this->loader);

  lv_obj_clean(scr);
  baseUIRef = baseUI;
  baseUI->composeScreen(scr);
}

}
