/// \file City.cpp
/// \brief cpp-���� ������ City.cpp
/// \brief ����� �����
/// \author ���������� ������� ���-22
/// \date 15.12.2023

#include "City.h"

City::City(std::string City_name, std::string City_population, int City_home) {
	name = City_name;
	population = City_population;
	home = City_home; // 2 - ������� ���, > 2 - ��������������� ���
}
std::string City::work() const {
	return name + " work on zavod";
}

std::string City::walk() const {
	return name + " walk in Museum";
}