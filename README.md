# dustbin
This project aims to prevent the spread of infection and germs by using an ultrasonic sensor to allow the user to operate the dustbin cover without having to touch it. It utilizes a PIC 16F877A microcontroller, a servo motor to move the bin cover, and an ultrasonic sensor.

#### Description
Using the timer1 module for two operations. First with the capture and compare module to generate a PWM signal for the servo motor. Second with the capture and compare module to sense the ultrasonic sensor echo signal.Pic 16f877A has two capture and compare modules.<br> 
The CCP1 module is responsible for sensing the echo signal from the ultrasonic sensor. Initially, it operates in capture rising edge mode. When the echo signal reaches the rising edge, an interrupt occurs and the value of the CCP1 register is saved. Following this, the mode of CCP1 is changed to capture falling edge mode. When the signal reaches the falling edge, another interrupt occurs and the value of the CCP1 register is saved. The capture mode then returns to the rising edge mode. The two saved values are used to calculate the time of the ultrasonic waves' journey and the distance. This calculated distance is used to determine if there is an object within the range of 3 to 15 cm. Based on this information, a decision is made whether to open or close the bin.<br>
The second ccp2 module is utilized to generate a PWM signal for the servo motor in the compare mode. When using a servo motor, only two positions are required: the 0-degree position for closing the bin and the 90-degree position for opening the bin. To achieve these positions, the PWM signal should have a duty cycle of 6.76 for 0 degrees and 12.08 for 90 degrees. Based on this information, I calculated the values that should be written in the ccp2 register to be compared with the timer1 register value in order to generate the PWM signal.

#### Project Vedio
https://drive.google.com/file/d/1kUnNiAtCZ5sWlvEC9OKh33dmTGjXQXa6/view
