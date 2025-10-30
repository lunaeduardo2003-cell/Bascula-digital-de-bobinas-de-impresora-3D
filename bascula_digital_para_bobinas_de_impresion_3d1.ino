#include <LiquidCrystal.h>


float pesoBobinaVacia = 250;    
float alertaSuave = 300;       
float alertaMedia = 200;        
float alertaCritica = 100;      
float umbralParada = 50;       
// Pines
int sensor = A0;           
int LED = 2;               
int buzzer = 3;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  lcd.begin(16, 2);        
  lcd.print("BASCULA DIGITAL");  
  lcd.setCursor(0, 1);
  lcd.print("3D IOT");          
  delay(2000);
  
  pinMode(LED, OUTPUT);     
  pinMode(buzzer, OUTPUT);
  
  lcd.clear();
}

void loop() {
  int lecturaSensor = analogRead(sensor);
  float pesoTotal = map(lecturaSensor, 0, 1060, 1250, pesoBobinaVacia);
  float filamentoRestante = pesoTotal - pesoBobinaVacia;
  
  
  if (filamentoRestante <= umbralParada) {
    
    digitalWrite(LED, HIGH);       
    tone(buzzer, 1500);             
    lcd.setCursor(0, 1);
    lcd.print("!PARAR IMPRESION!");
    
  } else if (filamentoRestante <= alertaCritica) {
  
    digitalWrite(LED, HIGH);        
    tone(buzzer, 1000, 500);        
    lcd.setCursor(0, 1);
    lcd.print("!CRITICO! <100g ");
    
  } else if (filamentoRestante <= alertaMedia) {
    
    digitalWrite(LED, HIGH);       
    tone(buzzer, 800, 1000);       
    lcd.setCursor(0, 1);
    lcd.print("ALERTA <200g   ");
    
  } else if (filamentoRestante <= alertaSuave) {
  
    digitalWrite(LED, HIGH);        
    noTone(buzzer);                
    lcd.setCursor(0, 1);
    lcd.print("ATENCION <300g ");
    
  } else {
    
    digitalWrite(LED, LOW);         
    noTone(buzzer);
    lcd.setCursor(0, 1);
    lcd.print("NORMAL         ");
  }
  
 
  lcd.setCursor(0, 0);
  lcd.print("Filam: ");
  lcd.print(filamentoRestante);
  lcd.print("g   ");

  delay(500);
}