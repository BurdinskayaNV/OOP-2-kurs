/// \file Locality.cpp 
/// \brief cpp-файл модуль Locality.cpp с классом Locality
/// \brief Класс Населённый пункт
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Locality.h" // Заголовочный файл с классом Locality
#include <stdexcept> // используемых для сообщения об исключениях exception
#include <iostream> // ввод-вывод
#include <cassert> // для assert

// Класс Населенный пункт
// Конструктор с параметрами
Locality::Locality(string Loc_name, int Loc_population, LocType Loc_type, string Loc_power, string Loc_info) {
	name = Loc_name; // имя населенного пункта
	set_population(Loc_population); // численность населения
	set_type(Loc_type); // тип населенного пункта
	power = Loc_power; // органы власти
	info = Loc_info; // особая информация
}

// сеттер и геттер для численности населения
void Locality::set_population(int new_population) {
	if (new_population != 0)
		population = new_population;
	else throw invalid_argument("Недействительный аргумент population");
}
int Locality::get_population() const {
	return population;
}

// сеттер и геттер для типа населенного пункта
void Locality::set_type(LocType new_type) {
	if ((new_type == 0) || (new_type == 1) || (new_type == 2) || (new_type == 3))
		type = new_type;
	else throw invalid_argument("Недействительный аргумент LocType");
}
string Locality::get_type() const {
	if (type == 0)
	{
		return "Город";
	}
	if (type == 1)
	{
		return "Деревня";
	}
	return "Другое";
}

// в населенном пункте живут
string Locality::live() const {
	string ss = "Другое";
	if (type == 0) { ss = "Город"; }
	if (type == 1) { ss = "Деревня"; }
	return "В населенном пункте " + name + ": - население " + to_string(population) + " человек, что соответствует типу " + ss + ".";
}

// в населенном пункте работают, занимаются
string Locality::work () const {
	return "В населенном пункте " + name + " люди работают согласно их социальному статусу и территориальному положению.";
}

// в населенном пункте досуг - гуляют, посещают
string Locality::walk() const {
	return "В населенном пункте " + name + " люди занимаются досугом согласно его типу и характеристикам.";
}

// преобразование в строку
string Locality::Loc_to_string() const {
	return "Населенный пункт " + name + ": - население " + to_string(get_population()) + " человек, тип - " + get_type() 
		+ ", орган власти - " + power + ", дополнительная информация - " + info + ".";
}

// вывод полей класса Locality
void Locality::Output() const {
	string ss = "Другое";
	if (type == 0)	{ ss = "Город"; }
	if (type == 1)	{ ss = "Деревня"; }
	cout << "----------------------------" << endl;
	cout << " НАСЕЛЕННЫЙ ПУНКТ __________  " << endl;
	cout << " Наименование              :  " << name << endl;
	cout << " Численность населения     :  " << population << " человек" << endl;
	cout << " Тип населенного пункта    :  " << ss << endl;
	cout << " Орган власти              :  " << power << endl;
	cout << " Дополнительная информация :  " << info << endl;
	cout << "----------------------------" << endl;
}

// проверка работы класса Locality
void test_Locality() {
	cout << "Тестирование класса Locality:" << endl;
	Locality Test1("Чита", 500, Деревня, "Органы местного самоуправления", "Особенности населенных пунктов зависят от их размера и типа");
	assert(Test1.get_population() == 500);
	assert(Test1.get_type() == "Деревня");

	Test1.set_population(333679);
	Test1.set_type(Город);
	cout << Test1.Loc_to_string() << endl;
	assert(Test1.Loc_to_string() == "Населенный пункт Чита: - население 333679 человек, тип - Город, орган власти - Органы местного самоуправления, дополнительная информация - Особенности населенных пунктов зависят от их размера и типа.");

	cout << "Тестирование класса 'Locality' выполнено УСПЕШНО" << endl;
}
