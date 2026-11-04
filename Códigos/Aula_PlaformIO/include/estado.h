#ifndef ESTADO_H
#define ESTADO_H

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#include "config.h"

extern DeviceAddress S1;
extern DeviceAddress S2;

extern OneWire onewire;
extern DallasTemperature sensors;
extern LiquidCrystal_I2C lcd;

extern int tela;
extern int telaAnterior;

extern float s1, s2, s1f, s2f;

extern bool b1Pressionado;
extern bool b2Pressionado;

extern bool aguardandoConversao;
extern unsigned long instantePedido;

#endif