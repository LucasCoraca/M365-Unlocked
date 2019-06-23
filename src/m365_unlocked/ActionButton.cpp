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

ActionButton v1

for more info refer to:
https://github.com/LucasCoraca/M365-Unlocked/blob/master/doc/classes/ActionButto
n.md
*/

#include "ActionButton.h"
#include "Arduino.h"

ActionButton::ActionButton(int bPin){
  pin = bPin;
  counter = 0;
  state = 0;
  bState = false;
  timer_micros = micros();
  elapsedTime_micros = 0;
  pinMode(pin, INPUT);
}

void ActionButton::reset(){
  elapsedTime_micros = 0;
}

void ActionButton::updateTimer(){
  timer_micros = micros();
}
void ActionButton::calculateElapsedTime(){
  elapsedTime_micros = micros() - timer_micros;
}

void ActionButton::updateState(){
  if(counter==0){
    state = 0;
  }
  if(counter==1){
    state = 1;
  }
  if(counter>1){
    state = 2;
  }
}

bool ActionButton::isSinglePressed(){
  bool result = false;
  if(state == 1){
    result = true;
  }
  return result;
}

bool ActionButton::isDoublePressed(){
  bool result = false;
  if(state == 2){
    result = true;
  }
  return result;
}

void ActionButton::loop(){
  calculateElapsedTime();
  if(state!=0 ){
    state = 0;
  }
  if( digitalRead(pin) == 1){
    if(bState == false){
      bState = true;
      if(elapsedTime_micros>AB_INTERVAL_MICROS){
        updateState();
        updateTimer();
        counter = 1;
        bState = false;
      } else {
        counter = counter + 1;
        updateTimer();
      }
    }
  } else {
    if(bState == true){
      bState = false;
    }
      if(elapsedTime_micros>AB_INTERVAL_MICROS){
        updateState();
        updateTimer();
        counter = 0;
    }
  }

}
