#include <iostream>
#include <windows.h>  
#include "Lesson.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//пример работы с динамическим массивом "Lesson"
	Lesson* lessonsArray = new Lesson[2];
	for (int i = 0; i < 2; i++)
	{
		lessonsArray[i].Input();
		lessonsArray[i].Print();
	}
	lessonsArray[0].Setpaymentstatus(2);
	lessonsArray[0].Print();
	delete[] lessonsArray;
	
	//пример работы с массивом динамических объектов "Client"
	Client* clientsArray[2];
	clientsArray[0] = new Client();
	clientsArray[0]->Input();
	clientsArray[0]->Print();
	(*clientsArray[0]).Settotalless(25);
	clientsArray[0]->Print();
	clientsArray[1] = new Client();
	clientsArray[1]->Print();
	for (size_t i = 0; i < 2; i++) delete clientsArray[i];
}