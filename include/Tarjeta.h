/**
    Tarjeta.h
    Interfaz que define los comportamientos de una tarjeta

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef TARJETA_H
#define TARJETA_H


#include <iostream>
#include <string>

using namespace std;

class Tarjeta {
  private: enum ESTADO { ACTIVA, INACTIVA };

  public: static int totalTarjetas;
  private: static long cantidadTarjetas;
  protected: long long numero;
  protected: string NIP;
  protected: double saldo;
  protected: ESTADO estado;

  //constructor
  public: Tarjeta(double saldo, string NIP);
  /**
    @return numero de la tarjeta
  */
  public: virtual double getNumero(void);
  /**
    @return saldo de la tarjeta
  */
  public: virtual double getSaldo(void);
  /**
    @return NIP de la tarjeta
  */
  public: virtual string getNIP(void);
  /**
    deposita la cantidad proporcionada
    @param cantidad a depositar
  */
  public: virtual void depositar(double cantidad);
  /**
    verifica que el NIP proporcionado se acorrecto
    @param NIP
    @return true si el NIP es correcto, false de lo contrario
  */
  public: virtual bool validar(string NIP);
  /**
    verifica que elestado de la tarjeta se activar
    @return true si la tarjeta esta activa, false de lo contrario
  */
  public: virtual bool esActiva(void);
  /**
    activa la tarjeta
  */
  public: virtual void activar(void);
  /**
    desactiva la tarjeta
  */
  public: virtual void desactivar(void);
  /**
    asigna un nuevo NIP a la tarjeta
    @param nuevo NIP
  */
  public: virtual void setNIP(string NIP);
  /**
    metodo virtual puro -> convierte la clase en abstracta
    realiza un retiro de la tarjeta
    @param cantidad a retirar
  */
  public: virtual bool retirar(double cantidad) = 0;
  /**
    @return representaion textual de la tarjeta
  */
  public: virtual string toString(void) = 0;
};

#endif
