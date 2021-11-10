const int irPins[6] = {A0, A1, A2, A3, A4, A5}; //pin dif
int irSensorDigital[6] = {0,0,0,0,0,0};// array variabale 
int backIr = 8;
int led = 13;
int pushButton = 2;
int i,j = 0; // for loop
int irSensors = B000000; // bit dif.


void setup() 
{ 
 
  for (int i = 0; i <= 5; i++)//input from IR array
  {pinMode(irPins[i], INPUT);}

Serial.begin(9600); // Starts the serial communication
}


void loop() {
     scan();
     Serial.println(irSensors+"\n");
     delay(3000);
     //check();
     
}   
void scan(){ //Scan IR white and black
  for ( byte count = 0; count < 6;count++ ){
  bitWrite(irSensors, count, digitalRead( irPins[count] ));
    } 
}
