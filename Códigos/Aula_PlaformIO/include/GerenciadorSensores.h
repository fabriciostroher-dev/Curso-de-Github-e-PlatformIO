#ifndef GERENCIADOR_SENSORES_H
#define GERENCIADOR_SENSORES_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include "SensorTemperatura.h"

class GerenciadorSensores {
public:
    GerenciadorSensores(uint8_t pinoOneWire,
                        DeviceAddress end1, DeviceAddress end2,
                        unsigned long intervaloMs = 1000);
    void begin();
    void atualizar();
    SensorTemperatura& sensor1();
    SensorTemperatura& sensor2();

private:
    OneWire _onewire;
    DallasTemperature _sensors;
    SensorTemperatura _s1;
    SensorTemperatura _s2;
    unsigned long _intervalo;
    unsigned long _ultimoPedido;
    bool _aguardando;
};

#endif