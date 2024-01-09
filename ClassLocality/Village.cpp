/// \file Village.cpp
/// \brief cpp-файл модуль Village.cpp с наследником класса Locality
/// \brief Класс Деревня
/// \author Бурдинская Наталья ВМК-22
/// \date 15.12.2023

#include "Village.h" // Заголовочный файл с наследником класса Locality
#include <iostream> // ввод-вывод
#include <cassert> // для assert

//Конструктор с параметрами
LocVillage::LocVillage(string Loc_name, int Loc_population, LocType Loc_type, string Loc_power, string Loc_info, int Loc_house, string Loc_occupation, string Loc_leisure, string Loc_ecology)
: Locality(Loc_name, Loc_population, Loc_type, Loc_power, Loc_info)
{
	set_house(Loc_house);
	set_occupation(Loc_occupation);
	set_leisure(Loc_leisure);
	ecology = Loc_ecology;
}

// сеттер и геттер для этажности дома
void LocVillage::set_house(int new_house) {
	house = new_house;
}
int LocVillage::get_house() const {
	return house;
}

// сеттер и геттер для занятости населения
void LocVillage::set_occupation(string new_occupation) {
	occupation = new_occupation;
}
std::string LocVillage::get_occupation() const {
	return occupation;
}

// сеттер и геттер для досуга населения
void LocVillage::set_leisure(string new_leisure) {
	leisure = new_leisure;
}
string LocVillage::get_leisure() const {
	return leisure;
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
	return "Деревня " + name + ": - население " + to_string(get_population()) + " человек, тип - " + get_type() + ", орган власти - " 
		+ power + ", дополнительная информация - " + info + ", люди занимаются - " + get_occupation() + ", экология - " + ecology + ".";
}

// вывод полей класса LocVillage
void LocVillage::Output() const {
	string ss = "Другое";
	if (type == 0) { ss = "Город"; }
	if (type == 1) { ss = "Деревня"; }
	string sss = "нет";
	if (house > 2) { sss = "много -"; }
	if (house < 3) { sss = "одно-двух"; }
	cout << "----------------------------" << endl;
	cout << " ДЕРЕВНЯ ___________________  " << endl;
	cout << " Наименование              :  " << name << endl;
	cout << " Численность населения     :  " << population << " человек" << endl;
	cout << " Тип населенного пункта    :  " << ss << endl;
	cout << " Орган власти              :  " << power << endl;
	cout << " Дополнительная информация :  " << info << endl;
	cout << " Жилые дома                :  " << sss << " этажный дом" << endl;
	cout << " Занятость населения       :  " << occupation << endl;
	cout << " Досуг и отдых             :  " << leisure << endl;
	cout << " Экология                  :  " << ecology << endl;
	cout << "----------------------------" << endl;
}

// проверка работы класса LocVillage
void test_Village() {
	cout << "Тестирование класса LocVillage:" << endl;
	LocVillage Test3("Новотроицк", 500, Деревня, "Новотроицкий сельсовет", "Новотроицк селение Забайкальского края", 1,
		       "сельское хозяйство", "сельский клуб и библиотека", "чистый воздух, чистая вода, натуральные продукты");
	cout << Test3.Loc_to_string() << endl;
	assert(Test3.Loc_to_string() == "Деревня Новотроицк: - население 500 человек, тип - Деревня, орган власти - Новотроицкий сельсовет, дополнительная информация - Новотроицк селение Забайкальского края, люди занимаются - сельское хозяйство, экология - чистый воздух, чистая вода, натуральные продукты.");
	cout << "Тестирование класса 'LocVillage' выполнено УСПЕШНО" << endl;
}
