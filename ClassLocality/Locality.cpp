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
Locality::Locality(string Loc_name, int Loc_population, string Loc_power,
  int Loc_house, string Loc_occupation, string Loc_leisure, string Loc_info) {
	name = Loc_name; // имя населенного пункта
	set_population(Loc_population); // численность населения
	set_power(Loc_power); // органы власти
	house = Loc_house; // жилье - этажность дома, 1 - одноэтажные, больше 1 - многоэтажные
	occupation = Loc_occupation; // занятия населения
	leisure = Loc_leisure; // досуг населения
	info = Loc_info; // особая информация
}

// сеттер и геттер для численности населения
void Locality::set_population(int new_population) { //*** проверка
	if (new_population < 0) throw std::invalid_argument("Численность населения не может быть отрицательной");
	population = new_population;
 }
int Locality::get_population() const {
	return population;
}

// сеттер и геттер для органов власти
void Locality::set_power(string new_power) {
	if (new_power != "")
		power = new_power;
	else throw std::invalid_argument("Недействительный аргумент power");
}
string Locality::get_power() const {
	return power;
}

// в населенном пункте живут
string Locality::live() const {
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
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
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
	return "Населенный пункт " + name + ": - население " + to_string(get_population()) + " человек, тип - " + ss 
		+ ", орган власти - " + power + ", дополнительная информация - " + info + ".";
}

// вывод полей класса Locality в таблицу
void Locality::Output() const {
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
	string sss = "нет";
	if (house > 2) { sss = "много -"; }
	if (house < 3) { sss = "одно-двух"; }
	cout << "----------------------------" << endl;
	cout << " НАСЕЛЕННЫЙ ПУНКТ __________  " << endl;
	cout << " Наименование              :  " << name << endl;
	cout << " Численность населения     :  " << population << " человек" << endl;
	cout << " Тип населенного пункта    :  " << ss << endl;
	cout << " Орган власти              :  " << power << endl;
	cout << " Жилые дома                :  " << sss << " этажный дом" << endl;
	cout << " Занятость населения       :  " << occupation << endl;
	cout << " Досуг и отдых             :  " << leisure << endl;
	cout << " Дополнительная информация :  " << info << endl;
	cout << "----------------------------" << endl;
}

// проверка работы класса Locality
void test_Locality() {
	cout << "Тестирование класса Locality:" << endl;
	Locality Test1("Чита", 500, "Органы местного самоуправления", 10, "промышленность", "музеи, торговые центры, театры и кино",
		           "Особенности населенных пунктов зависят от их размера и типа");
	assert(Test1.get_population() == 500);
	assert(Test1.get_power() == "Органы местного самоуправления");

	Test1.live();
	Test1.work();
	Test1.walk();

	Test1.set_population(333679);
	Test1.set_power("Органы местного самоуправления");
	cout << Test1.Loc_to_string() << endl;
	assert(Test1.Loc_to_string() == "Населенный пункт Чита: - население 333679 человек, тип - Город, орган власти - Органы местного самоуправления, дополнительная информация - Особенности населенных пунктов зависят от их размера и типа.");

	cout << "Тестирование класса 'Locality' выполнено УСПЕШНО" << endl;
}
