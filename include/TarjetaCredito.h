/**
    TarjetaCredito.h
    Clase que implementa una tarjeta y define a una tarjeta de crédito

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef TARJETA_CREDITO_H
#define TARJETA_CREDITO_H

#include<iostream>

#include"Tarjeta.h"

using namespace std;

class TarjetaCredito : public Tarjeta {

  private: double limite;
  private: double const saldoDefault = 0;
  private: double const limiteDefault = 20000.0;

  public: TarjetaCredito(string NIP);

  /**
    realiza un retiro de la tarjeta mientras no se rebase el limite de credito
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
