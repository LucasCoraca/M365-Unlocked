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

class Light;
class Brake;

class BrakeL : public Light{

  #define INTERVAL 100000

  protected:
    Brake *brake;
    bool bState;
    int previousState;
    unsigned long elapsedTime_micros;
    unsigned long timer_micros;

    void calculateElapsedTime();
  public:
    BrakeL(int lPin, ActionButton *ab, Brake *b);
    void loop();

};
