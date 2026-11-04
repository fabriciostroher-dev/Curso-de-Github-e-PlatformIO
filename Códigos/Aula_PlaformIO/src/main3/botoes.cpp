#include "botoes.h"
#include "estado.h"

void iniciarBotoes(){
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);
}

void lerBotoes(){
  static bool b1Ant = false;
  static bool b2Ant = false;

  bool b1 = !digitalRead(BUTTON1);
  bool b2 = !digitalRead(BUTTON2);

  b1Pressionado = b1 && !b1Ant;
  b2Pressionado = b2 && !b2Ant;

  b1Ant = b1;
  b2Ant = b2;
}