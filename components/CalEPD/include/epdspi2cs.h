/* Implement IoInterface for 4 wire SPI communication with 2 CS pins */
#include "driver/spi_master.h"
#include "driver/gpio.h"
#include "iointerface.h"

#ifndef epdspi2cs_h
#define epdspi2cs_h

class EpdSpi2Cs : IoInterface
{
  public:
    spi_device_handle_t spi;

    void cmd(const uint8_t cmd) override;
    void data(uint8_t data) override;
    // No data is used here (No DC pin)
    void data(const uint8_t *data, int len) override; 
    void reset(uint8_t millis) override;
    void init(uint8_t frequency, bool debug) override;

    
    void csStateLow();
    void csStateHigh();
    void csStateToogle();
    void cs2StateLow();
    void cs2StateHigh();
    void cs2StateToogle();
    // Accelerometer BMA250E uses CS2
    void cmdAccel(const uint8_t *data, int len);


  private:
    bool debug_enabled = true;
};
#endif
// Note: using override compiler will issue an error for "changing the type"
//       in case the type is changed.