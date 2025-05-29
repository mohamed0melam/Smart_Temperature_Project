#include "globals.h"
#include "eeprom_config.h"

void setupEEPROM() {
    EEPROM.begin(512);
}
EEPROM.commit();   // Must commit to save changes
