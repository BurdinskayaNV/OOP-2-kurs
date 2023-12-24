/// \file Locality.cpp 
/// \brief cpp-файл модуль Locality.cpp с классом Locality
/// \brief Класс Населённый пункт
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Locality.h" // Заголовочный файл с классом Locality
#include "City.h"
#include "Village.h"

// Класс Населенный пункт
Locality::Locality(string Locality_name, string Locality_power, int Locality_population) {
	name = Locality_name; // имя населенного пункта
	power = Locality_power; // власть
	population = Locality_population; // численность населения
}

string Locality::get_name() const {
	return name;
}

void Locality::set_name(string new_name) {
	if (new_name != "")
		name = new_name;
	else throw std::invalid_argument("Impossible Locality name");
}

string Locality::get_power() const {
	return power;
}

void Locality::set_power(string new_power) {
	if (new_power != "")
		power = new_power;
	else throw std::invalid_argument("Impossible Locality name");
}

int Locality::get_population() const {
	return population;
}

void Locality::set_population(int new_population) {
	if (new_population != 0)
		population = new_population;
	else throw std::invalid_argument("Impossible Locality population");
}

string Locality::live() const {
	return name + ": - population " + to_string (population) + " mans ";
}

// До 1000 человек – деревня, до 30 000 человек – посёлок, более 30 000 – город
string Locality::live (int number_of_population) const {
	string Okey = "Other"; 
	if (number_of_population <= 1000)
	{
		LocType type = LocType::Village; // деревня    
		Okey = "Village";
	}
	if ((number_of_population > 1000) && (number_of_population <= 30000))
	{
		LocType type = LocType::City_Village; // поселок городского типа
		Okey = "City_Village";
	}
	if (number_of_population > 30000)
	{
		LocType type = LocType::City; // город
		Okey = "City";
	}
	if (Okey == "Other")
	{
		LocType type = LocType::Other; // другой
	}
	string s = name + ": - ";
	s = s +  Okey + ", population " + to_string (number_of_population) + " mans, " + " management bodies : " + power;
	
	return s;
}

string Locality::work () const {
	string ss = "  Other"; // разбиваем перечислимый тип на строки
	if (population > 30000)
		// Люди работают в больницах, школах, на предприятиях и в торговых центрах.
		ss = ": - City. People work in hospitals, schools, businesses, and shopping malls.";

	if ((population > 1000) && (population <= 30000))
        // Люди работают в медицинских центрах, школах, магазинах, занимаются сельским хозяйством.
		ss = ": - City_Village. People work in medical centers, schools, shops, and are engaged in agriculture.";

	if (population <= 1000)
		// Люди занимаются сельским хозяйством.
		ss = ": - Village. People are engaged in agriculture.";

	if (ss == "  Other")
		// Неопределенное место для работы.
		ss = ": - Other. An undefined place to work.";

	return name + ss;
}

string Locality::walk() const {
	string ss = "  Other"; // разбиваем перечислимый тип на строки
	if (population > 30000)
		// Люди гуляют в парках, ходят в кино, музеи, рестораны
		ss = ": - City. People walk in parks, go to the cinema, museums, restaurants.";

	if ((population > 1000) && (population <= 30000))
		// Люди гуляют по улицам, в лесах, ходят в клубы.
		ss = ": - City_Village. People walk the streets, in the woods, go to clubs.";

	if (population <= 1000)
		// Люди гуляют по лесу, купаются в водоемах.
		ss = ": - Village. People walk in the woods, swim in reservoirs.";

	if (ss == "  Other")
		// Неопределенное место для прогулок.
	    ss = ": - Other. An undefined place to walk.";

	return name + ss;
}

void Locality::Output() const {
	cout << endl;
	cout << " Locality  " << endl;
	cout << " Name       : " << name << endl;
	cout << " Power      : " << power << endl;
	cout << " Population : " << population << endl;
	cout << endl;
}
