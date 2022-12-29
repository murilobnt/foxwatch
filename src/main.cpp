#include "main.h"

foxwatch::Requester requester;
foxwatch::UI ui;
TTGOClass *ttgo;

void mainLoad(foxwatch::SCIndex index) {
	switch (index) {
		case foxwatch::SIMPLEBUTTONUI:
			ui.load(new foxwatch::SimpleButtonUI(&requester));
			break;
		case foxwatch::SIMPLELABELUI:
			ui.load(new foxwatch::SimpleLabelUI());
			break;
	}
}

void setup() {
  Serial.begin(115200);

  ttgo = TTGOClass::getWatch();
  ttgo->begin();
  ttgo->setBrightness(48);
  ttgo->openBL();
  ttgo->lvgl_begin();

  ui.start(&mainLoad);
  foxwatch::wifi::connect(ssid, password);
  ui.load(new foxwatch::SimpleButtonUI(&requester));
}

void loop() {
  lv_task_handler();
  delay(5);//allow the cpu to switch to other tasks
}
