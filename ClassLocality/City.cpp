/// \file City.cpp
/// \brief cpp-файл модуль City.cpp с наследником класса Locality
/// \brief Класс Город
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "City.h" // Заголовочный файл с наследником класса Locality
#include <iostream> // ввод-вывод
#include <cassert> // для assert

//Конструктор с параметрами
LocCity::LocCity(string Loc_name, int Loc_population, string Loc_power, int Loc_house, string Loc_occupation, string Loc_leisure, string Loc_info, string Loc_Infrastructure)
	: Locality(Loc_name, Loc_population, Loc_power, Loc_house, Loc_occupation, Loc_leisure, Loc_info), Infrastructure (Loc_Infrastructure) {};

// сеттер и геттер для Инфраструктура 
void LocCity::set_Infrastructure(string new_Infrastructure) {
	if (new_Infrastructure != "")
		Infrastructure = new_Infrastructure;
	else throw std::invalid_argument("Недействительный аргумент Infrastructure");
}
string LocCity::get_Infrastructure() const {
	return Infrastructure;
}

// люди живут в каких домах
string LocCity::live() const {
	string ss = "нет";
	if (house > 2) { ss = "много -"; }
	if (house < 3) { ss = "одно-двух"; }
	return "В городе " + name + " люди живут в кирпичных " + ss + " этажных домах.";
}

// люди где работают
string LocCity::work() const {
	return "В городе " + name + " люди заняты в сфере " + occupation + ".";
}

// люди где проводят досуг
string LocCity::walk() const {
	return "В городе " + name + " люди гуляют в парках, посещают " + leisure + ".";
}

// инфраструктура и коммуникации
string LocCity::infr() const {
	return "В городе " + name + " " + Infrastructure + ".";
}

// преобразование в строку
string LocCity::Loc_to_string() const {
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
	return "Город " + name + ": - население " + to_string(get_population()) + " человек, тип - " + ss
		+ ", орган власти - " + power + ", дополнительная информация - " + info + ", люди занимаются - " + occupation
		+ ", инфраструктура - " + Infrastructure + ".";
}

// вывод полей класса LocCity в таблицу
void LocCity::Output() const {
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
	string sss = "нет";
	if (house > 2) { sss = "много -"; }
	if (house < 3) { sss = "одно-двух"; }
	cout << "----------------------------" << endl;
	cout << " ГОРОД _____________________  " << endl;
	cout << " Наименование              :  " << name << endl;
	cout << " Численность населения     :  " << population << " человек" << endl;
	cout << " Тип населенного пункта    :  " << ss << endl;
	cout << " Орган власти              :  " << power << endl;
	cout << " Жилые дома                :  " << sss << " этажный дом" << endl;
	cout << " Занятость населения       :  " << occupation << endl;
	cout << " Досуг и отдых             :  " << leisure << endl;
	cout << " Дополнительная информация :  " << info << endl;
	cout << " Инфраструктура            :  " << Infrastructure << endl;
	cout << "----------------------------" << endl;
}

// проверка работы класса LocCity
void test_City() {
	cout << "Тестирование класса LocCity:" << endl;
	LocCity Test2("Омск", 1110836, "Администрпция города Омск", 10, "промышленность", "музеи, торговые центры, театры и кино",
		"Омск крупный город", "сильно развитые централизованные энергетическая система, водоснабжение, канализация и системы отопления");
	Test2.live();
	Test2.work();
	Test2.walk();
	cout << Test2.Loc_to_string() << endl;
	assert(Test2.Loc_to_string() == "Город Омск: - население 1110836 человек, тип - Город, орган власти - Администрпция города Омск, дополнительная информация - Омск крупный город, люди занимаются - промышленность, инфраструктура - сильно развитые централизованные энергетическая система, водоснабжение, канализация и системы отопления.");
	cout << "Тестирование класса 'LocCity' выполнено УСПЕШНО" << endl;
}
