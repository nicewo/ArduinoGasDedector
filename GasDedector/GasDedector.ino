#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#define MQ135_PIN A0
#define GAS_PIN 6
#define BUZZER_PIN 7
#define RELAY_PIN 8

DHT dht(DHTPIN, DHTTYPE);

int gasThreshold = 550;
int tempThreshold = 50;

bool buzzerState = false;

unsigned long previousMillis = 0;
const int buzzerInterval = 300;  // bip hızı

unsigned long dhtMillis = 0;
const unsigned long dhtInterval = 2000;

unsigned long debugMillis = 0;
const unsigned long debugInterval = 500;

float temp = 0;  // son geçerli değer

void setup() {
  Serial.begin(9600);
  dht.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  pinMode(GAS_PIN, INPUT);

  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(RELAY_PIN, LOW);
}


void loop() {
  int gasValue = analogRead(MQ135_PIN);

  // -------- DHT OKUMA (2 saniyede 1) --------
  if (millis() - dhtMillis >= dhtInterval) {
    dhtMillis = millis();

    float t = dht.readTemperature();

    if (!isnan(t)) {
      temp = t;  // sadece geçerliyse güncelle
    }
  }

  // -------- ALARM --------
  bool alarm = (gasValue > gasThreshold || temp > tempThreshold || !digitalRead(GAS_PIN));

  if (alarm) {
    digitalWrite(RELAY_PIN, HIGH);

    if (millis() - previousMillis >= buzzerInterval) {
      previousMillis = millis();
      buzzerState = !buzzerState;
      digitalWrite(BUZZER_PIN, buzzerState);
    }

  } else {
    digitalWrite(RELAY_PIN, LOW);
    digitalWrite(BUZZER_PIN, LOW);
    buzzerState = false;
  }


  if (millis() - debugMillis >= debugInterval) {
     debugMillis = millis();
   // -------- DEBUG --------
    Serial.print("Gas: ");
    Serial.print(gasValue);
    Serial.print("-");
    Serial.print(digitalRead(GAS_PIN));
    Serial.print(" Temp: ");
    Serial.println(temp);
  }
}