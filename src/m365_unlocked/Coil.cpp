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

#include "Coil.h"
#include "Arduino.h"

Coil::Coil(int pVcc, int pGnd){
  pinVcc = pVcc;
  pinGnd = pGnd;
  pinMode(pinVcc, OUTPUT);
  pinMode(pinGnd, OUTPUT);
  //start coil off;
  digitalWrite(pinVcc, LOW);
  digitalWrite(pinGnd, HIGH);
}

void Coil::setCoil(int state){
  //off
  if(state==NOT_CONNECTED){
    digitalWrite(pinVcc, LOW);
    digitalWrite(pinGnd, HIGH);
  }
  //vcc
  if(state==VCC){
    digitalWrite(pinVcc, HIGH);
    digitalWrite(pinGnd, HIGH);
  }
  //gnd
  if(state==GND){
    digitalWrite(pinVcc, LOW);
    digitalWrite(pinGnd, LOW);
  }
}
