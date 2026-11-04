#include "MaquinaTelas.h"

MaquinaTelas::MaquinaTelas(LiquidCrystal_I2C &lcd,
                           GerenciadorSensores &sensores,
                           Botao &b1, Botao &b2)
    : _lcd(lcd), _sensores(sensores), _b1(b1), _b2(b2),
      _estado(EstadoTela::MENU), _anterior(EstadoTela::ENDERECOS) {}

void MaquinaTelas::begin() {
    _lcd.init();
    _lcd.backlight();
    _lcd.setCursor(1, 1);
    _lcd.print("Iniciando sistema!");
}

void MaquinaTelas::navegar() {
    switch (_estado) {
        case EstadoTela::MENU:
            if (_b1.pressionado())      _estado = EstadoTela::CELSIUS;
            else if (_b2.pressionado()) _estado = EstadoTela::ENDERECOS;
            break;
        case EstadoTela::CELSIUS:
            if (_b1.pressionado())      _estado = EstadoTela::FAHRENHEIT;
            else if (_b2.pressionado()) _estado = EstadoTela::MENU;
            break;
        case EstadoTela::FAHRENHEIT:
            if (_b2.pressionado()) _estado = EstadoTela::MENU;
            break;
        case EstadoTela::ENDERECOS:
            if (_b2.pressionado()) _estado = EstadoTela::MENU;
            break;
    }
}

void MaquinaTelas::desenhar() {
    if (_estado != _anterior) _lcd.clear();
    switch (_estado) {
        case EstadoTela::MENU:       desenharMenu();       break;
        case EstadoTela::CELSIUS:    desenharCelsius();    break;
        case EstadoTela::FAHRENHEIT: desenharFahrenheit(); break;
        case EstadoTela::ENDERECOS:  desenharEnderecos();  break;
    }
    _anterior = _estado;
}

void MaquinaTelas::atualizar() {
    navegar();
    desenhar();
}

void MaquinaTelas::desenharMenu() {
    _lcd.setCursor(0,0); _lcd.print("MENU:               ");
    _lcd.setCursor(0,1); _lcd.print("B1 - Temperatura    ");
    _lcd.setCursor(0,2); _lcd.print("B2 - Endereco       ");
    _lcd.setCursor(0,3); _lcd.print("                    ");
}

void MaquinaTelas::desenharCelsius() {
    _lcd.setCursor(0,0); _lcd.print("TEMP. (");
    _lcd.write(0xDF);    _lcd.print("C)       ");

    _lcd.setCursor(0,1); _lcd.print("Temp. 1: ");
    _lcd.print(_sensores.sensor1().celsius(), 1);
    _lcd.write(0xDF);    _lcd.print("C   ");

    _lcd.setCursor(0,2); _lcd.print("Temp. 2: ");
    _lcd.print(_sensores.sensor2().celsius(), 1);
    _lcd.write(0xDF);    _lcd.print("C   ");

    _lcd.setCursor(0,3); _lcd.print("1: F  2: Sair       ");
}

void MaquinaTelas::desenharFahrenheit() {
    _lcd.setCursor(0,0); _lcd.print("TEMP. (F)           ");

    _lcd.setCursor(0,1); _lcd.print("Temp. 1: ");
    _lcd.print(_sensores.sensor1().fahrenheit(), 1);
    _lcd.print(" F  ");

    _lcd.setCursor(0,2); _lcd.print("Temp. 2: ");
    _lcd.print(_sensores.sensor2().fahrenheit(), 1);
    _lcd.print(" F  ");

    _lcd.setCursor(0,3); _lcd.print("2: Sair             ");
}

void MaquinaTelas::desenharEnderecos() {
    _lcd.setCursor(0,0); _lcd.print("ENDERECOS           ");

    _lcd.setCursor(0,1); _lcd.print("S1:");
    _sensores.sensor1().imprimirEndereco(_lcd);
    _lcd.print(" ");

    _lcd.setCursor(0,2); _lcd.print("S2:");
    _sensores.sensor2().imprimirEndereco(_lcd);
    _lcd.print(" ");

    _lcd.setCursor(0,3); _lcd.print("2: Sair             ");
}