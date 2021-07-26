//lógica ou
#define chave1 10
#define chave2 11
#define LED 30

void setup() 
{
pinMode(chave1,INPUT_PULLUP);
pinMode(chave2,INPUT_PULLUP);
pinMode(LED,OUTPUT);
}
bool e1,e2,s1;//variável global

void loop() 
{
 e1=digitalRead(chave1);
 e2=digitalRead(chave2); 

if(e1==1 || e2==1)
s1=1;
else
s1=0;
digitalWrite(LED,s1);
}
