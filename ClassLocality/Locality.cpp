/// \file Locality.cpp
/// \brief cpp-файл модуль Locality.cpp
/// \brief Класс Населённый пункт
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Locality.h"

// Класс 
Locality::Locality(std::string Locality_name, std::string Locality_population, int Locality_home) {
	name = Locality_name;
	population = Locality_population;
	home = Locality_home; // 2 - частный дом, > 2 - многоквартирный дом
}

void Locality::set_name(std::string new_name) {
	if (new_name != "")
		name = new_name;
	else throw std::invalid_argument("Impossible Locality name");
}

std::string Locality::get_name() {
	return name;
}

void Locality::set_population(std::string new_population) {
	if (new_population != "")
		population = new_population;
	else throw std::invalid_argument("Impossible Locality population");
}

std::string Locality::get_population() {
	return population;
}

void Locality::set_home(int new_home) {
	if (new_home >= 2)
		home = new_home;
	else throw std::invalid_argument("Impossible Locality home");
}

int Locality::get_home() {
	return home;
}

std::string Locality::live() {
	return name + ": population ";
}

std::string Locality::live(int number_of_population) {
	if (number_of_population < 50000) {
		std::string s = name + ": - ";
		s = s + " small_population";
		return s;
	}
	else return name + ": - " + " large_population";
}

std::string Locality::work() {
	return name + " work people";
}

std::string Locality::walk() {
	return name + " walk people";
}
