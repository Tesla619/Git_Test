#include "mbed.h" 

// The sinewave is created on this pin
AnalogOut aout(PA_5);

// main() runs in its own thread in the OS
int main()
{
    const double pi = 3.141592653589793238462;
    const double amplitude = 0.5f;
    const double offset = 32767.5f;//65535/2;
    double rads = 0.0;
    uint16_t sample = 0;
    
    while(1) {
        // sinewave output
        for (int i = 0; i < 360; i++) {
            rads = (pi * i) / 180.0f;
            sample = (uint16_t)(amplitude * (offset * (cos(rads + pi))) + offset);
            aout.write_u16(sample);
        }
    }
}