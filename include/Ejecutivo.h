/**
    Ejecutivo.h
    Clase estatica representa el estado de un ejecutivo

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef EJECUTIVO_H
#define EJECUTIVO_H

#include"Banco.h"
#include"Cliente.h"
#include"Tarjeta.h"

using namespace std;

class Ejecutivo {

  private: enum OPERACION {
    ALTA_TARJETA = 1,
    BAJA_TARJETA,
    ACTIVAR_TARJETA,
    RECUPERAR_NIP,
    IMPRIMIR_BALANCE,
    REGISTRAR_CLIENTE,
    SALIR
  };
  //estatica para atencion al cliente
  private: static Cliente * cliente;
  private: static Tarjeta * tarjeta;

  /**
    inicia el proceso de atencion como ejecutivo
  */
  public:  static void run(void);
  /**
    solicita el id del cliente y verifica que este registrado
  */
  private: static void login(void);
  /**
    solicita el numero de tarjeta y verifica que este registrada
    @param Si activas = true muestra las tarjetas activas
    @param Si inactivas = true muestra las tarjetas inactivas
  */
  private: static void seleccionaTarjeta(bool activas, bool inactivas);
  /**
    verifica que el estado de la tajeta sea activa
    @return si la tarjeta esta activa devuelve true, de lo contrario devuelve false
  */
  private: static bool validarTarjetaEstado(void);
  /**
    (recursiva) solicita el NIP de la tarjeta y verifica que este sea correcto
    @param intentos, se incrementa con cada llamada mientras no se alcance el limite de intentos
    @return true si se ingreso el NIP correcto false de lo contrario
  */
  private: static bool validarTarjetaNIP(int intentos);
  /**
    registra una nueva tarjeta para el cliente activo
  */
  private: static void altaTarjeta(void);
  /**
    permite elegir una tarjeta del cliente activo y la desactiva solo si su saldo es 0
  */
  private: static void bajaTarjeta(void);
  /**
    permite elegir una tarjeta del cliente activo y la activa
  */
  private: static void activarTarjeta(void);
  /**
    permite elegir una tarjeta del cliente activo y muestra el NIP de la misma
  */
  private: static void recuperarNIP(void);
  /**
    muestra una lista de las tarjetas del cliente activo además del balance de credito y saldos
  */
  private: static void imprimeBalance(void);
  /**
    solicita el tipo de operación
    @return tipo de operacion del ejecutivo
   */
  private: static int  seleccionaOperacion(void);
};

#endif
