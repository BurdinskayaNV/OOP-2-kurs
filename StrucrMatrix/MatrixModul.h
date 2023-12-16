/// \file MatrixModul.h
/// \brief Заголовочный файл модуля MatrixModul.cpp
/// \brief Класс матрица
/// \author Бурдинская Наталья ВМК-22
/// \date 15.11.2023

//Объявляет cin cout, управляющие чтением из станд.потоков и записью в них
#include <iostream>
// работа с файлами
#include <fstream>
// определяет функцию setlocale для установки русской локали и выводить сообщение на русском языке
#include <locale>
#include <cmath>  // модуль с математическими константами и функциями
#include <cassert> // для assert
#include <iomanip> // для определения нужного числа манипуляторов setw setprecision
#include <string> // для работы со строками
#include <vector> // класс векторов
// теперь можно обращаться ко всем именам, описанным в std, непосредственно, без префикса std::
using namespace std;

// Класс - Матрица MatrixClass
class MatrixClass {
private:
	// поле класса как класс vector двумерный массив (вектор векторов типа double)
	vector <vector <double> > MatrixVector;

	// Получение матрицы путём удаление id строки и jd столбца
	MatrixClass Del_Line_Column(const MatrixClass* MainMatr, int id, int jd) const;

	// Проверка того, чтобы строки и столбцы были неотрицательными
	bool Nonnegative_Line_Column(int line, int column) const;

	// Проверка того, чтобы количество строк и столбцов матриц было одинаково
	// (для операторов *=, -=, +=)
	bool Line_Equality_Column(const MatrixClass& Matrix) const;

	// Установка новых размеров строк и столбцов
	void New_Line_Column(int line, int column);

public:
	// Конструктор матрицы
	MatrixClass();
	// Конструктор матрицы с параметрами строка и столбец
	MatrixClass(int line, int column);

	// геттеры элементов матрицы
	// const т.к. метод не меняет значений полей
	// Операция: получение элемента [n][m] матрицы
	float Get_Element(int n, int m) const;
	// Операция: получение количества строк
	int Get_Line() const;
	// Операция: получение количества столбцов
	int Get_Column() const;
	// Операция: получение матрицы
	void Get_Matrix() const;

	// сеттеры элементов матрицы
	// Операция: ввод количества строк и столбцов
	void Set_Line_Column(int line, int column);
	// Операция: ввод количества строк
	void Set_Line(int line);
	// Операция: ввод количества столбцов
	void Set_Column(int column);
	// Операция: ввод нового [n][m] элемента матрицы
	void Set_Element(int line, int column, double deft);

	// Операция: заполнение матрицы одним значением deft
	void Matrix_Default(double deft);
	// Операция: заполнить матрицу случайными значениями от min до max
	void Matrix_Random(double min, double max);

	// Операция: сложение матриц 
	MatrixClass operator+ (const MatrixClass& Matrix) const;
	// Операция: сложение матрицы с числом deft
	MatrixClass operator+ (double deft) const;

	// Операция: вычитание матриц
	MatrixClass operator- (const MatrixClass& Matrix) const;

	// Операция: вычитание матрицы числом deft
	MatrixClass operator- (double deft) const;

	// Операция: умножение матрицы на число deft
	MatrixClass operator* (double deft) const;

	// Операция: умножение матрицы на матрицу
	MatrixClass operator* (const MatrixClass& Matrix)const;

	// Операция: собственное умножение матрицы на матрицу
	void operator*= (const MatrixClass& Matrix);

	// Операция: собственное умножение матрицы на число deft
	void operator*= (double deft);

	// Операция: собственное вычитание матриц
	void operator-= (const MatrixClass& Matrix);

	// Операция: собственное вычитание числа deft из матрицы
	void operator-= (double deft);

	// Операция: собственное сложение матриц
	void operator+= (const MatrixClass& Matrix);

	// Операция: собственное сложение числа deft с матрицей
	void operator+= (double deft);

	// Операция: транспонирование матрицы
	MatrixClass Trans_Matrix() const;

	// Операция: диагональная матрица
	MatrixClass Diagonal_Matrix() const;

	// Операция: поиск определителя матрицы и ранга
	double Determinant(int rang) const;

	// Операция: построение обратной матрицы
	MatrixClass Inverse_Matrix() const;

	// Деструктор класса матрица
	~MatrixClass();
};
