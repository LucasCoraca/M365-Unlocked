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
#include "Arduino.h"
#include "ActionButton.h"

Light::Light(int lPin, ActionButton *ab){
  pin = lPin;
  pinMode(pin, OUTPUT);
  actionButton = ab;
}

void Light::loop(){
  if(actionButton->isSinglePressed()){
    toggle();
  }
}

void Light::toggle(){
  if(digitalRead(pin)==LOW){
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}
