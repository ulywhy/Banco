/**
    Cliente.h
    Define a un cliente del banco

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef CLIENTE_H
#define CLIENTE_H

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<stdlib.h>

#include"../src/Persona.cpp"
#include"../src/TarjetaCredito.cpp"
#include"../src/TarjetaDebito.cpp"

using namespace std;

class Cliente : public Persona {
  //Attributes
  private: /* const */ int id;
  private: string NIP;
  private: vector<long long> tarjetas;

  //constructor
  public: Cliente(string nombre, int id, string NIP);
  //métodos
  /**
    @return representacion textual del Cliente
  */
  public: string toString(void);
  /**
    @return El id del cliente
  */
  public: int getId(void);
  /**
    muestra las tarjetas del cliente
    @param Si activas = true muestra las tarjetas activas
    @param Si inactivas = true muestra las tarjetas inactivas
    @return Cantidad de tarjetas mostradas
  */
  public: int showTarjetas(bool activas, bool inactivas);
  /**
    agrega la tarjeta a la lista de tarjetas del cliente y del regristro del banco
    @param tarjeta que será agregada
  */
  public: void addTarjeta(Tarjeta * tarjeta);
  /**
    verifica que el NIP proporcionado coincida con el NIP del cliente
    @param NIP contraseña del cliente
    @return true si el NIP es correcto de lo contrario devuelve false
  */
  public: bool validar(string NIP);
  /**
    devuelve el vector de tarjetas del cliente
    @return tarjetas del cliente
  */
  public: vector<long long> getTarjetas(void);

};

#endif
