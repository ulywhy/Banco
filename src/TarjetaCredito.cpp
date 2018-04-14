#ifndef TARJETA_CREDITO_CPP
#define TARJETA_CREDITO_CPP

#include<iostream>

#include"../include/TarjetaCredito.h"

using namespace std;


TarjetaCredito::TarjetaCredito(string NIP):
Tarjeta(saldoDefault, NIP){
  this->limite = limiteDefault;
}
//implementa métodos virtuales
bool TarjetaCredito::retirar(double cantidad){
  if(saldo + limite >= cantidad){
    this->saldo -= cantidad;
    return true;
  }else{
    return false;
  }
}

string TarjetaCredito::toString(void){
  string result;
  result
  .append("\t").append(to_string(this->numero))
  //.append("\t").append(this->NIP)
  .append("\t").append("Credito")
  .append("\t").append(to_string(this->saldo))
  .append("\t").append(to_string(this->limite))
  .append("\t").append((esActiva() ? "ACTIVA" : "INACTIVA")).append("\n");
  return result;
}


#endif
