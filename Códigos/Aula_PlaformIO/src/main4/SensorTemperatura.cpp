#include "SensorTemperatura.h"

SensorTemperatura::SensorTemperatura(DeviceAddress endereco)
    : _celsius(0.0f), _fahrenheit(0.0f) {
    memcpy(_endereco, endereco, 8);
}

void SensorTemperatura::atualizar(DallasTemperature &sensors) {
    _celsius    = sensors.getTempC(_endereco);
    _fahrenheit = sensors.getTempF(_endereco);
}

float SensorTemperatura::celsius() const    { return _celsius; }
float SensorTemperatura::fahrenheit() const { return _fahrenheit; }

void SensorTemperatura::imprimirEndereco(Print &out) const {
    for (int i = 0; i < 8; i++) {
        if (_endereco[i] < 16) out.print('0');
        out.print(_endereco[i], HEX);
    }
}