/// \file Village.cpp
/// \brief cpp-файл модуль Village.cpp с наследником класса Locality
/// \brief Класс Деревня
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Village.h" // Заголовочный файл с наследником класса Locality
#include <iostream> // ввод-вывод
#include <cassert> // для assert  string Loc_info,

//Конструктор с параметрами
LocVillage::LocVillage(string Loc_name, int Loc_population, string Loc_power, int Loc_house, string Loc_occupation, string Loc_leisure, string Loc_info, string Loc_ecology)
	: Locality(Loc_name, Loc_population, Loc_power, Loc_house, Loc_occupation, Loc_leisure, Loc_info), ecology(Loc_ecology) {};

// сеттер и геттер для экологии
void LocVillage::set_ecology(string new_ecology) {
	if (new_ecology != "")
		ecology = new_ecology;
	else throw std::invalid_argument("Недействительный аргумент ecology");
}
string LocVillage::get_ecology() const {
	return ecology;
}

// люди живут в каких домах
string LocVillage::live() const {
	string ss = "нет";
	if (house > 2) { ss = "много -"; }
	if (house < 3) { ss = "одно-двух"; }
	return "В деревне " + name + " люди живут в деревянных " + ss + " этажных домах.";
}

// люди где работают
string LocVillage::work() const {
	return "В деревне " + name + " люди заняты в сфере " + occupation + ".";
}

// люди где проводят досуг
string LocVillage::walk() const {
	return "В деревне " + name + " люди гуляют по лесу, посещают " + leisure + ".";
}

// экология
string LocVillage::eco() const {
	return "В деревне " + name + " экологически " + ecology + ".";
}

// преобразование в строку
string LocVillage::Loc_to_string() const {
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
	return "Деревня " + name + ": - население " + to_string(get_population()) + " человек, тип - " + ss + ", орган власти - " 
		+ power + ", дополнительная информация - " + info + ", люди занимаются - " + occupation + ", экология - " + ecology + ".";
}

// вывод полей класса LocVillage в таблицу
void LocVillage::Output() const {
	string ss = "Другое";
	if (population > 30000) { ss = "Город"; }
	if (population <= 30000) { ss = "Деревня"; }
	string sss = "нет";
	if (house > 2) { sss = "много -"; }
	if (house < 3) { sss = "одно-двух"; }
	cout << "----------------------------" << endl;
	cout << " ДЕРЕВНЯ ___________________  " << endl;
	cout << " Наименование              :  " << name << endl;
	cout << " Численность населения     :  " << population << " человек" << endl;
	cout << " Тип населенного пункта    :  " << ss << endl;
	cout << " Орган власти              :  " << power << endl;
	cout << " Жилые дома                :  " << sss << " этажный дом" << endl;
	cout << " Занятость населения       :  " << occupation << endl;
	cout << " Досуг и отдых             :  " << leisure << endl;
	cout << " Дополнительная информация :  " << info << endl;
	cout << " Экология                  :  " << ecology << endl;
	cout << "----------------------------" << endl;
}

// проверка работы класса LocVillage
void test_Village() {
	cout << "Тестирование класса LocVillage:" << endl;
	LocVillage Test3("Новотроицк", 500, "Новотроицкий сельсовет", 1, "сельское хозяйство", "сельский клуб и библиотека",
		       "Новотроицк селение Забайкальского края", "чистый воздух, чистая вода, натуральные продукты");
	Test3.live();
	Test3.work();
	Test3.walk();
	cout << Test3.Loc_to_string() << endl;
	assert(Test3.Loc_to_string() == "Деревня Новотроицк: - население 500 человек, тип - Деревня, орган власти - Новотроицкий сельсовет, дополнительная информация - Новотроицк селение Забайкальского края, люди занимаются - сельское хозяйство, экология - чистый воздух, чистая вода, натуральные продукты.");
	cout << "Тестирование класса 'LocVillage' выполнено УСПЕШНО" << endl;
}
