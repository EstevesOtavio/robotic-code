#include <Servo.h>

int ledVerde = 12;
int ledVermelho = 11;
int ledAmarelo = 13;
int micro_servo = 7;
int botao_esquerdo_pin = 2;
int botao_direito_pin = 3;
int botao_esquerdo_state = 0;
int botao_direito_state = 0;

int trigPin = 10;
int echoPin = 9; 
int buzzer = 8;

int servoAngle = 0;

Servo servoMotor;

void setup(){
  //leds
  pinMode (ledVermelho, OUTPUT);
  pinMode (ledAmarelo, OUTPUT);
  pinMode (ledVerde, OUTPUT);
  //motor
  pinMode (botao_esquerdo_pin, INPUT);
  pinMode (botao_direito_pin, INPUT);
  servoMotor.attach(micro_servo);
  servoMotor.write(servoAngle);
  //sonico e buzzer
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
	
}

void loop(){
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho,HIGH);
  delay(2000);
    
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, LOW);
  delay(5000);
  
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledVermelho,LOW);
  delay(100);
  
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledVermelho, HIGH);
  delay(100);
  
  digitalWrite(ledAmarelo, HIGH);
  delay(100);
  
  digitalWrite(ledAmarelo, LOW);
  delay(100);

 
  //Sirene de policia
/*  digitalWrite(ledVerde, HIGH);
  delay(100);
  
  digitalWrite(ledVerde, LOW);
  delay(100);
  
  digitalWrite(ledVermelho, HIGH);
  delay(100);
  
  digitalWrite(ledVermelho, LOW);
  delay(100);
  
  tone(buzzer,6800);
  delay(1000);
  
  for (int i = 500; i <= 1000; i++){ 
    tone(buzzer, i);
    delay(2);
  }
  
 
  for (int i = 1000; i >= 500; i--) { 
    tone(buzzer, i);  
    delay(2);
  }
  
  delay(100);*/
  
  //Servo Motor
  /*botao_esquerdo_state = digitalRead(botao_esquerdo_pin);
  botao_direito_state = digitalRead(botao_direito_pin);
  
  if (botao_esquerdo_state == HIGH){
    servoAngle -=90;
    if (servoAngle < 0 ){
      servoAngle = 0;
    }
    servoMotor.write(servoAngle);
    delay(200);
  }
  
  if (botao_direito_state == HIGH){
    servoAngle += 90;
   if (servoAngle > 180){
      servoAngle = 180;
    }
    servoMotor.write(servoAngle);
    delay(200);
  }
  if (servoAngle == 0){
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);  
  }
  if (servoAngle != 0){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);  
  }
  if (servoAngle == 90){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  }
  if (servoAngle != 90){
    digitalWrite(ledVerde, LOW);
   digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
 }
  if (servoAngle == 180){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }
  if (servoAngle != 180){
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  */
   //Medindo a distância com o sensor ultrassônico
  /*long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Converte o tempo em distância (em cm)

  // Controle do buzzer e LEDs com base na distância
  if (distance > 30) { // Longe - Verde
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer); // Não faz som quando está longe

  } else if (distance > 10 && distance <= 30) { // Média distância - Amarelo
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    
    tone(buzzer, 1000); // Som médio
    delay(300);
    noTone(buzzer);
    delay(300);

  } else if (distance <= 10) { // Perto - Vermelho
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    
   tone(buzzer, 1000); // Som rápido
    delay(100);
    noTone(buzzer);
    delay(100);
  } else {
  // Desliga todos os LEDs e o buzzer se nenhuma condição for atendida
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  }

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(50);
*/  
}