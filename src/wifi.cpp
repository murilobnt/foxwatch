#include "foxwatch/wifi.h"

namespace foxwatch {

namespace wifi {

WiFiData *scan() {
	int16_t n = WiFi.scanNetworks();
	if(!n)
		return nullptr;

	WiFiData *dat = (WiFiData*)malloc(n * sizeof(struct WiFiData));
	for(int16_t i = 0; i < n; ++i)
		dat[i] = { WiFi.SSID(i).c_str(), (WiFi.encryptionType(i) != WIFI_AUTH_OPEN) };

	return dat; // CAUTION: REQUIRES FREE()
}

void connect(const char *ssid, const char *password) {
  Serial.println("Connecting");
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

bool isConnected() {
  return (WiFi.status() == WL_CONNECTED);
}

}

}
