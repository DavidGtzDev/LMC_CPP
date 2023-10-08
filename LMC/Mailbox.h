#pragma once


class Mailbox
{
private:
	int memoryArray[100];
	int* ptr = memoryArray;
public:
	Mailbox();
	void loadM(int direccionMemoria, int instrucccion);
	int leerM(int direccionMemoria);
};

