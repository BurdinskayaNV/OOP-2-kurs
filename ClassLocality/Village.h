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
	string ecology; // экология
public:
	// конструктор класса город
	LocVillage(string Loc_name = "Locality", int Loc_population = 0, string Loc_power = "-", int Loc_house = 0, 
		       string Loc_occupation = "-", string Loc_leisure = "-", string Loc_info = "-", string ecology = "-");
	
	// сеттер и геттер для экологии
	void set_ecology(string new_ecology);
	string get_ecology() const;
	
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

	//вывод полей класса LocVillage в таблицу
	void Output() const override;
};

// Проверка работы класса LocVillage
void test_Village();

#endif

