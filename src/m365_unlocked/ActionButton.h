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

class ActionButton {

  #define AB_INTERVAL_MICROS 250000

  private:
    int counter;
    int pin;
    int state;
    bool bState;
    unsigned long timer_micros;
    unsigned long elapsedTime_micros;

    void reset();
    void updateState();
    void updateTimer();
    void calculateElapsedTime();

  public:
    ActionButton(int pin);
    void loop();
    bool isSinglePressed();
    bool isDoublePressed();

};
