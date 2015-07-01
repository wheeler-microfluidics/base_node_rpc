#ifndef ___BASE_NODE_EEPROM__H___
#define ___BASE_NODE_EEPROM__H___


#include "BaseBuffer.h"
#include <pb_eeprom.h>


class BaseNodeEeprom : public BufferIFace {
public:
  void update_eeprom_block(uint16_t address, UInt8Array data) {
    cli();
    eeprom_update_block((void*)data.data, (void*)address, data.length);
    sei();
  }

  UInt8Array read_eeprom_block(uint16_t address, uint16_t n) {
    UInt8Array output = get_buffer();
    eeprom_read_block((void*)&output.data[0], (void*)address, n);
    output.length = n;
    return output;
  }
};


#endif  // #ifndef ___BASE_NODE_EEPROM__H___
