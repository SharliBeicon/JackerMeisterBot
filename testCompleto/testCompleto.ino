#include <NewPing.h>
#include <Motor.h>
#include <CNY.h>
#include <Sharp.h>
  Sharp izq(A4);
  Sharp der(A3);
  CNY atras(A5);
  NewPing ultra(8, 8, 200);

void setup() {

  Serial.begin(9600);
}

void loop() {
  Serial.print("Distancia frontal: ");
  Serial.print(ultra.ping_cm());
  Serial.println(" cm");

  
  Serial.print("Distancia pared izq: ");
  Serial.print(izq.getDistance());
  Serial.println(" cm");

  Serial.print("Distancia pared der: ");
  Serial.print(der.getDistance());
  Serial.println(" cm");

  if(atras.onBlack())
    Serial.println("NEGRASO");
  else
    Serial.println("NO NEGRASO");
  delay(2500);
}

