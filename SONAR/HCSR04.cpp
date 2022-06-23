#include "HCSR04.h"
#include "mbed.h"


HCSR04::HCSR04(PinName trigger, PinName echo) : _t(trigger), _e(echo) {
    wait(0.1);
    }

float HCSR04::getCm(void){
    distcm = readEcho()/58;
    return distcm;
    }

float HCSR04::getIn(void){
    distin = readEcho()/148;
    return distin;
    }

float HCSR04::readEcho(void){     
    _t=1;                       //Inicio do trigger
    wait_us(10);                //10us de pulso
    _t=0;                       //Fim do trigger
    while(!_e);
    _tempo.start();
    while(_e);
    tdist = _tempo.read_us();   //Leitura do tempo transcorrido 
    _tempo.stop();              //Paro o temporizador
    _tempo.reset();             //Reset para o próximo ciclo
    return tdist;
}