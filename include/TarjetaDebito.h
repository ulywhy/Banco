/**
    TarjetaDebito.h
    Clase que implementa una tarjeta y define a una tarjeta de debito

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef TARJETA_DEBITO_H
#define TARJETA_DEBITO_H

#include<iostream>

#include"Tarjeta.h"

using namespace std;

class TarjetaDebito : public Tarjeta {

  public: static constexpr double saldoMinimo = 4000.0;

  public: TarjetaDebito(double saldo, string NIP);

    /**
      realiza un retiro de la tarjeta mientras se cuente con el saldo suficiente
      @param cantidad a retirar
      @return true si el retiro fue exitoso, false de lo contrario
    */
  public: virtual bool retirar(double cantidad);
  /**
    @return representaion textual de la tarjeta
  */
  public: virtual string toString(void);
};

#endif
