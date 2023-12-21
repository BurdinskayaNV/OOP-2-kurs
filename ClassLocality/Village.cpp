// \file Village.cpp
/// \brief cpp-файл модуль Village.cpp
/// \brief Класс Деревня
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Village.h"

Village::Village(std::string Village_name, std::string Village_population, int Village_home) {
	name = Village_name;
	population = Village_population;
	home = Village_home;
}

std::string Village::live() {
	return name + " live in Village ";
}

std::string Village::work() {
	return name + " work in pole ";
}
