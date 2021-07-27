#include <Wire.h>
#include <MAX30100.h>
#include <SHCSR04.h>

//lógica analogica ultrassonico

#define LDR 6
#define reflet 7
#define infra 8
#define incl 9
#define LED1 30
#define LED2 31
#define LED3 32
#define LED4 33

MAX30100 pulsacao;
void setup() 
{
pinMode(LDR,INPUT);
pinMode(reflet,INPUT);
pinMode(infra,INPUT);
pinMode(incl,INPUT);  
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(LED3,OUTPUT);
pinMode(LED4,OUTPUT);
//coração
Serial.begin(9600);
Wire.begin();
pulsacao.begin(pw1600, i50, sr100);
}

SHCSR04 sensor5;// sensor ultrassonico
float ultrassonico;
int analogico1, analogico2;
float tensao1, percentual1,tensao2, percentual2;

void loop() 
{
//analogico
analogico1=analogRead(A0);
analogico2=analogRead(A1);
ultrassonico=sensor5.read(4,5);//4 trigger e 5 echo
Serial.println(ultrassonico);
//Serial.println(analogico1);

pulsacao.readSensor();// coração
Serial.println(pulsacao.IR);

//Analogico LDR
//processamento do sinal analogico em nivel de tensão (0-5v), (0-1023) (v=5/1023=4,88mv)
// conversão (tensao1*1023=5*analogico1)(tensao1=(5*analogico1)/1023)
//tensao1=5*analogico1/1023;
tensao1=0.00488*analogico1;
//Serial.print("Nivel de tensao: ");
//Serial.println(tensao1);
//conversao para percentual
percentual1=(1-analogico1/1023.0)*100;//o valor da divisão de 1023 o soft nao entende como valor int entao multip por .0
//Serial.print("luminosidade em %: ");
//Serial.println(percentual1);

//Analogico Microfone
tensao2=0.00488*analogico2;
//Serial.print("Nivel de tensao Mic: ");
//Serial.println(tensao2);
//conversao para percentual
percentual2=(1-analogico2/1023.0)*100;//o valor da divisão de 1023 o soft nao entende como valor int entao multip por .0
//Serial.print("Som em %: ");
//Serial.println(percentual2);
 
}
