#include "Mailbox.h"
#include <iostream>
using namespace std;



Mailbox::Mailbox()
{// Inicializar la memoria a 0.
    for (int i = 0; i < 100; i++)
    {
        this->memoryArray[i] = 0;
    }
}

void Mailbox::loadM(int direccionMemoria, int instruccion)
{
    if (direccionMemoria >= 0 && direccionMemoria < 100) {

        this->ptr[direccionMemoria] = instruccion;
       
    }
    else {
        cerr << "Error: La dirección de memoria está fuera de rango." << endl;
    }
	
}

int Mailbox::leerM(int direccionMemoria)
{
    if (direccionMemoria >= 0 && direccionMemoria < 100) {
		return this->memoryArray[direccionMemoria];
	}
    else {
		cerr << "Error: La dirección de memoria está fuera de rango." << endl;
	}
}
