/**
    ATM.h
    Clase estatica representa el estado de un Cajero automático

    un ATM no se intersapor información del cliente, solo le importa
    el estado de las tarjetas

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef ATM_H
#define ATM_H

#include"Banco.h"
#include"Cliente.h"
#include"Tarjeta.h"

using namespace std;

class ATM {
  private: enum OPERACION {
    SALDO = 1,
    DEPOSITO,
    RETIRO,
    CAMBIAR_NIP,
    SALIR
  };
  //estatica para interfaz de cajero automático
  private: static Cliente * cliente;
  private: static Tarjeta * tarjeta;

  public:  static void run(void);
  private: static void login(void);
  private: static void seleccionaTarjeta(void);
  private: static void verSaldo(void);
  private: static void deposita(void);
  private: static void retira(void);
  private: static void cambiaNIP(void);
  private: static int  seleccionaOperacion(void);
};

#endif
