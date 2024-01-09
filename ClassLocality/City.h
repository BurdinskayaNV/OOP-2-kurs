/// \file City.h
/// \brief Заголовочный файл модуля City.cpp с наследником класса Locality
/// \brief Класс Город
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#pragma once
#include "Locality.h" // Заголовочный файл с классом Locality
#include <string> // для работы со строками

#ifndef LOCCITY_H
#define LOCCITY_H

// класс LocCity
class LocCity : public Locality {
public:
	// поля наследники
	int house; // жилье - этажность дома, 1 - одноэтажные, больше 1 - многоэтажные
	string occupation; // занятия населения
	string leisure; // досуг населения
	string Infrastructure; // Инфраструктура и коммуникации

	// Конструктор с параметрами
	LocCity(string Loc_name = "Locality", int Loc_population = 0, LocType Loc_type = Другое, string Loc_power = "-",
		    string Loc_info = "-", int Loc_house = 0, string Loc_occupation = "-", string Loc_leisure = "-", string Loc_Infrastructure = "-");

	// люди живут в каких домах
	string live() const override;

	// люди где работают
	string work() const override;
	
	// люди где проводят досуг
	string walk() const override;

	// инфраструктура и коммуникации
	string infr() const;

	// преобразование в строку
	string Loc_to_string() const override;

	//вывод полей класса LocCity
	void Output() const override;
};

// Проверка работы класса LocCity
void test_City();

#endif
