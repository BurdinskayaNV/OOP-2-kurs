/// \file Locality.h
/// \brief Заголовочный файл модуля Locality.cpp
/// \brief Класс Населённый пункт
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#pragma once
#include <iostream>
#include <cstring>

class Locality
{
protected:
	std::string name;
	std::string population;
	int home;
public:
	Locality(std::string Locality_name = "-", std::string Locality_population = "-", int Locality_home = 0);

	void set_name(std::string new_name);
	std::string get_name();

	void set_population(std::string new_population);
	std::string get_population();

	void set_home(int set_home);
	int get_home();

	std::string live();
	std::string live(int number_of_population);
	std::string work();

	virtual std::string walk();
};
