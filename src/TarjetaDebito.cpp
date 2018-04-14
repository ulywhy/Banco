#ifndef TARJETA_DEBITO_CPP
#define TARJETA_DEBITO_CPP

#include<iostream>

#include"../include/TarjetaDebito.h"

using namespace std;

  TarjetaDebito::TarjetaDebito(double saldo, string NIP):
  Tarjeta(saldo, NIP){ }
  //implementa métodos virtuales
  bool TarjetaDebito::retirar(double cantidad){
    if(cantidad >= saldo){
      this->saldo -= cantidad;
      return true;
    }else{
      return false;
    }
  }

  string TarjetaDebito::toString(void){
    string result;
    result
    .append("\t").append(to_string(this->numero))
    //.append("\t").append(this->NIP)
    .append("\t").append("Debito")
    .append("\t").append(to_string(this->saldo))
    .append("\t").append(to_string(0.0))
    .append("\t").append((esActiva() ? "ACTIVA" : "INACTIVA")).append("\n");
    return result;
  }
#endif
