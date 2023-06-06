#include <LiquidCrystal.h>
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int umidade=0;
int prev=0;
int pres=0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print(" umidade do solo  ");
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  umidade=analogRead(A1);
  umidade=map(umidade,0,982,148,0);
  pres=umidade;
  if(umidade>100)
    umidade=100;
  else if(umidade<0)
    umidade=0;
  lcd.setCursor(6,1);
  //lcd.print(umidade); -> Comentado para não exibir a umidade no display
  lcd.print("  ");
  prev=umidade;
  delay(500);
  
  digitalWrite(A0, HIGH);
  delay(10); // Aguarda 10 milissegundos
  umidade = analogRead(A1);
  digitalWrite(A0, LOW); // Desliga o sensor para reduzir a corrosão
  lcd.print(umidade);
}
