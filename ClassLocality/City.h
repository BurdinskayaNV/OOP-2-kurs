/// \file City.h
/// \brief Заголовочный файл модуля City.cpp с наследником класса Locality
/// \brief Класс Город
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#pragma once
#include "Locality.h" // Заголовочный файл с классом Locality
#include "Locality.h"
// класс город
class City : public Locality {
private:
	string name; // имя населенного пункта
	int population; // численность населения
	string TypeLoc; // тип населенного пункта
	int House; // жилье - дом, 1 - одноэтажные, больше 1 - многоэтажные
public:
	// конструктор класса город
	City (string name = "-", int population = 0, string TypeLoc = "Other", int House = 0);
	string stone_houses () const;
	string floors () const;
	
	string work() const override;

	//вывод полей класса Locality
	void Output() const override;
};
