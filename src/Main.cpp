#ifndef MAIN_CPP
#define MAIN_CPP

#include<iostream>
#include<vector>
#include<algorithm>

#include"Tarjeta.cpp"
#include"Banco.cpp"
#include"Cliente.cpp"
#include"TarjetaCredito.cpp"
#include"TarjetaDebito.cpp"

#define NOMBRE 0
#define PASS   1
class Main{
  public: static void run(void){
    //inicializar clientes
    int x;
    int cantidadClientes = 6;
    double saldoInicial = 4000;
    string clientesFalsos[cantidadClientes][2] = {
      {"Juan Pérez", "PASSJUAN"},
      {"Sabina goméz", "PASSSABINA"},
      {"Nicanor Gonzalez", "PASSNICANOR"},
      {"Matias Alcaráz",  "PASSMATIAS"},
      {"Ulises Osnaya", "PASSULISES"},
      {"Antonio López", "PASSANTONIO"}
    };

    for(x = 0; x < cantidadClientes; x++){
      Banco::addCliente(clientesFalsos[x][NOMBRE], clientesFalsos[x][PASS]);
    }
    vector<Cliente *> clientes = Banco::getClientes();
    for_each(clientes.begin(), clientes.end(),
    [saldoInicial] (Cliente * cl) {
      cl->addTarjeta(new TarjetaCredito("PASSWORD"));
      cl->addTarjeta(new TarjetaDebito(saldoInicial, "PASSWORD"));
    });
    cout << Banco::toString();
    Banco::run();
  }
};

int main(){
  Main::run();
}
#endif
