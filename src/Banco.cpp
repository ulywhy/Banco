#ifndef BANCO_CPP
#define BANCO_CPP

#include<iostream>
#include"../include/Banco.h"
#include"Cliente.cpp"
#include"ATM.cpp"
#include"Ejecutivo.cpp"

using namespace std;

//atributo de clase: lista de clientes
vector<Cliente *> Banco::clientes;
vector<Tarjeta *> Banco::tarjetas;

long Banco::cantidadClientes = 0;

void Banco::run(void){
  while(true){
    int modo = seleccionaModo();

    switch(modo){

      case EJECUTIVO: Ejecutivo::run(); break;

      case CLIENTE: ATM::run(); break;

      case SALIR: cout << "adiós" << endl; return;

      default: break;
    }
  }
}

int Banco::seleccionaModo(void){
  int seleccion;
  cout << "----------Binevenido al Banco UAEM----------" << endl << endl;

  cout << EJECUTIVO  << ") ejecutivo" << endl;
  cout << CLIENTE    << ") cliente"   << endl;

  cout << SALIR       << ") salir"     << endl;

  cout << "****Elige el modo****" << endl;

  cin >> seleccion;//TODO: make an exception for characters

  while(seleccion != SALIR && seleccion != EJECUTIVO && seleccion != CLIENTE){
    cout << "opcion no válida" << endl;
    cin >> seleccion;//TODO: make an exception for characters
  }

  return seleccion;
}

void Banco::addCliente(string nombre, string NIP){
    clientes.push_back(new Cliente(nombre, ++cantidadClientes, NIP));
}

/**devuelve el vector e clientes
*/
vector<Cliente *> Banco::getClientes(void){
  return clientes;
}

/** devuelve el cliente que tenga el @param(id)
*/
Cliente * Banco::getCliente(int id){
  vector<Cliente *>::iterator it;
  it = find_if(clientes.begin(), clientes.end(), [id] (Cliente * cliente) {
    return (cliente->getId() == id);
  });
  return (it != clientes.end()) ? clientes[distance(clientes.begin(), it)] : NULL;
}

void Banco::addTarjera(Tarjeta * tarjeta){
  tarjetas.push_back(tarjeta);
}

Tarjeta * Banco::getTarjeta(long long numero){
  vector<Tarjeta *>::iterator it;
  it = find_if(tarjetas.begin(), tarjetas.end(), [numero] (Tarjeta * tarjeta) {
    return (tarjeta->getNumero() == numero);
  });
  return (it != tarjetas.end()) ? tarjetas[distance(tarjetas.begin(), it)] : NULL;
}

string Banco::toString(void){
  string result;
  result.append("\t----Banco----\n");
  for_each(clientes.begin(), clientes.end(), [&result] (Cliente * cliente) {
    result.append(cliente->toString()).append("\n");
  });
  return result;
}

#endif
