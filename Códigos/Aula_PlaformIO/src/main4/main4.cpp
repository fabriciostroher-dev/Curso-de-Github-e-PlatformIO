#include <Arduino.h>
#include "Botao.h"
#include "GerenciadorSensores.h"
#include "MaquinaTelas.h"

DeviceAddress END1 = {0x28, 0xFF, 0xCE, 0x86, 0x86, 0x16, 0x04, 0x8C};
DeviceAddress END2 = {0x28, 0xFF, 0xEB, 0xDD, 0x52, 0x16, 0x04, 0x6D};

Botao b1(10);
Botao b2(11);
GerenciadorSensores sensores(9, END1, END2);
LiquidCrystal_I2C lcd(0x27, 20, 4);
MaquinaTelas telas(lcd, sensores, b1, b2);

void setup() {
    telas.begin();
    sensores.begin();
    b1.begin();
    b2.begin();
}

void loop() {
    b1.atualizar();
    b2.atualizar();
    sensores.atualizar();
    telas.atualizar();
    delay(20);
}