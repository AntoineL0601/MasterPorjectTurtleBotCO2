#ifndef HCSR04_H
#define HCSR04_H

#include "mbed.h"



/** Sonar HC-SR04 example.
 * @code
 * #include "mbed.h"
 * #include "HCSR04.h"
 *
 * DigitalOut myled(LED1);
 * Serial pc(USBTX,USBRX);     
 *
 * HCSR04 sonar(PTB0, PTD3);
 *
 * int main() {
 *     while(1) {
 *         printf("Distancia detectada pelo sensor Frente %.2f cm \n", sonar.echo()); 
 *         wait_ms(1000);
 *     }
 * }
 *
 * @endcode
*/

class HCSR04 {    
    public:    
        /** Constructor, create HC_SR04 instance 
          *
          * @param trigger TRIG pin
          * @param echo ECHO pin
          */
        HCSR04(PinName trigger, PinName echo);
 
        /** Faz uma leitura do sonar
          * 
          * @returns Tempo do pulso echo em microsegundos*/
        float readEcho(void);
        
        /** Mede a distância em centímetros "cm" 
          *
          *@returns Distância em cm
          */
        float getCm(void);
        
        /** Mede a distência em polegadas "in" 
          *
          *@returns Distência em in*/
        float getIn(void);
        
    private:
        float tdist;        //Leitura do tempo transcorrido
        float distcm;       //
        float distin;   
        
        DigitalOut _t;      //Configuração do pino de Trigger  
        DigitalIn _e;       //Configuração do pino de Echo
        Timer _tempo;
        
};

#endif