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

#ifndef LOCALITY_H
#define LOCALITY_H

// Специальный тип для указания населенного пункта
// перечисляемый тип видов (город, поселок, деревня, другое)
// До 1000 человек – деревня, до 30 000 человек – посёлок, более 30 000 – город
// enum LocType { Город, Деревня, Другое };  //** убрать

// Класс, хранящий информацию о населенном пункте Locality
// 4 обязательных характеристик населенного пункта - 
// имя, тип (по административному статусу: городской и сельский), численность населения, органы власти
class Locality
{
protected:
	int population;	// численность населения
	string power; // власть
public:
	string name; // имя населенного пункта
	int house; // жилье - этажность дома, 1 - одноэтажные, 2 - двухэтажные, больше 2 - многоэтажные
	string occupation; // занятия населения
	string leisure; // досуг населения
	string info; // дополнительная информация

	// Методы
	// Конструктор с параметрами
	Locality(string Loc_name = "Locality", int Loc_population = 0, string Loc_power = "-",
		     int Loc_house = 0, string Loc_occupation = "-", string Loc_leisure = "-", string Loc_info = "-");

	// сеттер и геттер для численности населения
	void set_population(int new_population);
	int get_population() const;

	// сеттер и геттер для органов власти
	void set_power(string new_power);
	string get_power() const;

	// в населенном пункте живут
	virtual string live() const;

	// в населенном пункте работают
	virtual string work() const;

	// в населенном пункте досуг - гуляют посещают
	virtual string walk() const;

	// преобразование в строку
	virtual string Loc_to_string() const;

	// вывод полей класса Locality в таблицу
	virtual void Output() const;
};

// проверка работы класса Locality
void test_Locality();

#endif


