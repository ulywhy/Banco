#ifndef ATM_CPP
#define ATM_CPP

#include"../include/ATM.h"

using namespace std;

//atributos de clase
Cliente * ATM::cliente;
Tarjeta * ATM::tarjeta;

void ATM::run(void){

  cout << "----------ATM----------" << endl << endl;

  seleccionaTarjeta(); if(tarjeta == NULL) return;

  while(true){

    switch(seleccionaOperacion()){
      case SALDO:       verSaldo();   break;
      case DEPOSITO:    deposita();   break;
      case RETIRO:      retira();     break;
      case CAMBIAR_NIP: cambiaNIP();  break;
      case SALIR: return;
    }
  }
}


int ATM::seleccionaOperacion(void){
  int seleccion;

  cout << "----------Operaciones Disponibles----------" << endl;

  cout << SALDO           << ") Consultar Saldo"    << endl;
  cout << DEPOSITO        << ") Depositar"          << endl;
  cout << RETIRO          << ") Retirar"            << endl;
  cout << CAMBIAR_NIP     << ") Cambiar NIP"        << endl;

  cout << SALIR   << ") salir"              << endl;

  do{
    cin >> seleccion;
  }while( !(seleccion <= SALIR &&  seleccion >= 1) );

  return seleccion;
}

void ATM::seleccionaTarjeta(void){
  long numeroTarjeta;
  string NIP;
  int intentos = 1;

  /*cout << endl << "****TUS TARJETAS****" << endl;
  cliente->showTarjetas(true, false);
  cout << endl << endl;
*/
  do{
    do{
      cout << "ingresa tu número de tarjeta "; cin >> numeroTarjeta;
      tarjeta = Banco::getTarjeta(numeroTarjeta);
    }while(tarjeta == NULL);
    //si la tarjeta esta desactivada
    if(!tarjeta->esActiva()){
      cout << endl << "la tarjeta esta desactivada, visita a un ejecutivo para reactivar" << endl << endl;
      tarjeta = NULL;
      break;
    }
  }while(tarjeta == NULL);

  while(tarjeta != NULL){
    cout << "ingresa el NIP de la tarjeta #" << numeroTarjeta << " "; cin >> NIP;

    if(tarjeta->validar(NIP)) break;

    if(intentos++ == Banco::INTENTOS_INGRESO_NIP){
      cout << endl
      << "has agotado las oportunidades de ingreso, la tarjeta se ha desactivado" << endl
      << "visita a un ejecutivo para reactivar"
      << endl << endl;
      tarjeta->desactivar();
      tarjeta = NULL;
    }
  }
}

void ATM::verSaldo(void){
  cout << endl
  << "el saldo de la tarjeta #" << tarjeta->getNumero()
  << " es $" << tarjeta->getSaldo()
  << endl << endl;
}

void ATM::deposita(void){
  double cantidad;

  do{
    cout << endl << "ingresa la cantidad a depositar $"; cin >> cantidad;
  }while(cantidad <= 0);

  tarjeta->depositar(cantidad);

  verSaldo();
}
//el retiro es admisible solo en tarjetas de débito
void ATM::retira(void){
  double cantidad;
  //if tarjeta instance of TarjetaDebito
  do{
    cout << endl << "ingresa la cantidad a retirar $"; cin >> cantidad;
  }while(cantidad <= 0);

  cout << endl << (tarjeta->retirar(cantidad) ? "calculando efectivo..." : "no puedes retirar tal cantidad");

  verSaldo();
}

void ATM::cambiaNIP(void){
  string NIP;

  cout << endl << "ingresa el nuevo NIP "; cin >> NIP;

  tarjeta->setNIP(NIP);

  cout << "NIP actualizado exitosamente" << endl << endl;
}

#endif
