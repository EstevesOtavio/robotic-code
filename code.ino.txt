#include <Servo.h>  

int ledVermelho = 13;
int ledAmarelo = 12;
int ledVerde = 11;
int servoPin = 7;
int botao1 = 2;
int botao2 = 3;
int posicaoAtual = 0;

const int trigPin = 5;
const int echoPin = 6;
const int buzzer = 4;

const int distanciaLimite = 50;

Servo servoMotor;

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  servoMotor.attach(servoPin);
  servoMotor.write(posicaoAtual);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  
  Serial.begin(9600);
  
  
}

void loop() {
  if (digitalRead(botao1) == HIGH){
    posicaoAtual += 90;
  	servoMotor.write(posicaoAtual);
  }
  
  if (digitalRead(botao2) == HIGH){
    posicaoAtual -= 90;
  	servoMotor.write(posicaoAtual);
  }
  
  if (posicaoAtual <= 0){
    posicaoAtual = 0;
  }
  if (posicaoAtual >= 180){
  	posicaoAtual = 180;
  }
  
  if (posicaoAtual == 180){
   	digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  } else if (posicaoAtual == 90){
   	digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else if (posicaoAtual == 0){
   	digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  
  //digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  //digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
  //digitalWrite(trigPin, LOW);
  
  long duracao = pulseIn(echoPin, HIGH);

  int distancia = duracao * 0.034 / 2;

  if (distancia <= distanciaLimite) {
   
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledVermelho, HIGH);
  } else {
    digitalWrite(buzzer, LOW);
    digitalWrite(ledVermelho, LOW);
  }
  
  delay(100);
}