#ifndef TARJETA_CPP
#define TARJETA_CPP

#include "../include/Tarjeta.h"

using namespace std;

int Tarjeta::totalTarjetas = 0;
long Tarjeta::cantidadTarjetas = 0;
//constructor
Tarjeta::Tarjeta(double saldo, string NIP){
  this->numero = ++totalTarjetas;
  this->saldo = saldo;
  this->NIP = NIP;
  this->estado = ACTIVA;
}
double Tarjeta::getNumero(void){
  return this->numero;
}

double Tarjeta::getSaldo(void){
  return this->saldo;
}

string Tarjeta::getNIP(void){
  return this->NIP;
}

void Tarjeta::depositar(double cantidad){
  this->saldo += cantidad;
}

bool Tarjeta::validar(string NIP){
  return this->NIP.compare(NIP) == 0;
}

bool Tarjeta::esActiva(void){
    return this->estado == ESTADO::ACTIVA;
}

void Tarjeta::activar(void){
  this->estado = ESTADO::ACTIVA;
}

void Tarjeta::desactivar(void){
  this->estado = ESTADO::INACTIVA;
}

void Tarjeta::setNIP(string NIP){
  this-> NIP = NIP;
}
#endif
