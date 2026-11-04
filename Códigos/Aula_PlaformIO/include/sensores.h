#ifndef SENSORES_H
#define SENSORES_H

#include <Arduino.h>
#include <DallasTemperature.h>

void iniciarSensores();
void atualizarSensores();
void imprimirEndereco(DeviceAddress end, Print &out);

#endif