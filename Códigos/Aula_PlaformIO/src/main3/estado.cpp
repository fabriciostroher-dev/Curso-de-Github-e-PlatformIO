#include "estado.h"

DeviceAddress S1 = {0x28, 0xFF, 0xCE, 0x86, 0x86, 0x16, 0x04, 0x8C};
DeviceAddress S2 = {0x28, 0xFF, 0xEB, 0xDD, 0x52, 0x16, 0x04, 0x6D};

OneWire onewire(ONE_WIRE_BUS);
DallasTemperature sensors(&onewire);
LiquidCrystal_I2C lcd(I2C_ARRD, COLUMNS, LINES);

int tela = 0;
int telaAnterior = -1;

float s1 = 0, s2 = 0, s1f = 0, s2f = 0;

bool b1Pressionado = false;
bool b2Pressionado = false;

bool aguardandoConversao = false;
unsigned long instantePedido = 0;