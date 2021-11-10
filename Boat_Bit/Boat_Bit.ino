
const int motorRPin1 = 6; // motor +   
const int motorRPin2 = 9; // motor -
const int motorLPin1 = 5; // +    
const int motorLPin2 = 3; // -

const int irPins[3] = {A3, A2, A1}; //pin dif
int irSensorDigital[3] = {0,0,0};// array variabale 
int i,j = 0; // for loop

int irSensors = B000; // bit dif.

int motorLSpeed = 255;//speed full left
int motorRSpeed = 255;//speed full right
int slow = 140;   // speed slow 
void setup() {
  
  
  Serial.begin(9600); // printing on display
  
  // Output of motor
  pinMode(motorLPin1,OUTPUT);        
  pinMode(motorLPin2,OUTPUT);
  pinMode(motorRPin1,OUTPUT);        
  pinMode(motorRPin2,OUTPUT);
   
  //input from IR array
  for (int i = 0; i <= 2; i++) 
  {pinMode(irPins[i], INPUT);}
 
}

void loop() {
     scan(); // IR return data
     check(); // switch inside function 
}   

void check( ) 
{    
     switch (irSensors) {

     case B000:
     left();
     break;
     
     case B100: 
     left();
     break;
      
     case B010:
     go();
     break;
     
     case B001: 
     right();
     break;

     case B110: 
     right();
     break;

     case B011: 
     left();
     break;
     
     case B111:
     stopme();        
     break;

     default:
     Serial.print("????");   
    
     }
}


void right()  // SLOW Right
{
     Serial.println("                     SLOW RIGHT... ");
     analogWrite(motorRPin1, 80);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 0);
     analogWrite(motorLPin2, 160);
}

void left()  // SLOW Right
{
     Serial.println("                     SLOW RIGHT... ");
     analogWrite(motorRPin1, 0);
     analogWrite(motorRPin2, 150);
     analogWrite(motorLPin1, 80);
     analogWrite(motorLPin2, 0);
}



/*void utrun()  // U TRUN
{
     Serial.println("                        U TRUN... ");
     analogWrite(motorRPin1, 100);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 0);
     analogWrite(motorLPin2, 120);
}

void left()  // Left
{
     Serial.println("                          LEFT... ");
     analogWrite(motorRPin1, 100);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 255);
     analogWrite(motorLPin2, 0);
}
void right()  // Right
{
     Serial.println("                         RIGHT... ");
     analogWrite(motorRPin1, 255);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 100);
     analogWrite(motorLPin2, 0);
}
void leftS()  // SLOW Left
{
     Serial.println("                      SLOW LEFT... ");
     analogWrite(motorRPin1, 0);
     analogWrite(motorRPin2, 180);
     analogWrite(motorLPin1, 100);
     analogWrite(motorLPin2, 0);
}
void rightS()  // SLOW Right
{
     Serial.println("                     SLOW RIGHT... ");
     analogWrite(motorRPin1, 100);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 0);
     analogWrite(motorLPin2, 180);
}*/
void go()  // Go
{
     Serial.println("                             GO... ");
     analogWrite(motorRPin1, 200);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 200);
     analogWrite(motorLPin2, 0);
}
void stopme()  // Stopme
{
     Serial.println("                           STOP... ");
     analogWrite(motorRPin1, 0);
     analogWrite(motorRPin2, 0);
     analogWrite(motorLPin1, 0);
     analogWrite(motorLPin2, 0);
}


void scan()//Scan IR white and black
{
  for ( byte count = 0; count <= 2;count++ )
{
  bitWrite(irSensors, count, digitalRead( irPins[count] ));
} 
}
