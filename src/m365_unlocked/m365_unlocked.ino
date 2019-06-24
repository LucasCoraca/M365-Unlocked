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
#include "Light.h"
#include "Brake.h"
#include "BrakeL.h"

ActionButton *actionButton;
Light *frontLight;
Brake *brake;
BrakeL *brakeL;

void setup() {
   actionButton = new ActionButton(11);
   frontLight = new Light(13, actionButton); //FOR TESTING CHANGE IN THE FUTURE
   brake = new Brake(ACTIONB_PIN); //FOR TESTING CHANGE IN THE FUTURE
   brakeL = new BrakeL(13, actionButton, brake);
}

void loop() {
  actionButton->loop();
  //frontLight->loop();
  brake->loop();
  brakeL->loop();
}
