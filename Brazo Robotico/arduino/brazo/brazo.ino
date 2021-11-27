// brazo.ino

//************************************
// Proyecto Introducción a mecatronica
//
// Proyecto: brazo robot
//
// Integrantes: - Adrian Becerra
//              - Adriana Cirilo
//              - Andrea Muñoz
//              - Andy Gutierrez
//              - Alessandro Lugo
//
//
//************************************

// Librerias
#include <Servo.h> // Libreria de control de servomotores

// Definiciones
#define B 9
#define S1 5
#define S2 6
#define G 3

// Declaración de servos
Servo base;
Servo servo1;
Servo servo2;
Servo grip;


// Variables
int pos_base = 0;
int pos1 = 0;
int pos2 = 0;
int pos_grip = 0;
String inputString;

 
void setup() {

  // Inicio de Serial
  Serial.begin(9600);

  // Organización de servos
  base.attach(B);
  servo1.attach(S1);
  servo2.attach(S2);
  /* grip.attach(G); */

}
 
void loop() {
  delay(100);
  SerialEvent();
  base.write(pos_base);
  servo1.write(pos1);
  servo2.write(pos2);
  delay(15);                       
}

void SerialEvent(){
  while(Serial.available()){
    char inputChar = Serial.read();
    inputString += inputChar;
  }
  byte prevPos = inputString.indexOf(':');
  String id = inputString.substring(0,prevPos);
  int value = inputString.substring(prevPos+1).toInt();
  if(id.equals("B")){
    pos_base = value;
  }else if(id.equals("S1")){
    pos1 = value;
  }else if(id.equals("S2")){
    pos2 = value;
  }else if(id.equals("G")){
    pos_grip = value;
  }

  inputString = "";
}

