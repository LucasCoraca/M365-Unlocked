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
#include "Light.h"
#include "Brake.h"
#include "BrakeL.h"
#include "ActionButton.h"
#include "Arduino.h"


BrakeL::BrakeL(int lPin, ActionButton *ab, Brake *b) : Light(lPin, ab){
  brake = b;
  elapsedTime_micros = 0;
  timer_micros = micros();
  bState = false;
  previousState = LOW;
}

void BrakeL::calculateElapsedTime(){
  elapsedTime_micros = micros() - timer_micros;
}

void BrakeL::loop(){
  if(actionButton->isSinglePressed()){
    toggle();
  }
  if(brake->getBrakePercentage()){
    calculateElapsedTime();
    if(bState == false){
      bState = true;
      previousState = digitalRead(pin);
    }
    if(elapsedTime_micros>INTERVAL){
      toggle();
      timer_micros = micros();
    }
  } else {
    if(bState == true){
      bState = false;
      if(previousState != digitalRead(pin)){
        toggle();
      }
    }
  }
}
