#include "telas.h"
#include "estado.h"
#include "sensores.h"

static void desenharMenu(){
  lcd.setCursor(0,0); lcd.print("MENU:               ");
  lcd.setCursor(0,1); lcd.print("B1 - Temperatura    ");
  lcd.setCursor(0,2); lcd.print("B2 - Endereco       ");
  lcd.setCursor(0,3); lcd.print("                    ");
  tela = 1;
}

static void desenharCelsius(){
  lcd.setCursor(0,0); lcd.print("TEMP. (");
  lcd.write(0xDF);    lcd.print("C)       ");

  lcd.setCursor(0,1); lcd.print("Temp. 1: ");
  lcd.print(s1, 1);   lcd.write(0xDF); lcd.print("C   ");

  lcd.setCursor(0,2); lcd.print("Temp. 2: ");
  lcd.print(s2, 1);   lcd.write(0xDF); lcd.print("C   ");

  lcd.setCursor(0,3); lcd.print("1: F  2: Sair       ");
}

static void desenharFahrenheit(){
  lcd.setCursor(0,0); lcd.print("TEMP. (F)           ");

  lcd.setCursor(0,1); lcd.print("Temp. 1: ");
  lcd.print(s1f, 1);  lcd.print(" F  ");

  lcd.setCursor(0,2); lcd.print("Temp. 2: ");
  lcd.print(s2f, 1);  lcd.print(" F  ");

  lcd.setCursor(0,3); lcd.print("2: Sair             ");
}

static void desenharEnderecos(){
  lcd.setCursor(0,0); lcd.print("ENDERECOS           ");

  lcd.setCursor(0,1); lcd.print("S1:");
  imprimirEndereco(S1, lcd);

  lcd.setCursor(0,2); lcd.print("S2:");
  imprimirEndereco(S2, lcd);

  lcd.setCursor(0,3); lcd.print("2: Sair             ");
}

void iniciarDisplay(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 1);
  lcd.print("Iniciando sistema!");
}

void navegarTelas(){
  if (tela == 1){
    if (b1Pressionado)      tela = 2;
    else if (b2Pressionado) tela = 4;
  }
  else if (tela == 2){
    if (b1Pressionado)      tela = 3;
    else if (b2Pressionado) tela = 0;
  }
  else if (tela == 3){
    if (b2Pressionado) tela = 0;
  }
  else if (tela == 4){
    if (b2Pressionado) tela = 0;
  }
}

void desenharTela(){
  if (tela != telaAnterior){
    lcd.clear();
  }

  switch (tela){
    case 0: desenharMenu();       break;
    case 1:                       break;
    case 2: desenharCelsius();    break;
    case 3: desenharFahrenheit(); break;
    case 4: desenharEnderecos();  break;
  }

  telaAnterior = tela;
}