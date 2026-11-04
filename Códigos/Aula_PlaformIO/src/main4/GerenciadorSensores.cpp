#include "GerenciadorSensores.h"

GerenciadorSensores::GerenciadorSensores(uint8_t pinoOneWire,
                                         DeviceAddress end1, DeviceAddress end2,
                                         unsigned long intervaloMs)
    : _onewire(pinoOneWire),
      _sensors(&_onewire),
      _s1(end1),
      _s2(end2),
      _intervalo(intervaloMs),
      _ultimoPedido(0),
      _aguardando(false) {}

void GerenciadorSensores::begin() {
    _sensors.begin();
    _sensors.setWaitForConversion(false);
}

void GerenciadorSensores::atualizar() {
    if (!_aguardando && (millis() - _ultimoPedido >= _intervalo)) {
        _sensors.requestTemperatures();
        _aguardando = true;
        _ultimoPedido = millis();
    }
    if (_aguardando && _sensors.isConversionComplete()) {
        _s1.atualizar(_sensors);
        _s2.atualizar(_sensors);
        _aguardando = false;
    }
}

SensorTemperatura& GerenciadorSensores::sensor1() { return _s1; }
SensorTemperatura& GerenciadorSensores::sensor2() { return _s2; }