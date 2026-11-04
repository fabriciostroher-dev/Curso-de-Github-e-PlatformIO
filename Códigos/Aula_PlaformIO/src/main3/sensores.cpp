#include "sensores.h"
#include "estado.h"

void iniciarSensores(){
  sensors.begin();
  sensors.setWaitForConversion(false);
  sensors.requestTemperatures();
}

void atualizarSensores(){
  if (!aguardandoConversao && (millis() - instantePedido >= 1000)){
    sensors.requestTemperatures();
    aguardandoConversao = true;
    instantePedido = millis();
  }

  if (aguardandoConversao && sensors.isConversionComplete()){
    s1  = sensors.getTempC(S1);
    s2  = sensors.getTempC(S2);
    s1f = sensors.getTempF(S1);
    s2f = sensors.getTempF(S2);
    aguardandoConversao = false;
  }
}

void imprimirEndereco(DeviceAddress end, Print &out){
  for (int i = 0; i < 8; i++){
    if (end[i] < 16) out.print('0');
    out.print(end[i], HEX);
  }
}