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

#include "pins_board_v1.h"
#include "configuration.h"
#include "ActionButton.h"

ActionButton actionButton = ActionButton::ActionButton(ACTIONB_PIN);


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
}

void loop() {
  actionButton.loop();
  if(actionButton.isSinglePressed()){
      digitalWrite(13,HIGH);
      Serial.println("s");
    }
  if(actionButton.isDoublePressed()){
      digitalWrite(13,LOW);
      Serial.println("d");
    }
}
