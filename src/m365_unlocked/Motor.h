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

class Battery;
class Throttle;
class Brake;
class PowerMode;
class Coil;

class Motor{

  private:

    //dependencies
    Throttle *throttle;
    Brake *brake;
    PowerMode *powerMode;
    Battery *battery;

    //Coils
    Coil *coilA;
    Coil *coilB;
    Coil *coilC;

    //hall sensors pins
    int sensorA;
    int sensorB;
    int sensorC;

    //main variables
    unsigned long timer_micros;
    unsigned long elapsedTime_micros;
    int rpm;
    int speed_kmh;
    int power;
    int targetSpeed_kmh;

    //fase functions
    void setFase1();
    void setFase2();
    void setFase3();
    void setFase4();
    void setFase5();
    void setFase6();
    void setOff();

    //main functions
    void accelerate();
    void brakeM();
    void updateTargetSpeed();
    void updateTargetPower();
    void calculateSpeed();


  public:
    Motor(int aVcc,int aGnd,int bVcc,int bGnd,int cVcc,int cGnd,int sA,int sB,
      int sC, Throttle *t, Brake *bK, PowerMode *pM, Battery *bT);
    int getSpeed();
    void loop();

};
