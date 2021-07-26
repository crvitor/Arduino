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

//if(e1==1)
//s1=0;
//else
//s1=1;// ou uso !
s1=!e1;

digitalWrite(LED,s1);
}
