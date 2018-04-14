/**
    Banco.h
    Clase estatica representa el estado de un banco

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/
#ifndef BANCO_H
#define BANCO_H

#include<iostream>
#include<vector>
#include<algorithm>

#include"Cliente.h"

using namespace std;

class Banco { //clase estática

  public: enum MODO {
    EJECUTIVO = 1,
    CLIENTE,
    SALIR
  };
  //constructor privado para evitar instancias
  private: Banco(){}
  //Constantes
  public: static const int INTENTOS_INGRESO_PASSWORD = 3;
  public: static const int INTENTOS_INGRESO_NIP = 3;
  //Atributos
  private: static long cantidadClientes;
  private: static vector<Cliente *> clientes;
  private: static vector<Tarjeta *> tarjetas;

  //MÉTODOS
  /**
    Punto de inicio de la aplicacion.
    Permite seleccionar entre cliente y ejecutivo
  */
  public: static void run(void);

  /**
    muestra el menu y valida la selección
  */
  private: static int seleccionaModo(void);

  /**
    inserta un cliente a la lista de clientes
    verifica que el id de cliente no se repita
    @param nombre nombre del cliente
    @param id del cliente
    @param NIP contraseña del cliente
  */
  public: static void addCliente(string nombre, string NIP);
  /**
    devuelve el vector de clientes
    @return vector de clientes del banco
  */
  public: static vector<Cliente *> getClientes(void);
  /**
    busca al cliente con el id
    @param id del cliente esperado
    @return apuntador al cliente con el id o NULL si no se encuentra el cliente
  */
  public: static Cliente * getCliente(int id);
  /**
    agrega la tarjeta a la lista de tarjetas del regristro del banco
    @param tarjeta que será agregada
  */
  public: static void addTarjera(Tarjeta * tarjeta);
  /**
    busca la tarjeta que tenga el numero de tarjeta proporcionado
    @param numero de la tarjeta que se busca
    @return apuntador a la tarjeta con el numero buscado o NULL si no se encuentra
  */
  public: static Tarjeta * getTarjeta(long long numero);
  /**
    @return representacion textual del banco
  */
  public: static string toString(void);

};
#endif
