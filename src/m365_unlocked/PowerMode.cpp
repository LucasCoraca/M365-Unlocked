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
#include "PowerMode.h"
#include "ActionButton.h"
#include "configuration.h"
#include "Arduino.h"


PowerMode::PowerMode(ActionButton *ab){
  mode = 2;
  maxPower = MAX_POWER_M2;
  maxSpeed = MAX_SPEED_M2;
  actionButton = ab;
}

void PowerMode::loop(){
  if(actionButton->isDoublePressed()){
    //Serial.println("entered");
      if(mode == 1){
        //Serial.println("entered");
        mode = 2;
        maxSpeed = MAX_SPEED_M2;
        maxPower = MAX_POWER_M2;
      } else{
      if( mode == 2){
        mode = 3;
        maxSpeed = MAX_SPEED_M3;
        maxPower = MAX_POWER_M3;
      }else{if( mode == 3 ){
        mode = 1;
        maxSpeed = MAX_SPEED_M1;
        maxPower = MAX_POWER_M1;
      }
      }
      }
  }
}

int PowerMode::getPowerMode(){
  return mode;
}

int PowerMode::getMaxSpeed(){
  return maxSpeed;
}

int PowerMode::getMaxPower(){
  return maxPower;
}
