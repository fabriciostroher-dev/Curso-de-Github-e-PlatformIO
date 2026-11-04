#ifndef SENSOR_TEMPERATURA_H
#define SENSOR_TEMPERATURA_H

#include <Arduino.h>
#include <DallasTemperature.h>

class SensorTemperatura {
public:
    SensorTemperatura(DeviceAddress endereco);
    void atualizar(DallasTemperature &sensors);
    float celsius() const;
    float fahrenheit() const;
    void imprimirEndereco(Print &out) const;

private:
    DeviceAddress _endereco;
    float _celsius;
    float _fahrenheit;
};

#endif