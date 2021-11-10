const int motorRPin1 = 6; // motor +   
const int motorRPin2 = 9;  // motor -
const int motorLPin1 = 5; // +    
const int motorLPin2 = 3; // -

int maxSpeed = 255;//speed full left
int midSpeed = 140;   // speed slow 
int zeroSpeed = 0;   //null speed

const int irPins[6] = {A0, A1, A2, A3, A4, A5}; //pin dif
int irSensorDigital[6] = {0,0,0,0,0,0};// array variabale 
int backIr = 8;
int led = 13;
int pushButton = 2;
int i,j = 0; // for loop
int irSensors = B000000; // bit dif.


void setup() 
{ 
  pinMode(motorLPin1,OUTPUT);   //M     
  pinMode(motorLPin2,OUTPUT);   //O
  pinMode(motorRPin1,OUTPUT);   //T      
  pinMode(motorRPin2,OUTPUT);   //O
                                //R
 
  for (int i = 0; i <= 5; i++)//input from IR array
  {pinMode(irPins[i], INPUT);}

Serial.begin(9600); // Starts the serial communication
}

void loop() {
     scan();
     Serial.begin(irSensors+"\n");
     //check();
     
}   

void fastRightMove() {     //fast right  move 
     Serial.println("                         right motor forward (spin)");
     analogWrite(motorRPin1, 220);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 0);
     analogWrite(motorLPin2, 100);
  }

void slowRightMove() {      //slow right move
     Serial.println("                         right motor slow forward ");
     analogWrite(motorRPin1, 255);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 140);
     analogWrite(motorLPin2, 0);
 }

void fastLeftMove(){   //fast left turn
  Serial.println("                         left  motor forward (spin)");
     analogWrite(motorRPin1, 0);
     analogWrite(motorRPin2, 100);
     analogWrite(motorLPin1, 220);
     analogWrite(motorLPin2, 0);
  }
  
void slowLeftMove() { //slow left turn
     Serial.println("                         left  motor slow forward ");
     analogWrite(motorRPin1, 140);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 255);
     analogWrite(motorLPin2, 0);
  }
void go() { // forward move
     Serial.println("                         forward ");
     analogWrite(motorRPin1, 255);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 255);
     analogWrite(motorLPin2, 0);

}

void stopme() { //stop to bot
     Serial.println("                         stop");
     analogWrite(motorRPin1, 0);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 0);
     analogWrite(motorLPin2, 0);
  
}





void scan(){ //Scan IR white and black
  for ( byte count = 0; count < 6;count++ ){
  bitWrite(irSensors, count, digitalRead( irPins[count] ));
    } 
}

void check(){    
    switch(irSensors){
    case B000000:     //stop condition
    case B111111:
      stopme();
      break;
//    case B000001:
//    case B100000:
//    case B000011:
//    case B110000:
        
    case B000111:
    case B100111:
      slowLeftMove();
      break;
    case B111000:
    case B111001:
      slowRightMove();
      break;
    case B001111:
    case B011111:
      fastLeftMove();
      break;
    case B111100:
    case B111110:
      fastRightMove();
      break;
    case B110011:
      go();
      break;
    default:
      Serial.println("invalid case");
}
}
