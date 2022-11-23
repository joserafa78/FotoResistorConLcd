
//Mustra valor de FotoResistencia y Activa led RGB
//Deacuerdo a cada valor en el Rango.

#include <LiquidCrystal.h> //libreria..
LiquidCrystal lcd (7,6,5,4,3,2);
int RGB_R=9;
int RGB_V=10;
int RGB_A=11;
int SENSOR =0;
int LED =12;
int VALOR;
void setup()
{
  lcd.begin(16,2); //Inicializa el Display, 16 Com y 2 Fil
  lcd.setCursor(0,0);//Posicion del Cursor, columna y fila.
  lcd.print("-FOTORESISTOR-");//Mensaje a Mostrar.
     //-------------------

pinMode(LED,OUTPUT);
pinMode(RGB_R,OUTPUT);
pinMode(RGB_V,OUTPUT);
pinMode(RGB_A,OUTPUT);
	
}

void loop() 
{
VALOR= analogRead(SENSOR);//Captura el valor Analogo desde 1-1123
if (VALOR>0 && VALOR<200)
{
   muestraLCD(VALOR," LED VERDE       ");
   miColor(0,255,0);
}
if (VALOR>201 && VALOR<500)
{
   muestraLCD(VALOR," LED AZUL       ");
   miColor(0,0,255);
}
if (VALOR>501 )
{
   muestraLCD(VALOR," LED ROJO      ");
   miColor(255,0,0);
}


delay(1000);
}//******************************
 //Funcion para RGB
 void miColor(int rojo, int verde, int azul){
analogWrite(RGB_R,rojo);
analogWrite(RGB_V,verde);
analogWrite(RGB_A,azul);

}
//Funcion para Mostar en Display.
  void muestraLCD(int numero,String palabra){
    //lcd.setCursor(0,0);//Posicion del Cursor, columna y fila.
    //lcd.print("CONTADOR DE PULSOS..");
    lcd.setCursor(0,1);//Posicion del Cursor, columna y fila.
    lcd.print(numero);
    lcd.print(palabra);
  }