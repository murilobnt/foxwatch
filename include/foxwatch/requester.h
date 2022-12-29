#ifndef FOXWATCH_REQUESTER_H_
#define FOXWATCH_REQUESTER_H_

#include <functional>
#include <AsyncHTTPSRequest_Generic.hpp>

namespace foxwatch {

class Requester {
public:
  Requester();
  bool get(const char *url);
  bool post(const char *url, const String &body);
  void setHeader(const char *header, const char *value);

  virtual void callback(void *optParm, AsyncHTTPSRequest *request, int readyState);

private:
  AsyncHTTPSRequest request;

  void open(bool * const requestOpenResult, const char *url, const char *method);
};

}

#endif
