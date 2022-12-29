#include "foxwatch/requester.h"

namespace foxwatch {

Requester::Requester() { 
  request.setDebug(false);
  request.onReadyStateChange(std::bind(&Requester::callback, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3));
}

void Requester::open(bool * const requestOpenResult, const char *url, const char *method) {
  if (request.readyState() == readyStateUnsent || request.readyState() == readyStateDone)
    *requestOpenResult = request.open(method, url);
}

bool Requester::get(const char *url) {
  static bool requestOpenResult;

  open(&requestOpenResult, url, "GET");
  if (requestOpenResult) {
    request.send();
    return true;
  } else {
    /* Serial.println("Bad request."); */
    return false;
  }
}

bool Requester::post(const char *url, const String &body) {
  static bool requestOpenResult;

  open(&requestOpenResult, url, "POST");
  if (requestOpenResult) {
    request.setReqHeader("Content-Type", "application/json");
    request.send(body);
    return true;
  } else {
    /* Serial.println("Bad request."); */
    return false;
  }
}

void Requester::setHeader(const char *header, const char *value) {
  request.setReqHeader(header, value);
}

void Requester::callback(void *optParm, AsyncHTTPSRequest *request, int readyState) {
  if (readyState == readyStateDone)
  {
    Serial.print("Response Text = ");
    Serial.println(request->responseHTTPString());

    if (request->responseHTTPcode() == 200)
    {
      Serial.println(F("\n**************************************"));
      Serial.println(request->responseText());
      Serial.println(F("**************************************"));
    }
  } 
}

}
