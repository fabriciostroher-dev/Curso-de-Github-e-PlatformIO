#include <Arduino.h>
#include "estado.h"
#include "botoes.h"
#include "sensores.h"
#include "telas.h"

void setup(){
  iniciarDisplay();
  iniciarSensores();
  iniciarBotoes();
  delay(500);
  s1 = sensors.getTempC(S1);
  s2 = sensors.getTempC(S2);
}

void loop(){
  lerBotoes();
  atualizarSensores();
  navegarTelas();
  desenharTela();
  delay(20);
}