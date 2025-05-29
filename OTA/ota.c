#include <AsyncElegantOTA.h>
#include "globals.h"

void setupOTA() {
  webServer.begin();
  AsyncElegantOTA.begin(&webServer);
}
