#include <LiquidCrystal.h>

int seconds = 0;
int fotoresistorValue = 0; // Variável para armazenar o valor lido do fotoresistor
int tempSensor = 0;
int green = 6;
int umidade = 0;

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);

void setup() {
  pinMode(A0, INPUT); // Definir o pino A0 como entrada
  pinMode(A3, INPUT); // umidade
  pinMode(A5, INPUT); // temperatura
  lcd_1.begin(16, 2); // Configurar o número de colunas e linhas do LCD.
}

void loop() {
  fotoresistorValue = analogRead(A0); // Ler o valor analógico do pino A0
  tempSensor = analogRead(A5);
  
  lcd_1.setCursor(0, 0);
  lcd_1.print("Luminosidade:");
  
  if (fotoresistorValue < 100) {
    digitalWrite(6, 1);
    digitalWrite(A2, 0);
    digitalWrite(A1, 0);
    digitalWrite(A4, 0);
    lcd_1.setCursor(0, 1);
    lcd_1.print("ok");
  }
  else if (fotoresistorValue > 100 && fotoresistorValue < 130) {
    digitalWrite(6, 0);
    digitalWrite(A2, 1);
    digitalWrite(A1, 0);
    digitalWrite(A4, 0);
    lcd_1.setCursor(0, 1);
    lcd_1.print("alert");
  }
  else if (fotoresistorValue > 130) {
    digitalWrite(6, 0);
    digitalWrite(A2, 0);
    digitalWrite(A1, 1);
    digitalWrite(A4, 1);
    lcd_1.setCursor(0, 1);
    lcd_1.print("alta");
  }
  
  delay(3000);
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print("Temp.");
  lcd_1.setCursor(0, 1);
  lcd_1.print("Temp.=");

  if (tempSensor < 20 && tempSensor > 10) {
    lcd_1.setCursor(7,0);
    lcd_1.print("Ok");
    lcd_1.setCursor(7,1);
    lcd_1.print(tempSensor);
    lcd_1.setCursor(9,1);
    lcd_1.print("C");
  }
  else if (tempSensor < 10) {
    lcd_1.setCursor(7,0);
    lcd_1.print("Baixa");
    lcd_1.setCursor(7,1);
    lcd_1.print(tempSensor);
    lcd_1.setCursor(9,1);
    lcd_1.print("C");
  }
  else if (tempSensor > 20) {
    lcd_1.setCursor(7,0);
    lcd_1.print("Alta");
    lcd_1.setCursor(7,1);
    lcd_1.print(tempSensor);
    lcd_1.setCursor(10,1);
    lcd_1.print("C");
    digitalWrite(A4, 1);
  }
  delay(3000);
  lcd_1.clear();
  lcd_1.setCursor(0,0);
  lcd_1.print("Umidade");
  lcd_1.setCursor(0,1);
  lcd_1.print("Umidade=");

  umidade = analogRead(A3);
  lcd_1.setCursor(8,1);
  lcd_1.print(map(umidade, 0, 1023, 1, 100));
  lcd_1.setCursor(10,1);
  lcd_1.print("%");
  
  if (umidade > 80) {
    digitalWrite(A4, 1);
  }
  
  delay(3000);
  lcd_1.clear();
}
