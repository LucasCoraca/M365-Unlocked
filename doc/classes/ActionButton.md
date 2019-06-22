## ActionButton Class

This class is responsible to handle action button functionality.

It is able to detect single and double button presses.

## How it works

After the button is pressed for the first time a timer is started, if the button is
pressed more than once it adds to a counter.

If the button is not pressed for more than 500 milliseconds then the timer and
counter are reset.

The readable button state(not(0), single(1) or double pressed(2)) is only updated once the 500 milliseconds is over.

![alt text](https://github.com/LucasCoraca/M365-Unlocked/blob/master/doc/classes/ActionButton.png)

## Class Diagram

![alt text](https://github.com/LucasCoraca/M365-Unlocked/blob/master/doc/classes/ActionButtonClass.png)

void setup()

* setup pin mode on arduino start

void loop()

* handles ActionButton logic

void reset()

* reset timer and counter to default values

bool isSinglePressed()

* returns true if button is single pressed

bool isDoublePressed()

* returns true if double pressed
