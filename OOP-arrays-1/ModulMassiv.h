/// \file ModulMassiv.h
/// \brief Заголовочный файл модуля ModulMassiv.cpp
/// \author БурдинскаЯ Наталья‚ ВМК-22
/// \date 29.10.2023

#pragma once
//предоставляет функционал для считывания данных из файла и для записи в файл.
#include <fstream>
// определяет функцию setlocale для установки русской локали и выводить сообщение на русском языке.
#include <locale>
//объявляет класс векторов
#include <vector>
//для использования строк
#include <string> 
//динамич.управление памятью, генерации случайных чисел srand и rand
//для использования abort, в случае ошибок в try catch
#include <stdlib.h> 
//объявляет набор функций,макросов и типов для работы с датой и временем
#include <time.h> 
//модуль с математическими константами и функциями - fabs ...
#include <cmath> 
//для assert
#include <cassert>
//Объявляет cin cout,управляющие чтением из станд.потоков и записью в них
#include <iostream>
//для определения нужного числа манипуляторов setw setprecision
#include <iomanip> 
//для обработки исключений exception
#include <stdexcept>  
//теперь можно обращаться ко всем именам, описанным в std, непосредственно, без префикса std::
using namespace std;

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАТРИЦЫ
namespace NamespaceMassiv
{
	//---функция выделение памяти для массива размерности n
	//int* Memo_Mass(unsigned n);

	//---процедура ввода массива размерности n случайными числами
	// Динамические массивы в функции передаются как векторы
	// ничего не возвращает, просто вводит данные в массив
	//void Vvod_Mass(int* a, unsigned n);
	void Vvod_Mass(vector<double>& a);
	//---процедура вывода на экран массива N
	// ничего не возвращает, просто выводит на консоль
	void Screen_Mass(vector<double>& a);

	//---функция расчета суммы |a1| + ... + |an|
	// массив a – формальные параметры
	// возвращает сумму типа int
	int Sum_Mass(vector<double>& a);

	//---проверка работы функции Sum_Mass на разных входных данных
	// в саму процедуру нет входящих параметров
	void Test_Sum_Mass();

	//---функция освобождение памяти массива N
	// массив *a формальные параметры
	// ничего не возвращает, просто удаляет память у массива а
	//void Del_Mass(int* a); 
}

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАТРИЦЫ В ФАЙЛЕ
namespace NamespaceFile
{
	//---процедурa записи в файл fmass.txt
	// массив a – формальные параметры
	// ничего не возвращает, просто пишет массив в файл
	void WriteFile(vector<double>& a);

	//-----процедурa чтения из файла fmass.txt
	// n – формальные параметры - размерность массива
	// возвращает прочитанный массив a из файла
	vector<double> ReadFile(unsigned n);

	//---процедурa добавления записи в файл fmass.txt
	// массив a – формальные параметры
	// ничего не возвращает, просто пишет массив в файл
	void AddFile(vector<double>& a);
}

