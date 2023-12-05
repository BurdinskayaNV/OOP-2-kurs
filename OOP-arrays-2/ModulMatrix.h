/// \file ModulMatrix.h
/// \brief Заголовочный файл модуля ModulMatrix.cpp
/// \brief Созданы пространства имён
/// \author Бурдинская Наталья ВМК-22
/// \date 20.10.2023

#pragma once
// стандартный для определения нужного числа манипуляторов setw setprecision.
#include <iomanip>
// объявляет набор функций, макросов и типов для работы с датой и временем
#include <time.h> 
/// предоставляет функционал для считывания данных из файла и для записи в файл.
#include <fstream>
/// Объявляет объекты cin cout, управляющие чтением из стандартных потоков и записью в них.
#include <iostream>
/// стандартный шаблон C++, реализующий динамический массив.
// Как и все стандартные компоненты, он расположен в пространстве имён std.
#include <vector>
/// теперь можно обращаться ко всем именам без префикса std::
using namespace std;
// создание синонима для типа vector<vector<int>> матрица
using vector_int = vector<vector<int>>;
// vector -- класс-обёртка для динамического массива
// vector -- шаблонный класс, поэтому поддерживает задание типа
// для вложенных в него значений (здесь это элементы массива). 
// Тип вложенных значений указывается внутри угловых скобок 
// < > при объявлении переменой типа vector
// <vector< >> создаём массив массивов векторов - матрица

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАТРИЦЫ
namespace NamespaceMatrix
{
	// процедура заполнение матрицы, размером N x M, случайными числами
	vector_int CreateRandomMatrix(vector_int matr, int n, int m);

	// процедура вывода на консоль двумерного массива N х М
	// процедура ничего не возвращает
	void Print_Vector(const vector_int& matr, int n, int m);

	// функция создание новой матрицы N х M, с помощью перестановок столбцов
	// на входе будет матрица vector_int &matr
	// на выходе будет матрица vector_int &matr, созданная перестановкой столбцов
	vector_int Perestanovka(vector_int& matr, int n, int m);
}

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАТРИЦЫ В ФАЙЛЕ
namespace NamespaceFile
{
	//процедура записи матрицы matr, размером N x M, в файл fmatrix.txt
	void WriteFile(vector_int matr, int n, int m);

	//процедура добавления записи матрицы matr, размером N x M, в файл fmatrix.txt
	void AddFile(vector_int matr, int n, int m);

	// процедура чтения матрицы matr, размером N x M, из файла fmatrix.txt
	vector_int ReadFile(vector_int matr, int n, int m);
}

