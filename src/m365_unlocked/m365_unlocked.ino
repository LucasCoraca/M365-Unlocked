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
#include "PowerMode.h"
#include "Battery.h"
#include "Throttle.h"
//#include "Motor.h"

ActionButton *actionButton;
Light *frontLight;
Brake *brake;
BrakeL *brakeL;
PowerMode *powerMode;
Battery *battery;
Throttle *throttle;
//Motor *motor;

void setup()
{
  actionButton = new ActionButton(ACTIONB_PIN);
  powerMode = new PowerMode(actionButton);
  brake = new Brake(BRAKE_PIN);
  brakeL = new BrakeL(BACK_LIGHT_PIN ,actionButton, brake);
  battery = new Battery(BATTERY_PIN);
  throttle = new Throttle(THROTTLE_PIN);
  frontLight = new Light(FRONT_LIGHT_PIN, actionButton);
  //  motor = new Motor();
  Serial.begin(9600);
}

void loop()
{
  actionButton->loop();
  powerMode->loop();
  brakeL->loop();
  frontLight->loop();
  Serial.println(battery->getVoltage());

}
