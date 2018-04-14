#ifndef EJECUTIVO_CPP
#define EJECUTIVO_CPP

#include"../include/Ejecutivo.h"

using namespace std;

//atributos de clase
Cliente * Ejecutivo::cliente;
Tarjeta * Ejecutivo::tarjeta;

void Ejecutivo::run(void){

  cout << "----------EJECUTIVO----------" << endl << endl;
  //pedir datos de cliente
  login();
  while(true){

    tarjeta  = NULL;

    switch(seleccionaOperacion()){
      case ALTA_TARJETA:      altaTarjeta();    break;
      case BAJA_TARJETA:      bajaTarjeta();    break;
      case ACTIVAR_TARJETA:   activarTarjeta(); break;
      case RECUPERAR_NIP:     recuperarNIP();   break;
      case IMPRIMIR_BALANCE:  imprimeBalance(); break;
      case SALIR: return;
    }
  }
}


int Ejecutivo::seleccionaOperacion(void){
  int seleccion;

  cout << "----------Operaciones Disponibles----------" << endl;

  cout << ALTA_TARJETA      << ") Alta Tarjeta"     << endl;
  cout << BAJA_TARJETA      << ") Baja Tarjeta"     << endl;
  cout << ACTIVAR_TARJETA   << ") Activar Tarjeta"  << endl;
  cout << RECUPERAR_NIP     << ") Recuperar NIP"    << endl;
  cout << IMPRIMIR_BALANCE  << ") Implimir Balance" << endl;

  cout << SALIR   << ") salir"              << endl;

  do{
    cin >> seleccion;
  }while( !(seleccion <= SALIR &&  seleccion >= 1) );

  return seleccion;
}


void Ejecutivo::altaTarjeta(void){
  int tipoTarjeta;
  string NIP;
  double saldo;

  do{
    cout << endl
    << "tipo de tarjeta: "  << endl
    << "1) crédito"         << endl
    << "2) débito"          << endl;

    cin >> tipoTarjeta;

  }while(tipoTarjeta != 1 && tipoTarjeta != 2);

  switch(tipoTarjeta){
    case 1: //credito
    cout << endl << "ingresa el NIP "; cin >> NIP;
    cliente->addTarjeta(new TarjetaCredito(NIP));
    break;
    case 2: //debito
    cout << endl << "ingresa el NIP "; cin >> NIP;
    do{
      cout << endl << "ingresa el saldo inicial (mínimo $4000) $"; cin >> saldo;
    }while(saldo < 4000);
    cliente->addTarjeta(new TarjetaDebito(saldo, NIP));
    break;
  }
  cout << endl << "tarjeta registrada exitosamente" << endl << endl;
}

void Ejecutivo::bajaTarjeta(void){

  seleccionaTarjeta(true, false); if(tarjeta == NULL) return;
  if( !validarTarjetaNIP(1) && validarTarjetaEstado()) return;

  if(tarjeta->getSaldo() == 0){
    tarjeta->desactivar();
  }else{
    cout << endl << "la tarjeta " << tarjeta->getNumero() << " no se puede dar de baja" << endl
    << "el saldo es: $" << tarjeta->getSaldo();
  }
}

void Ejecutivo::activarTarjeta(void){
  seleccionaTarjeta(true, true); if(tarjeta == NULL) return;
  if(tarjeta == NULL) return; //INACTIVAS

  tarjeta->activar();
}

void Ejecutivo::recuperarNIP(void){
  int numeroTarjeta;

  seleccionaTarjeta(true, false); if(tarjeta == NULL) return;

  cout << endl << "el NIP es: " << tarjeta->getNIP() << endl << endl;
}

void Ejecutivo::imprimeBalance(void){
  double saldoDebito = 0, saldoCredito = 0;

  vector<long long> tarjetas = cliente->getTarjetas();
  cout << "********Listado de Tarjetas********" << endl << endl;
  for_each(tarjetas.begin(), tarjetas.end(), [&saldoDebito, &saldoCredito] (long long numeroTarjeta) {

    Tarjeta * tj = Banco::getTarjeta(numeroTarjeta);
    cout << tj->toString() << endl;

    if(TarjetaCredito * t = dynamic_cast<TarjetaCredito *> (tj)){
      saldoCredito += t->getSaldo();
    }
    else if(TarjetaDebito * t = dynamic_cast<TarjetaDebito *> (tj)){
      saldoDebito += t->getSaldo();
    }
  });

  cout << "****Balance****" << endl
  << "saldo total:   $" << saldoDebito << endl
  << "credito total: $" << saldoCredito << endl;
}

void Ejecutivo::login(){
  int numeroCliente;

  do{
    cout << "ingresa el número del cliente "; cin >> numeroCliente;
    cliente = Banco::getCliente(numeroCliente);
  }while(cliente == NULL);
}

void Ejecutivo::seleccionaTarjeta(bool activas, bool inactivas){
  long long numeroTarjeta;
  string NIP;
  int cantidadTarjetas;

  cout << endl << "****TUS TARJETAS****" << endl;
  cantidadTarjetas = cliente->showTarjetas(activas, inactivas);
  cout << endl << endl;
  if(cantidadTarjetas > 0){
    do{
      cout << "ingresa tu número de tarjeta "; cin >> numeroTarjeta;
      tarjeta = Banco::getTarjeta(numeroTarjeta);
      if(tarjeta != NULL){
        if( (tarjeta->esActiva() && activas) || (!tarjeta->esActiva() && inactivas) ){
          break;
        }
      }
    }while(tarjeta == NULL);
  }
}

bool Ejecutivo::validarTarjetaEstado(){
  if(tarjeta->esActiva()){
    return true;
  }else{
    cout << endl << "la tarjeta esta desactivada, visita a un ejecutivo para reactivar" << endl << endl;
    tarjeta = NULL;
    return false;
  }
}
//funcion recursiva para verificar que el nip sea el de la tarjeta
bool Ejecutivo::validarTarjetaNIP(int intentos){
  string NIP;
  cout << "ingresa el NIP de la tarjeta #" << tarjeta->getNumero() << " ";
  cin >> NIP;
  if(tarjeta->validar(NIP)) return true;
  else if(intentos++ == Banco::INTENTOS_INGRESO_NIP){
    cout << endl
    << "has agotado las oportunidades de ingreso, la tarjeta se ha desactivado" << endl
    << "visita a un ejecutivo para reactivar"
    << endl << endl;
    tarjeta->desactivar();
    tarjeta = NULL;
    return false;
  }else{
    return validarTarjetaNIP(intentos);
  }
}
#endif
