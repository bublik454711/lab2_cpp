#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <stdexcept>
#include <vector>
#include "PersData.h"

class Client
{
public:
	Client();
	Client(PersData persdata, int compless, int totalless);
	~Client();

	PersData Getpersdata() const;
	int Getcompless() const;
	int Gettotalless() const;
	void Input();
	void Print() const;
	void Settotalless(int totalless);


private:
	PersData persdata;
	int compless;
	int totalless;

	bool CheckArguments(PersData persdata, int compless, int totalless);
};

bool Client::CheckArguments(PersData persdata, int compless, int totalless) {
	return compless > 0&& totalless>0;
}


Client::Client()
{
	persdata = PersData();
	compless = 0;
	totalless = 0;
}


Client::Client(PersData persdata, int compless, int totalless)
{
	this->persdata = persdata;
	this->compless = compless;
	this->totalless = totalless;
}

Client::~Client()
{
}


PersData Client::Getpersdata() const {
	return persdata;
}

int Client::Getcompless() const {
	return compless;
}

int Client::Gettotalless() const {
	return totalless;
}
void Client::Settotalless(int totalless) {
	this->totalless = totalless;
}

void Client::Input() {
	PersData persdata;
	int compless;
	int totalless;
	std::cout << "\tВвод данных клиента\n";
	persdata.Input();
	std::cout << "Введите кол-во пройденных занятий: ";
	std::cin >> compless;
	std::cout << "Введите кол-во всех занятий: ";
	std::cin >> totalless;
	if (CheckArguments(persdata, compless, totalless)) {
		this->persdata = persdata;
		this->compless = compless;
		this->totalless = totalless;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}

void Client::Print() const {
	std::cout << "\tИнформация о клиенте\n";
	std::cout << "ФИО: " << this->persdata.Getfio() << "\tКол-во пройденных уроков: " << this->compless << "\tВсего уроков: " << this->totalless << "\n\n";
}