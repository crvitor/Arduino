#define chave 22
#define LED 23

void setup() 
{
  //configuração de um micrcontrolador
  //seráexecutado uma unica vez
  
//configuração dos pinos i/o digitais
// 0=output, 1=input
//pinMode(2,1);
//pinMode(chave,1);
pinMode(chave,INPUT_PULLUP);
pinMode(LED,OUTPUT);
Serial.begin(9600);
}
//bool entrada;
//bool saida;
bool entrada,saida;//variável global

void loop()
{
//a=b a(recebe b)  
//a==b a igual a b
//entrada=digitalRead(2)
entrada=digitalRead(chave);

//logica bafer
//saida = entrada;// ou uso uma condicional (if)
if(entrada==1)// ou simplesmente (entrada)
{
saida=1;
Serial.print("Entrada acionada: ");
}
else
{
saida=0;
Serial.print("Entrada desacionada: ");
}

//digitalWrite(LED,1);
digitalWrite(LED,saida);
Serial.print("Estado do LED: ");
Serial.println(saida);
}
