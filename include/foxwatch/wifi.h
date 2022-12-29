#ifndef FOXWATCH_WIFI_
#define FOXWATCH_WIFI_

#include <WiFi.h>

namespace foxwatch {

namespace wifi {

struct WiFiData {
public:
  const char *SSID;
  bool restricted;
};

WiFiData* scan();
void connect(const char *ssid, const char *password);
bool isConnected();

}

}

#endif
