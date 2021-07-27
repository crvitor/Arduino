//lógica sensor

#define LDR 6
#define reflet 7
#define infra 8
#define incl 9
#define LED1 30
#define LED2 31
#define LED3 32
#define LED4 33

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
Serial.begin(9600);

}

bool sensor1,sensor2,sensor3,sensor4,saida1,saida2,saida3,saida4;//variável global aqui ou depois do void

void loop() 
{
sensor1=digitalRead(LDR);
//Serial.println(sensor1);
sensor2=digitalRead(reflet);
//Serial.println(sensor2);
sensor3=digitalRead(infra);
//Serial.println(sensor3);
sensor4=digitalRead(incl);
//Serial.println(sensor4);

  if((sensor1||sensor2)&&(sensor3||sensor4)==1)//s=(a+b).(c+d)
  {
    saida1=1;
  }
  else
  {
    saida1=0;
  }
  //digitalWrite(LED1,saida1);//usar aqui ou no final
  //Serial.println(saida1);

      if((sensor1||sensor2||sensor3||sensor4)==1)//s=(a+b+c+d)
      {
        saida2=1;
      }
      else
      {
        saida2=0;
      }
      //digitalWrite(LED2,saida2);//usar aqui ou no final
      //Serial.println(saida2);

         if(!(sensor1||sensor2)|| !(sensor3||sensor4)==1)//s=(a+b)'(c+d)'
          {
            saida3=1;
          }
          else
          {
            saida3=0;
          }
          //digitalWrite(LED3,saida3);//usar aqui ou no final
          //Serial.println(saida3);

               if(sensor1 && sensor2 && sensor3 && sensor4==1)//s=(a.b.c.d)
              {
                saida4=1;
              }
              else
              {
                saida4=0;
              }
             // digitalWrite(LED4,saida4);//usar aqui ou no final
              Serial.println(saida4);

            //uso no final
            digitalWrite(LED1,saida1);
            digitalWrite(LED2,saida2);
            digitalWrite(LED3,saida3);
            digitalWrite(LED4,saida4);  
}
