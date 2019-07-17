/*
GNU GPLv3 license

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 contact:lucascoracasilva@gmail.com
*/
#include "Battery.h"
#include "Throttle.h"
#include "Brake.h"
#include "PowerMode.h"
#include "Coil.h"
#include "Motor.h"
#include "Arduino.h"

Motor::Motor(int aVcc,int aGnd,int bVcc,int bGnd,int cVcc,int cGnd,int sA,int sB
  ,  int sC, Throttle *t, Brake *bK, PowerMode *pM, Battery *bT){

    //set dependencies
    throttle = t;
    brake = bK;
    powerMode = pM;
    battery = bT;

    //Set Coils
    coilA = new Coil(aVcc, aGnd);
    coilB = new Coil(bVcc, bGnd);
    coilC = new Coil(cVcc, cGnd);

    //set Sensors
    sensorA = sA;
    sensorB = sB;
    sensorC = sC;

    //set variables
    timer_micros = micros();
    elapsedTime_micros = 0;
    rpm = 0;
    speed_kmh = 0;
    power = powerMode->getMaxPower();
    targetSpeed_kmh = powerMode->getMaxSpeed();

  }

void Motor::setFase1(){
  coilA->setCoil(VCC);
  coilB->setCoil(GND);
  coilC->setCoil(NOT_CONNECTED);
}

void Motor::setFase2(){
  coilA->setCoil(NOT_CONNECTED);
  coilB->setCoil(GND);
  coilC->setCoil(VCC);
}

void Motor::setFase3(){
  coilA->setCoil(GND);
  coilB->setCoil(NOT_CONNECTED);
  coilC->setCoil(VCC);
}

void Motor::setFase4(){
  coilA->setCoil(GND);
  coilB->setCoil(VCC);
  coilC->setCoil(NOT_CONNECTED);
}

void Motor::setFase5(){
  coilA->setCoil(NOT_CONNECTED);
  coilB->setCoil(VCC);
  coilC->setCoil(GND);
}

void Motor::setFase6(){
  coilA->setCoil(VCC);
  coilB->setCoil(NOT_CONNECTED);
  coilC->setCoil(GND);
}

void Motor::setOff(){
  coilA->setCoil(NOT_CONNECTED);
  coilB->setCoil(NOT_CONNECTED);
  coilC->setCoil(NOT_CONNECTED);
}

void Motor::accelerate(){

}

void Motor::brakeM(){

}

void Motor::updateTargetSpeed(){

}

void Motor::updateTargetPower(){

}

void Motor::calculateSpeed(){

}

int Motor::getSpeed(){
  return speed_kmh;
}

void Motor::loop(){
    elapsedTime_micros = micros() - timer_micros;
    if(elapsedTime_micros>2000){
      timer_micros = micros();
      //fase1
      if((digitalRead(sensorA)==1 && digitalRead(sensorB)==0 && digitalRead(sensorC)==1)){
        setFase1();
      }
      //fase2
      if((digitalRead(sensorA)==0 && digitalRead(sensorB)==0 && digitalRead(sensorC)==1)){
        setFase2();
      }
      //fase3
      if((digitalRead(sensorA)==0 && digitalRead(sensorB)==1 && digitalRead(sensorC)==1)){
        setFase4();
      }
      //fase4
      if((digitalRead(sensorA)==0 && digitalRead(sensorB)==1 && digitalRead(sensorC)==0)){
        setFase4();
      }
      //fase5
      if((digitalRead(sensorA)==1 && digitalRead(sensorB)==1 && digitalRead(sensorC)==0)){
        setFase5();
      }
      //fase6
      if((digitalRead(sensorA)==1 && digitalRead(sensorB)==0 && digitalRead(sensorC)==0)){
        setFase6();
      }
    }

}
