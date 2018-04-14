#Headers
CC := g++
INCLUDE=include
BIN=bin
SRC=src
BUILDDIR=./build

TARGET := main

$(TARGET): $(BUILDDIR)/Persona.o $(BUILDDIR)/Cliente.o $(BUILDDIR)/Tarjeta.o $(BUILDDIR)/TarjetaCredito.o $(BUILDDIR)/TarjetaDebito.o $(BUILDDIR)/Banco.o $(BUILDDIR)/Ejecutivo.o
	$(CC) $(SRC)/Main.cpp -o $(TARGET)

$(BUILDDIR)/ATM.o: $(BUILDDIR)/Banco.o $(BUILDDIR)/Cliente.o $(BUILDDIR)/Tarjeta.o
	$(CC) -c $(SRC)/ATM.cpp

$(BUILDDIR)/Ejecutivo.o: $(BUILDDIR)/Banco.o $(BUILDDIR)/Cliente.o $(BUILDDIR)/Tarjeta.o
	$(CC) -c $(SRC)/Ejecutivo.cpp

$(BUILDDIR)/Banco.o: $(BUILDDIR)/Cliente.o
	$(CC) -c $(SRC)/Banco.cpp

$(BUILDDIR)/Tarjeta.o:
	$(CC) -c $(SRC)/Tarjeta.cpp

$(BUILDDIR)/TarjetaCredito.o: $(BUILDDIR)/Tarjeta.o
	$(CC) -c $(SRC)/TarjetaCredito.cpp

$(BUILDDIR)/TarjetaDebito.o: $(BUILDDIR)/Tarjeta.o
	$(CC) -c $(SRC)/TarjetaDebito.cpp

$(BUILDDIR)/Cliente.o: $(BUILDDIR)/Tarjeta.o $(BUILDDIR)/TarjetaCredito.o  $(BUILDDIR)/TarjetaDebito.o $(BUILDDIR)/Persona.o
	$(CC) -c $(SRC)/Cliente.cpp

$(BUILDDIR)/Persona.o:
	$(CC) -c $(SRC)/Persona.cpp

clean:
	rm -rf $(TARGET)

.PHONY: clean
