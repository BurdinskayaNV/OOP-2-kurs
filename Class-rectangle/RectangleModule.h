/// \file RectangleModule.h
/// \brief Заголовочный файл модуля RectangleModule.cpp
/// \brief Класс прямоугольник
/// \author Бурдинская Наталья ВМК-22
/// \date 01.11.2023

#pragma once
//Объявляет cin cout, управляющие чтением из станд.потоков и записью в них
#include <iostream>
// работа с файлами
#include <fstream>
// определяет функцию setlocale для установки русской локали и выводить сообщение на русском языке.
#include <locale>
#include <cmath>  // модуль с математическими константами и функциями
#include <cassert> // для assert
#include <iomanip> // стандартный для определения нужного числа манипуляторов setw setprecision.
#include <string> // для работы со строками
// теперь можно обращаться ко всем именам, описанным в std, непосредственно, без префикса std::
using namespace std;

// Класс - прямоугольник Rectangle
class RectangleClass {
private:
	// поля класса:
	double x1, y1; // координаты x и y первой точки
	double x2, y2; // координаты x и y второй точки
	double x3, y3; // координаты x и y третьей точки
public:
	// Методы класса:
	// double a, b; // стороны прямоугольника
	// double d; // диагональ прямоугольника
	// double angle_a; // угол прямоугольника
	// double x4, y4; // координаты x и y четвертой точки

	// перечислимый тип видов (квадрат, прямоугольник, другое)
	enum RecType { Sqare, Rectangle, Other };
	RecType type; // переменная типа класса RecType
	// Конструктор прямоугольника
	RectangleClass();
	// Конструктор с заданием координат вершин
	RectangleClass(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_);
	// геттеры координаты x и y i-ой точки прямоугольника
	// (Операция: Прочитать x и y i-ой точки (i=1,2,3) прямоугольника)
	// (const т.к. метод не меняет значений полей)
	double get_x1() const; double get_y1() const; // i=1
	double get_x2() const; double get_y2() const; // i=2  															
	double get_x3() const; double get_y3() const; // i=3
	// сеттеры координаты x и y i-ой точки прямоугольника
	// (Операция: Ввод x и y i-ой точки (i=1,2,3) прямоугольника)
	void set_x1(double x_1); void set_y1(double y_1); // i=1
	void set_x2(double x_2); void set_y2(double y_2); // i=2 
	void set_x3(double x_3); void set_y3(double y_3); // i=3 

	// (const т.к. метод не меняет значений полей) контроль постоянства

	// Операция: Нахождение длины стороны A прямоугольника
	double SideRectangleA() const;
	// Операция: Нахождение длины стороны B прямоугольника
	double SideRectangleB() const;

	// Операция: Нахождение косинуса угла прямоугольника cos90=0
	double AngleRectangle() const;
	// Операция: Нахождение длины диагонали прямоугольника
	double DiagonalRectangle() const;
	// Операция: Нахождение координаты X четвертой точки прямоугольника
	double СoordinateX4() const;
	// Операция: Нахождение координаты Y четвертой точки прямоугольника
	double СoordinateY4() const;

	// Операция: Расчет периметра P прямоугольника через длины сторон
	double PerimeterAB() const;
	// Операция: Расчет площади S прямоугольника через длины сторон
	double SquareAB() const;
	// Операция: Расчет периметра P прямоугольника через координаты точек
	double PerimeterXY() const;
	// Операция: Расчет площади S прямоугольника через координаты точек
	double SquareXY() const;
	// Операция: Определить вид прямоугольника
	void RectangleType();
	// Операция: Вывод результатов - метод to string
	string RefundResults() const;
};
//---проверка работы кода функций с классом RectangleClass
// в саму процедуру нет вход¤щих параметров
// Пример 1 - прямоугольник 
// Создать объект Test класса RectangleClass с координатами (1,1) (4,1) (1,3)
// Вычислить длины и углы сторон A и B, диагональ D,
// координаты 4-ой точки, периметр и площадь прямоугольника
// Затем поменять координаты на (1,1) (3,2) (0,3)
// Вычислить координаты 4-ой точки, площадь и периметр
void Test_RectangleClass1();
// Пример 2 - прямоугольник статистический массив
// Создать массив 3 объектов Test класса RectangleClass с различными координатами
// Найти сумму периметров прямоугольников и квадратов
void Test_RectangleClass2();
// Пример 3 - прямоугольник динамический массив по умолчанию
// Создать массив TestМ класса RectangleClass 
// Найти площадь прямоугольника
void Test_RectangleClass3();
// Пример 4 - прямоугольник массив из динамических объектов  
// Создать массив из 4 динамических объектов,
// вывести все их площади
void Test_RectangleClass4();
// Пример 5 - прямоугольник сохранить в файл fclass.txt  
// Создать объект Testmass класса RectangleClass с координатами (1,1) (4,1) (1,3)
// Сохранить его в файл и считать в новый объект Testmass1
// вывести плошадь прямоугольника
void Test_RectangleClass5();
// Тест с assert-ами, проверяет все функции работы с классом
void Test_Asserts();

