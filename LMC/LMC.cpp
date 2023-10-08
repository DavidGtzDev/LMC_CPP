#include <iostream>
#include <fstream>
#include <string>
#include "Interpretador.h"
#include "Mailbox.h"
using namespace std;

int main()
{
	string nombreArchivo = "for.txt";
	ifstream archivo(nombreArchivo.c_str());
	string linea;
	Interpretador interpretador;
	string direccion, instruccion;


	while (getline(archivo, linea)) {

		size_t posicionComa = linea.find(',');

		if (posicionComa != string::npos) {
			direccion = linea.substr(0, posicionComa);
			instruccion = linea.substr(posicionComa + 1);
			interpretador.getMailbox().loadM(stoi(direccion), stoi(instruccion));
		}
		else {
			cout << "El formato no es válido." << endl;
		}
	}
 
	interpretador.ejecutar();
}
