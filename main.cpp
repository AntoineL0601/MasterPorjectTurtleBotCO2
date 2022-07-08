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
   

    
    mq.initialize();
    while(1) {
        blueth.printf("\r Distance devant: %.2f cm \n", sonarDevant.getCm()); 
        blueth.printf("\r Distance gauche: %.2f cm \n", sonarGauche.getCm()); 
        blueth.printf("\r Distance droite: %.2f cm \n", sonarDroite.getCm());
        blueth.printf("\r PPM mesure: %f PPM \n", mq.getPPM()); 
        blueth.printf("\r \n");
        if(mq.getPPM()>30){
            ledR = 1;
            ledV = 0;
            Moteur1 = 0;
            Moteur2 = 0;
            Mot1RotHor = 0;
            Mot2RotHor = 0;
        }
        else{
            ledR = 0;
            ledV = 1;
            if(sonarDevant.getCm() <= 80.0 and sonarGauche.getCm() >= 50.0 and sonarDroite.getCm() >= 50.0){
                Mot1RotHor = 1;
                Mot2RotHor = 0;
            }else if(sonarDevant.getCm() >= 80.0 and sonarGauche.getCm() <= 50.0 and sonarDroite.getCm() >= 50.0){
                Mot1RotHor = 1;
                Mot2RotHor = 0;
            }else if(sonarDevant.getCm() >= 80.0 and sonarGauche.getCm() >= 50.0 and sonarDroite.getCm() <= 50.0){
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
}
