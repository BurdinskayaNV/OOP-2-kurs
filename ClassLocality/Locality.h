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
enum LocType { Город, Деревня, Другое };

// Класс, хранящий информацию о населенном пункте Locality
// 4 обязательных характеристик населенного пункта - 
// имя, тип (по административному статусу: городской и сельский), численность населения, органы власти
class Locality
{
protected:
	int population;	// численность населения
	LocType type; // переменная типа класса LocType
public:
	string name; // имя населенного пункта
	string power; // власть
	string info; // дополнительная информация

	// Методы
	// Конструктор с параметрами
	Locality(string Loc_name = "Locality", int Loc_population = 0, LocType Loc_type = Другое, string Loc_power = "-", string Loc_info = "-");

	// сеттер и геттер для численности населения
	void set_population(int new_population);
	int get_population() const;

	// сеттер и геттер для типа населенного пункта
	void set_type(LocType new_type);
	string get_type() const;

	// в населенном пункте живут
	virtual string live() const;

	// в населенном пункте работают
	virtual string work() const;

	// в населенном пункте досуг - гуляют посещают
	virtual string walk() const;

	// преобразование в строку
	virtual string Loc_to_string() const;

	// вывод полей класса Locality
	virtual void Output() const;
};

// проверка работы класса Locality
void test_Locality();

#endif

