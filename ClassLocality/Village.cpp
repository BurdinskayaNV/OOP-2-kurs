/// \file Village.cpp
/// \brief cpp-файл модуль Village.cpp с наследником класса Locality
/// \brief Класс Деревня
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Village.h" // Заголовочный файл с наследником класса Locality
#include "Locality.h" // Заголовочный файл с классом Locality

Village::Village (string Village_name, int Village_population, string Village_TypeLoc, int Village_house) {
	name = Village_name; // наименование города
	population = Village_population; // численность населения
	TypeLoc = Village_TypeLoc; // тип населенного пункта
	House = Village_house; // жилье - дом, 1 - одноэтажные, больше 1 - многоэтажные
}

string Village::wooden_houses() const {
	return name + " - the houses are brick and wooden.";
}

string Village::floors() const {
	return name + " - the houses and buildings are single-storey.";
}

string Village::work() const {
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

void Village::Output() const {
	string s1 = wooden_houses();
	string s2 = floors();
	string s3 = work();
	cout << endl;
	cout << " Village      " << endl;
	cout << " Name       : " << name << endl;
	cout << " Population : " << population << endl;
	cout << " TypeLoc    : " << TypeLoc << endl;
	cout << " House      : " << s1 << endl;
	cout << " Floors     : " << s2 << endl;
	cout << " Work       : " << s3 << endl;
	cout << endl;
}
