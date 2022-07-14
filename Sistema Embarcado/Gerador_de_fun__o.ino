/******************************************************************
  TRABALHO EMBS-CIMATEC|TRAINEEs: ANDRÉ;BIANCA;J.VICENTE;VINÍCIUS
  ---------------------------------------------------------------
   Teclado Assistivo: o projeto ultiliza de um teclado Matricial,
   lógica em sistema embarcado, dispositivos de saída em LCD
   para verificação e em Buzzer para representação por freqências
 ******************************************************************
*/


// biblioteca Keypad e LCD
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);

const int motor = 12; //motor na porta 12

const int Buz = 13; // Buzzer na porta 13

// Matriz 4x4
const byte ROWS = 4; // 4 linhas
const byte COLS = 4; // 4 colunas
int cont = 0;
char Keys[ROWS][COLS] = // La matrice del Keypad 4x4.

{
  {'1', '2', '3', 'A'} ,
  {'4', '5', '6', 'B'} ,
  {'7', '8', '9', 'C'} ,
  {'*', '0', '#', 'D'}
};

byte colPins[4] = {5, 4, 3, 2}; // Pin assegnati alle colonne
byte rowPins[4] = {9, 8, 7, 6}; // Pin assegnati alle righe

// inicialização Keypad
Keypad keypad = Keypad( makeKeymap(Keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600); // inicializar monitor serial
  //lcd.begin(16, 2);// inicializar lcd
  lcd.init();
  lcd.backlight();
  lcd.clear();// limpar lcd
  pinMode(Buz, OUTPUT); // declarar Buzzer como saída
  pinMode(motor, OUTPUT); // declarar motor como saída
  lcd.print("teclado assistivo");
  lcd.setCursor(0, 1);
  delay(1000); // espera 1s
}

void loop() {

  char tecla = keypad.getKey();//capta dados do teclado 4x4
  /*lógica se alguma tecla for clicada entra em analise de casos
    será imprimida no LCD e uma freqência é emetida para cada tecla
  */
  if (tecla != NO_KEY) {
    switch (tecla) {
      case '0':
        lcd.print(tecla);
        tone(Buz, 2793, 85);
        break;
      case '1':
        lcd.print(tecla);
        tone(Buz, 220, 85);
        break;
      case '2':
        lcd.print(tecla);
        tone(Buz, 261, 85);
        break;
      case '3':
        lcd.print(tecla);
        tone(Buz, 329, 85);
        break;
      case '4':
        lcd.print(tecla);
        tone(Buz, 493, 85);
        break;
      case '5':
        lcd.print(tecla);
        tone(Buz, 587, 85);
        break;
      case '6':
        lcd.print(tecla);
        tone(Buz, 698, 85);
        break;
      case '7':
        lcd.print(tecla);
        tone(Buz, 1046, 85);
        break;
      case '8':
        lcd.print(tecla);
        tone(Buz, 1318, 85);
        break;
      case '9':
        lcd.print(tecla);
        tone(Buz, 1567, 85);
        break;
      case 'A':
        lcd.print(tecla);
        tone(Buz, 392, 85);
        break;
      case 'B':
        lcd.print(tecla);
        tone(Buz, 880, 85);
        break;
      case 'C':
        lcd.print(tecla);
        tone(Buz, 1975, 85);
        break;
      case 'D':
        lcd.print(tecla);
        tone(Buz, 4186, 85);
        break;
      case '*':
        lcd.print(tecla);
        tone(Buz, 2349, 85);
        break;
      case '#':
        lcd.print(tecla);
        tone(Buz, 3520, 85);
        //digitalWrite(motor, HIGH);
        //delay(85); // Wait for 1000 millisecond(s)
        //digitalWrite(motor, LOW);
    }

    cont++;
    if (cont >= 17) {
      delay(85); // espera 1s
      tone(Buz, 0, 85);
      lcd.clear();
      cont = 0;
      lcd.print("teclado assistivo");
      lcd.setCursor(0, 1);
      lcd.print(tecla);
    }
    tecla = NO_KEY;//reseta váriável
  }
}
