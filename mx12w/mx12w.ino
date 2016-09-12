#include <ax12.h>
#include <BioloidController.h>

/***************************
 * AXSimpleTest
 * This sketch sends positional commands to the AX servo 
 * attached to it - the servo must set to ID # 1
 * The sketch will send a value, i, to the servo.
 * 'For' loops are used to increment and decrement the value of 'i'
 ***************************/

//import ax12 library to send DYNAMIXEL commands
#include <ax12.h>
#define ROTATION_RANGE 4095
#define NEW_LINE 10


char inByte;
char formerInByte;
int number_of_characters;
char byte_buffer[5];

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(50);
  Serial.println("System Starting");
  SetPosition(1,0); //set the position of servo # 1 to '0'
  delay(100);//wait for servo to move
}

void loop()
{  
  if (Serial.available()) {
    number_of_characters = Serial.readBytesUntil(NEW_LINE,byte_buffer,5);
    if (number_of_characters == 4) {
      moveToPosition(byte_buffer);
    } 
  }
}

void moveToPosition(char buffer[]) {
  unsigned int pos;
  pos = atoi(buffer);
  SetPosition(1, pos);
  
  //print position
  Serial.print("going to: "); 
  Serial.println(pos);
}







