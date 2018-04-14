#ifndef CLIENTE_CPP
#define CLIENTE_CPP

#include"../include/Cliente.h"
#include"../include/Banco.h"

using namespace std;

//constructor
Cliente::Cliente(string nombre, int id, string NIP)
:Persona(nombre){
  this->id = id;
  this->NIP = NIP;
}

string Cliente::toString(){
  string result = Persona::toString()
  .append("id: ").append(to_string(this->id)).append("\n")
  .append("NIP: ").append(this->NIP).append("\n");
  for_each(this->tarjetas.begin(), this->tarjetas.end(), [&result] (long long t) {

    result.append("#").append(to_string(t)).append("\n");
  });

  return result;
}

void Cliente::addTarjeta(Tarjeta * tarjeta){
  Banco::addTarjera(tarjeta);
  this->tarjetas.push_back(tarjeta->getNumero());
}

bool Cliente::validar(string NIP){
  return this->NIP.compare(NIP) == 0;
}

int Cliente::showTarjetas(bool activas, bool inactivas){
  int n = 0;
  for_each(this->tarjetas.begin(), this->tarjetas.end(), [&n, activas, inactivas] (long long t) {
    Tarjeta * tarjeta = Banco::getTarjeta(t);
    if( (tarjeta->esActiva() && activas) || (!tarjeta->esActiva() && inactivas) ){
      cout << tarjeta->toString(); n++;
    }
  });
  return n;
}

vector<long long> Cliente::getTarjetas(void){
  return this->tarjetas;
  }

int Cliente::getId(void){
  return this->id;
}

#endif
