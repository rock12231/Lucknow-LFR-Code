#include <ArduinoRobot.h>

void setup(){
  Robot.begin();
  Serial.begin(9600);
}

void loop(){
  Robot.updateIR(); // update the IR array
  for(int i=0;i<=4;i++){
    Serial.print(Robot.IRarray[i]); // print the values to the serial port
    Serial.print(",");
  }
  Serial.println("");
  delay(100);
}
