/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */


#include "mbed.h"
#include "platform/mbed_thread.h"
#include "HCSR04.h"


// Blinking rate in milliseconds
#define BLINKING_RATE_MS    500
Serial blueth(D1, D0, 115200);
HCSR04 sonar(D8, D9);// sonar de devant
HCSR04 sonar1(D10, D11); // sonar gauche
HCSR04 sonar2(D12, D13); // sonar droite 
DigitalOut Moteur1(D6); // moteur à droite
DigitalOut Moteur2(D3); // moteur à gauche
DigitalOut Mot1RotHor(D7);
DigitalOut Mot1RotAntiHor(D5);
DigitalOut Mot2RotHor(D4);
DigitalOut Mot2RotAntiHor(D2);



int main()
{
    
    while(1) {
        blueth.printf("Distance : %.2f cm \n", sonar.getCm()); 
        
        if(sonar.getCm() <= 80.0 and sonar1.getCm() >= 50.0 and sonar2.getCm() >= 50.0){
            Mot1RotHor = 1;
            Mot2RotHor = 0;
        }else if(sonar.getCm() >= 80.0 and sonar1.getCm() <= 50.0 and sonar2.getCm() >= 50.0){
            Mot1RotHor = 1;
            Mot2RotHor = 0;
        }else if(sonar.getCm() >= 80.0 and sonar1.getCm() >= 50.0 and sonar2.getCm() <= 50.0){
            Mot1RotHor = 0;
            Mot2RotHor = 1;
        }else{
            Moteur1 = 1;
            Moteur2 = 1;
            Mot1RotHor = 1;
            Mot2RotHor = 1;
        }
        
    }
}

