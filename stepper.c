#include <lpc214x.h>

#define PULSE_DELAY 1000 // Adjust this value for desired speed and step size

void delay(unsigned int count) {
    unsigned int i;
    for (i = 0; i < count; i++);
}

void stepperMotorControl() {
    unsigned int sequence[] = {0x01, 0x02, 0x04, 0x08}; // Define the sequence for 4 steps

    int i, j;

    while (1) {
        for (i = 0; i < 4; i++) {
            IO0PIN = sequence[i]; // Output the sequence
            delay(PULSE_DELAY);   // Delay for motor speed
        }
    }
}

int main() {
    PINSEL0 = 0x00000000; // Configure GPIO pins as GPIO

    IODIR0 = 0x0000000F; // Set the lower 4 bits as outputs

    stepperMotorControl(); // Start stepper motor control

    return 0;
}
