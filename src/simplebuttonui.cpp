#include "foxwatch/screens/simplebuttonui.h"

namespace foxwatch {

SimpleButtonUI::SimpleButtonUI(Requester *requester) : requester(requester) {}

void SimpleButtonUI::composeScreen(lv_obj_t *scr){
  static SimpleButtonUI *instance = this;
  lv_obj_t *label;

  lv_obj_t *btn1 = lv_btn_create(scr, NULL);
  lv_obj_set_event_cb(btn1, 
    [] (lv_obj_t *obj, lv_event_t event) {
     switch(event) {
       case LV_EVENT_CLICKED:
        instance->load(SIMPLELABELUI);
	  /* if(wifi::isConnected()) { */
		/* instance->requester->post("url", "body"); */
		 /* } else { */
	    /* Serial.println("Not connected to WiFi."); */
	  /* } */
	  break;
     }
    }
  );

  lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, 0, 0);

  label = lv_label_create(btn1, NULL);
  lv_label_set_text(label, "Click me");
}

}
