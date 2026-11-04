#ifndef BOTAO_H
#define BOTAO_H

#include <Arduino.h>

class Botao {
public:
    Botao(uint8_t pino);
    void begin();
    void atualizar();
    bool pressionado() const;

private:
    uint8_t _pino;
    bool _anterior;
    bool _pressionado;
};

#endif