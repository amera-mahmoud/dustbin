# dustbin
This project aims to prevent the spread of infection and germs. With the help of ultrasonic sensor the user is not forced to use his hand touching the dustbin. It is done using pic 16f877A, servo motor to move the bin cover and ultrasonic sensor.

#### Description
Using timer1 module for two operations first with capture and compare module to generate pwm signal for servo motor then with also capture and compare module to sense the ultrasonic sensor echo signal.
pic 16f877A has two capture and compare modules. ccp1 module is used for sensing the echo signal and it is in capture rising edge mode. when the echo signal is in rising edge an interrupt occures, the value of ccp1 register is saved and the mode of ccp1 is changed to capture falling edge mode so when the signal is in falling edge an interrupt also occures, the value of ccp1 register is saved and using this two values to calculate the time of ultrasonic waves journey and then calculate the distance. Using this calculated distance to know if there is an object exists in the range between 3 to 15 cm so a decision is taken whether open the bin or close it.
The second ccp1 module is used for generating pwm signal for the servo motor, it is used in compare mode. when using a servo motor in this project we need only two position 0 degree position for closing the bin and 90 degree position for opening the bin. To make the servo motor go to 0 and 90 degrees the pwm signal should have 6.76 and 12.08 duty cycle, so from this information I calculated the values that should be written in ccp2 register to be compared with timer1 register value.

#### Project Vedio
https://drive.google.com/file/d/1kUnNiAtCZ5sWlvEC9OKh33dmTGjXQXa6/view
