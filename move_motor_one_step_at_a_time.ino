/*
  Stepper Motor Control - one revolution

  This program drives a unipolar or bipolar stepper motor.
  The motor is attached to digital pins 8 - 11 of the Arduino.



*/

const int height = 300;
const int width = 100;
const int degree_per = 1.9;
const int x_rot = 200;
const int y_rot = 300;
const int mass_of_head = 1.8;


int convert_xy(int x, int y);
int num_of_steps(int x_deg, int y_deg);
void checktension( int mass_of_head);


#include <Stepper.h>

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  // set the speed at 60 rpm:
  myStepper.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

int convert_xy (int x, int y)
{

  int x_deg = (x * (x_rot / width));
  int y_deg = (y * (y_rot / height));


  return  x_deg, y_deg;
}

int num_of_steps(int x_deg, int y_deg)
{
  int x_steps = x_deg / degree_per ;
  int y_steps = y_deg / degree_per ;

  return x_steps, y_steps;
}

void checktension( int mass_of_head)
{

}

