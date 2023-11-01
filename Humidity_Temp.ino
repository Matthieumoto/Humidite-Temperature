#include "DHT.h"
#include "LiquidCrystal.h"

DHT dht(2, DHT11);
LiquidCrystal lcd = LiquidCrystal(8, 9, 10, 11, 12, 13);
int Choix(0);

void setup() {  
  // Initialise la capteur DHT11
  dht.begin();
  lcd.begin(16, 2);

  pinMode(7, OUTPUT); // VERT
  pinMode(6, OUTPUT); // JAUNE
  pinMode(5, OUTPUT); // ROUGE
  pinMode(3, INPUT); // BOUTON
  
}

void loop() {
  delay(1000);

  if (digitalRead(3) == HIGH) {
    Choix ++;
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(5, HIGH);
  }

  if (Choix == 3) {
    Choix = 1;
  }

  if (Choix == 0) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Clique sur le ");
    lcd.setCursor(0, 1);
    lcd.print("bouton");
  }
  
  if (Choix == 1) {
    delay(1000);
    if (dht.readHumidity() > 40 && dht.readHumidity() < 60) {
      digitalWrite(7, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      lcd.clear();
      lcd.setCursor(9, 1);
      lcd.print("Normal");
    } 

    if (dht.readHumidity() < 40 && dht.readHumidity() > 30) {
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(5, LOW);
      lcd.clear();
      lcd.setCursor(9, 1);
      lcd.print("Moyen");
    }

    if (dht.readHumidity() > 60 && dht.readHumidity() < 70) {
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(5, LOW);
      lcd.clear();
      lcd.setCursor(9, 1);
      lcd.print("Moyen");
    }

    if (dht.readHumidity() > 70 || dht.readHumidity() < 30) {
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      lcd.clear();
      lcd.setCursor(9, 1);
      lcd.print("Eleve");
    }

    float humidity = dht.readHumidity();

    lcd.setCursor(0, 0);
    lcd.print("Humidite =");

    lcd.setCursor(11, 0);  
    lcd.print(humidity, 0);

    lcd.setCursor(14, 0);  
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("Niveau :");
  }
  
  if (Choix == 2) {
    delay(1000);
    if (dht.readTemperature() > 15 && dht.readTemperature() < 20) {
        digitalWrite(7, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(5, LOW);
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("Bon");
      } 

      if (dht.readTemperature() < 15 && dht.readTemperature() > 10) {
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(5, LOW);
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("Froid");
      }

      if (dht.readTemperature() > 20 && dht.readTemperature() < 25) {
        digitalWrite(6, HIGH);
        digitalWrite(7, LOW);
        digitalWrite(5, LOW);
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("Chaud");
      }

      if (dht.readTemperature() > 25) {
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("Trop Chaud");
      }

      if (dht.readTemperature() < 10) {
        digitalWrite(5, HIGH);
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        lcd.clear();
        lcd.setCursor(6, 1);
        lcd.print("Trop froid");
      }

      float temp = dht.readTemperature();

      lcd.setCursor(0, 0);
      lcd.print("Temp =");

      lcd.setCursor(7, 0);  
      lcd.print(temp, 0);

      lcd.setCursor(10, 0);  
      lcd.print("C");

      lcd.setCursor(0, 1);
      lcd.print("Niv :");
  }
}


