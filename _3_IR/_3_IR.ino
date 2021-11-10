int motlp=11;
int motlm=10;
int motrp=9;
int motrm=6;

int left=A2;
int center1=A3;
int center2=A4;
int right=A5;

int Left;
int Center1;
int Center2;
int Right;


void setup()
{
  pinMode(motlp,OUTPUT);
  pinMode(motlm,OUTPUT);
  pinMode(motrp,OUTPUT);
  pinMode(motrm,OUTPUT);

  pinMode(left,INPUT);
  pinMode(center1,INPUT);
  pinMode(center2,INPUT);
  pinMode(right,INPUT);
  
}

void Update(void);
void loop() 
{
 Update();
 // font move
 if(Left == 1 && Center1 == 0 && Center2 == 0 && Right == 1)
 {
  analogWrite(motlp,255);
  analogWrite(motlm,0);
  analogWrite(motrp,255);
  analogWrite(motrm,0);
 }
 //left move
  if(Left == 1 && Center1 == 0 && Center2 == 0 && Right == 0)
 {
  analogWrite(motlp,255);
  analogWrite(motlm,0);
  analogWrite(motrp,255);
  analogWrite(motrm,0);
 }
}


