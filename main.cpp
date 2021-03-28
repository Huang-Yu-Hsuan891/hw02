#include "mbed.h"
#include "uLCD_4DGL.h"
uLCD_4DGL uLCD(D1, D0, D2);
DigitalIn up(D3);    // up
DigitalIn down(D4);    // down
DigitalIn sel(D5);    // select
AnalogOut  aout(D7);
AnalogIn Ain(A0);
float i;
int j;
int sample = 128;
float ADCdata[128];

void print(int state);

int main()
{
    int Fre;  // frequency
    Fre = 1;
    int state = 0;
    int start = 0;
    print(0);
    while (1) {
        if (up) {
            if (state == 1) state = 1;
            else state++;
            start = start;
            print(state);
        }
        else if (down) {
            if(state == 0) state = 0;
            else state--;
            start = start;
            print(state);
        }
        else if (sel) {
            start++;
            state = state;
        } else {
            start = start;
            state = state;
        }

        if (start) {
            if (state == 0) Fre =2;
            else if (state == 1) Fre = 5;
            else Fre = 2;
        }
        while (Fre != 1) {
        for (i = 0.0, j = 0;Fre !=1 && j < 128 && i < 1.0/ Fre; j += 1, i +=1.0/128) {
            aout = i * Fre;
            ThisThread::sleep_for(1000ms/( 128 * Fre ));
            ADCdata[j] = Ain;
            printf("%f\r\n", ADCdata[j]); 
        }
        }               
    } 
}
void print (int state) {
    int fre;
    if (state == 0) fre = 2;
    else if (state == 1) fre = 5;
    else fre = 2;
    uLCD.cls();
    uLCD.background_color(WHITE);
    uLCD.color(BLUE);
    uLCD.text_width(4); //4X size text
    uLCD.text_height(4);
    uLCD.textbackground_color(WHITE);
    uLCD.printf("\n%dHz\n", fre);
}
