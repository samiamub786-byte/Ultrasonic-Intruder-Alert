#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int trigPin = 2;
int echoPin = 3;
int ledPin = 6;     // RED LED Pin 6 par hai
int buzzerPin = 8;  // Buzzer Pin 8 par hai

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.print("System Secure");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Distance calculate karna
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // LCD par normal state dikhana
  lcd.setCursor(0, 0);
  lcd.print("Status: SECURE  ");
  lcd.setCursor(0, 1);
  lcd.print("Dist: "); lcd.print(distance); lcd.print(" cm    ");

  // 🚨 AGAR KOI 15cm KE ANDAR AAYE (Intruder Alert!)
  if (distance > 0 && distance < 15) {
    lcd.setCursor(0, 0);
    lcd.print("Status: ALERT!! ");
    
    digitalWrite(ledPin, HIGH);  // Red LED ON
    tone(buzzerPin, 1200, 100);  // Beep
    delay(100);
    
    digitalWrite(ledPin, LOW);   // Red LED OFF (Blinking effect)
    noTone(buzzerPin);
    delay(100);
  } else {
    // Agar sab clear hai toh LED aur Buzzer band
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(200); 
  }
}
