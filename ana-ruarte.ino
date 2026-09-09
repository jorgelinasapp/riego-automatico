const int pinSensor = A0; // pin conectado al potenciómetro (simula el sensor)
const int pinRojo = 10;
const int pinAmarillo = 9;
const int pinVerde = 8;

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int humedad = analogRead(pinSensor);
  Serial.println(humedad);

  digitalWrite(pinRojo, LOW);
  digitalWrite(pinAmarillo, LOW);
  digitalWrite(pinVerde, LOW);

  if (humedad > 600) {
    digitalWrite(pinRojo, HIGH);
  } else if (humedad >= 400 && humedad <= 600) {
    digitalWrite(pinAmarillo, HIGH);
  } else if (humedad < 400) {
    digitalWrite(pinVerde, HIGH);
  }
  delay(500);
}