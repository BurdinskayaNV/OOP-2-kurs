/// \file Village.h
/// \brief Заголовочный файл модуля Village.cpp
/// \brief Класс Деревня
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#pragma once
#include "Locality.h"
class Village :
	public Locality
{
public:
	Village(std::string Village_name, std::string Village_population, int Village_home);
	std::string live();
	std::string work();
	std::string walk() override;
};
