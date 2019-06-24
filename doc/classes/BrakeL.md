## BrakeL

Handles brake light functionality

## Dependencies

Light class
Brake class

## How it works

If the brake is pressed blink

It must preserve the state it was before the brake was pressed

## Class Diagram

![alt text](https://github.com/LucasCoraca/M365-Unlocked/blob/master/doc/classes
/BrakeLClass.png)

Brake brake

* Active Brake instance

bool bState

* Used to store the last brake state

int previousState

* Used to store the last brake light state, before the brake was engaged, so
when it is released it goes back to that state

unsigned long elapsedTime_micros

* Stores the elapsed time since last back light toggle

unsigned long timer_micros

* used to calculate elapsed time
