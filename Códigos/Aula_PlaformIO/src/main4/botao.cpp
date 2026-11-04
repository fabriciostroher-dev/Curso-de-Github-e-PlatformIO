#include "Botao.h"

Botao::Botao(uint8_t pino)
    : _pino(pino), _anterior(false), _pressionado(false) {}

void Botao::begin() {
    pinMode(_pino, INPUT_PULLUP);
}

void Botao::atualizar() {
    bool atual = !digitalRead(_pino);
    _pressionado = atual && !_anterior;
    _anterior = atual;
}

bool Botao::pressionado() const {
    return _pressionado;
}