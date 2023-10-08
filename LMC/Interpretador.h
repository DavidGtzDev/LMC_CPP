#pragma once
#include "Mailbox.h"
#include <iostream>

class Interpretador
{
private:
	int acumulador;
	Mailbox mailbox;
	
public:
	Interpretador();
	void ejecutar();
	void add(int direccion);
	void sub(int direccion);
	void sta(int direccion);
	void lda(int direccion);
	int bra(int direccion);
	int brz(int direccion, int pc);
	int brp(int direccion, int pc);
	void inp();
	void out();
	Mailbox getMailbox();

	//
	//int add (int mailbox, int acumulador);
};

