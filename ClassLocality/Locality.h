/// \file Locality.h
/// \brief Заголовочный файл модуля Locality.cpp с классом Locality
/// \brief Класс Населённый пункт
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#pragma once
#include <iostream> // ввод-вывод
#include <string> // для работы со строками
// теперь можно обращаться ко всем именам, описанным в std, непосредственно, без префикса std::
using namespace std;

class Locality
{
protected:
	string name; // имя населенного пункта
	string power; // власть
	int population;	// численность населения
public:
	// перечислимый тип видов (город, поселок, деревня)
	// До 1000 человек – деревня, до 30 000 человек – посёлок, более 30 000 – город
	enum LocType { City, City_Village, Village, Other};
	LocType type; // переменная типа класса LocType
	Locality (string Locality_name = "-", string Locality_power = "-", int Locality_population = 0);

	string get_name () const;
	void set_name (string new_name);

	string get_power () const;
	void set_power (string new_power);

	int get_population () const;
	void set_population (int set_population);

	string live() const;
	string live(int number_of_population) const;
	///string work() const;
	string walk() const;
	virtual string work() const;

	// полиморфный вывод полей класса Locality, применим к наследуемым классам
	virtual void Output() const;
};

