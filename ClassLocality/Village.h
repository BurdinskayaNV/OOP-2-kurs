/// \file Village.h
/// \brief Заголовочный файл модуля Village.cpp с наследником класса Locality
/// \brief Класс Деревня
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#pragma once
#include "Locality.h" // Заголовочный файл с классом Locality
#include <string> // для работы со строками

#ifndef LOCVILLAGE_H
#define LOCVILLAGE_H

// класс LocVillage
class LocVillage :	public Locality {
private:
	// поля наследники
	int house; // жилье - этажность дома, 1 - одноэтажные, больше 1 - многоэтажные
	string occupation; // занятия населения
	string leisure; // досуг населения
public:
	string ecology; // экология

	// конструктор класса город
	LocVillage(string Loc_name = "Locality", int Loc_population = 0, LocType type = Другое, string Loc_power = "-", string Loc_info = "-",
		int Loc_house = 0, string Loc_occupation = "-", string Loc_leisure = "-", string ecology = "-");
		
	// сеттер и геттер для этажности дома
	void set_house(int new_house);
	int get_house() const;

	// сеттер и геттер для занятости населения
	void set_occupation(string new_occupation);
	string get_occupation() const;

	// сеттер и геттер для досуга населения
	void set_leisure(string new_leisure);
	string get_leisure() const;

	// люди живут в каких домах
	string live() const override;

	// люди где работают
	string work() const override;

	// люди где проводят досуг
	string walk() const override;

	// экология
	string eco() const;

	// преобразование в строку
	string Loc_to_string() const override;

	//вывод полей класса LocVillage
	void Output() const override;
};

// Проверка работы класса LocVillage
void test_Village();

#endif
