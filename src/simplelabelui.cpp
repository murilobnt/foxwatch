#include "foxwatch/screens/simplelabelui.h"

namespace foxwatch {

SimpleLabelUI::SimpleLabelUI(){}

void SimpleLabelUI::composeScreen(lv_obj_t *scr) {
  lv_obj_t * label = lv_label_create(scr, NULL);
  lv_label_set_text(label, "It works!");
  lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
}

}
