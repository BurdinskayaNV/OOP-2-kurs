/// \file City.cpp
/// \brief cpp-файл модуль City.cpp с наследником класса Locality
/// \brief Класс Город
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "City.h" // Заголовочный файл с наследником класса Locality
#include "Locality.h" // Заголовочный файл с классом Locality

City::City (string City_name, int City_population, string City_TypeLoc, int City_house) {
	name = City_name; // наименование города
	population = City_population; // численность населения
	TypeLoc = City_TypeLoc; // тип населенного пункта
	House = City_house; // жилье - дом, 1 - одноэтажные, больше 1 - многоэтажные
}
string City::stone_houses() const {
	// дома кирпичные и панельные.
	return name + " - the houses are brick and panel.";
}

string City::floors() const {
	// дома и сооружения здесь многоэтажные.
	return name + " - the houses and buildings are multi-storey.";
}

string City::work() const {
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

void City::Output() const {
	string s1 = stone_houses();
	string s2 = floors();
	string s3 = work();
	cout << endl;
	cout << " City         " << endl;
	cout << " Name       : " << name << endl;
	cout << " Population : " << population << endl;
	cout << " TypeLoc    : " << TypeLoc << endl;
	cout << " House      : " << s1 << endl;
	cout << " Floors     : " << s2 << endl;
	cout << " Work       : " << s3 << endl;
	cout << endl;
}
