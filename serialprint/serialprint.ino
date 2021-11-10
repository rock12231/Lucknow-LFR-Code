const int irPins0 = A0;
const int irPins1 = A1;
const int irPins2 = A2;
const int irPins3 = A3;
const int irPins4 = A4;
const int irPins5 = A5;
const int irPins6 = 7;
const int irPins7 = 4;

int ir0=0;
int ir1=0;
int ir2=0;
int ir3=0; 
int ir4=0;
int ir5=0;
int ir6=0;
int ir7=0;

void setup()
{

  for(int i = 0 ; i <  ; i++)
  {
    pinMode("a"+i,INPUT);
    }
  /**
  pinMode(irPins0,INPUT);
  pinMode(irPins1,INPUT);
  pinMode(irPins2,INPUT);
  pinMode(irPins3,INPUT);
  pinMode(irPins4,INPUT);
  pinMode(irPins5,INPUT);
  pinMode(irPins6,INPUT);  
  pinMode(irPins7,INPUT);
  **/
  Serial.begin(9600);
}
void Update(void);
void loop() 
{
 Update();
 }
void Update(void)
  {
 ir0 = digitalRead(irPins0);
    ir1 = digitalRead(irPins1);
    ir2 = digitalRead(irPins2);
    ir3 = digitalRead(irPins3);
    ir4 = digitalRead(irPins4);
    ir5 = digitalRead(irPins5);
    ir6 = digitalRead(irPins6);
    ir7 = digitalRead(irPins7);
    Serial.print(" ONE:");
    Serial.print(ir0);
    Serial.print(" TWO:");
    Serial.print(ir1);
    Serial.print(" THREE:");
    Serial.print(ir2);
    Serial.print(" FOUR:");
    Serial.print(ir3);
    Serial.print(" FIVE:");
    Serial.print(ir4);
    Serial.print(" SIX:");
    Serial.print(ir5);
    Serial.print(" SEVEN:");
    Serial.print(ir6);
    Serial.print(" EIGHT:");
    Serial.print(ir7);
    Serial.println();
    delay(100);

    
  }


