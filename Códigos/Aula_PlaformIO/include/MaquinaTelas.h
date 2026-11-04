#ifndef MAQUINA_TELAS_H
#define MAQUINA_TELAS_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "Botao.h"
#include "GerenciadorSensores.h"

enum class EstadoTela : uint8_t {
    MENU,
    CELSIUS,
    FAHRENHEIT,
    ENDERECOS
};

class MaquinaTelas {
public:
    MaquinaTelas(LiquidCrystal_I2C &lcd,
                 GerenciadorSensores &sensores,
                 Botao &b1, Botao &b2);
    void begin();
    void atualizar();

private:
    LiquidCrystal_I2C &_lcd;
    GerenciadorSensores &_sensores;
    Botao &_b1;
    Botao &_b2;
    EstadoTela _estado;
    EstadoTela _anterior;

    void navegar();
    void desenhar();
    void desenharMenu();
    void desenharCelsius();
    void desenharFahrenheit();
    void desenharEnderecos();
};

#endif