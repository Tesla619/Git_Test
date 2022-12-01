#include "mbed.h"
#include "math.h"
#define N 1000
#define PI 3.142

AnalogOut aout(A5);

int n;
float sinW[N];

// main() runs in its own thread in the OS
int main()
{
    float freq = 1.0;
    float amp  = 1.0;
    float T = 1.0/freq;
    float ts = T/N;

    for (n=0; n<N; n++) {
	    sinW[n]=sin(0.303*amp*2*PI*freq*(float)n*ts);            
    }  

    while (true) 
    {
        for (n=0; n<N; n++) {
            aout.write(0.5 + sinW[n]); //0.5 is dc offset the 1.6V offset in the graph on the whiteboard
            wait_us((int)ts*1000000);
        }         
    }
}

