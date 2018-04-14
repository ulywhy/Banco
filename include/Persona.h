/**
    Persona.h
    Clase base que define a una persona

    @author Ulises Rodrigo Gonzalez Osnaya
    @version 1.0.0  11/03/2018
*/#ifndef PERSONA_H
#define PERSONA_H

#include<iostream>
#include<string>

using namespace std;

class Persona{
  //atributos de clase
  public: static const int NOMBRE_MIN_LONG = 3;

  //constructor
  public: Persona(string nombre);

  //Atributos
  private: string nombre;

  //Metodos
  /**
    devuelve el nombre de la persona
    @return nombre de la persona
  */
  public: virtual string getNombre(void);
  /**
    @return representaion textual de la persona
  */
  public: string toString(void);

};
#endif
