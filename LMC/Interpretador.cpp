#include "Interpretador.h"
#include <iostream>
using namespace std;


Interpretador::Interpretador()
{
	this->acumulador = 0;
	
}

void Interpretador::ejecutar()
{
	int pc = 0;
	while (true)
	{int instruccion = mailbox.leerM(pc);
		int opcode = instruccion / 100; 
		int direccion = instruccion % 100;
		


		if (instruccion == 0) {
			break;
		}

		switch (opcode)
		{
		case 1:
			add(direccion);
			break;
		case 2:
			sub(direccion);
			break;
		case 3:
			sta(direccion);
			break;
		case 5:
			lda(direccion);
			break;
		case 6:
			pc = bra(direccion);
			break;
		case 7:
			pc = brz(direccion, pc);
			break;
		case 8:
			pc = brp(direccion, pc);
			break;
		case 9:
			if (direccion == 1) {
				inp();
			}
			else if (direccion == 2) {
				out();
			}
			
			break;
		case 0:
			break;
		default:
			cerr << "Error: opcode no válido." << endl;
			break;
		}


		pc++;

	}
}

void Interpretador::add(int direccion)
{
	int valor = mailbox.leerM(direccion);
	this->acumulador += valor;

}

void Interpretador::sub(int direccion)
{int valor = mailbox.leerM(direccion);
	this->acumulador -= valor;
}

void Interpretador::sta(int direccion)
{	mailbox.loadM(direccion, this->acumulador);
}

void Interpretador::lda(int direccion)
{	this->acumulador = mailbox.leerM(direccion);
}

int Interpretador::bra(int direccion)
{
	return direccion - 1;
}

int Interpretador::brz(int direccion, int pc)
{
	if (this->acumulador == 0) {
		return direccion - 1;
	}
	
	return pc;
	
		

}

int Interpretador::brp(int direccion, int pc)
{
	if (this->acumulador > 0) {
		return direccion - 1;
	}
	
	return pc;
	
		


}

void Interpretador::inp()
{
	cout << "Dame un valor" << endl;
	cin >> this->acumulador;
}

void Interpretador::out()
{  cout << this->acumulador << endl;
}

Mailbox Interpretador::getMailbox()
{
	return this->mailbox;
}
