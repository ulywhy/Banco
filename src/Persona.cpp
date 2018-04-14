#ifndef PERSONA_CPP
#define PERSONA_CPP

#include"../include/Persona.h"

using namespace std;
//constructor
Persona::Persona(string nombre){
  this->nombre = nombre;
}
//Metodos
string Persona::getNombre(void){
  return this->nombre;
}

string Persona::toString(void){
  string result;
  result.append("nombre: ").append(this->nombre).append("\n");
  return  result;
}

#endif
