/// \file ModulMassiv.h
/// \brief Заголовочный файл модуля ModulMassiv.cpp
/// \author БурдинскаЯ Наталья‚ ВМК-22
/// \date 29.10.2023

#pragma once
//предоставляет функционал для считывания данных из файла и для записи в файл.
#include <fstream>
// определяет функцию setlocale для установки русской локали и выводить сообщение на русском языке.
#include <locale>
#include <vector> //объявляет класс векторов
#include <string> //для использования строк
//динамич.управление памятью, генерации случайных чисел srand и rand
//для использования abort, в случае ошибок в try catch
#include <stdlib.h> 
//объявляет набор функций,макросов и типов для работы с датой и временем
#include <time.h> 
//модуль с математическими константами и функциями - fabs ...
#include <cmath> 
#include <cassert> //для assert
//Объявляет cin cout,управляющие чтением из станд.потоков и записью в них
#include <iostream>
//для определения нужного числа манипуляторов setw setprecision
#include <iomanip> 
#include <stdexcept> //для обработки исключений exception
//теперь можно обращаться ко всем именам, описанным в std, непосредственно, без префикса std::
using namespace std;

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАТРИЦЫ
namespace NamespaceMassiv
{
	//---процедура ввода массива размерности n случайными числами
	// Динамические массивы в функции передаются как векторы
	// ничего не возвращает, просто вводит данные в массив
	template <typename type>
	void Vvod_Mass(vector<type>& a)
	{
		// массив a – формальные параметры
		// Генерирует случайное число, используя текущею дату, для непредсказуемости результата
		srand(time(0)); // инициализация генератора случайных чисел текущим временем в секундах time
		// заполнение массива случайными числами от -100 до 100 включительно
		for (unsigned i = 0; i < a.size(); ++i) // нумерация с нуля до n-1
		{
			a[i] = rand() % 200 - 100;
			// rand() возвращает случайное целое число от 0 до RAND_MAX
		}
	}

	//---процедура вывода на экран массива N
	// ничего не возвращает, просто выводит на консоль
	template<typename type>
	void Screen_Mass(const vector<type>& a)
	{
		// массив a – формальные параметры
		for (unsigned i = 0; i < a.size(); i++)
		{
			cout << "a[" << i << "] = " << a[i] << " ";
		}
		cout << "\n";
	}

	//---функция расчета суммы |a1| + ... + |an|
	// массив a – формальные параметры
	// возвращает сумму типа int
	template<typename type>
	int Sum_Mass(const vector<type>& a)
	{
		// определение переменной (объявление + инициализация)
		int sum = 0;
		for (unsigned i = 0; i < a.size(); ++i)
		{
			sum = sum + fabs(a[i]); // fabs - абсолютное значение |a[i]|
		}
		return sum; // возврат суммы sum из функции Sum_Mass
	}

	//---функция поиска количества элементов массива в файле
	unsigned SizeFile(const string& file_name);

	//---проверка работы функции Sum_Mass на разных входных данных
	// в саму процедуру нет входящих параметров
	void Test_Sum_Mass();
}

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАТРИЦЫ В ФАЙЛЕ
namespace NamespaceFile
{
	//---процедурa записи в файл fmass.txt
	// массив a – формальные параметры
	// ничего не возвращает, просто пишет массив в файл
	template<typename type>
	void WriteFile(string file_name, const vector<type>& a)
	{
		// Режим открытия файла для записи ios::out
		// устанавливается при создании файла
		ofstream Fin(file_name, ios::out); //затирает старые и пишет новые данные
		// пишем в файл отправленный массив
		for (unsigned i = 0; i < a.size(); ++i)
		{
			Fin << a[i] << " ";
		}
		Fin << endl;
		Fin.close(); // Функция close() закрывает поток файла
		cout << "Пишем. Конец записи." << endl;
	}

	//-----процедурa чтения из файла fmass.txt
	// n – формальные параметры - размерность массива
	// возвращает прочитанный массив a из файла
	vector<double> ReadFile(string file_name, unsigned n);
	
	//---процедурa добавления записи в файл fmass.txt
	// массив a – формальные параметры
	// ничего не возвращает, просто пишет массив в файл
	template<typename type>
	void AddFile(string file_name, const vector<type>& a)
	{
		//Режим открытия файла для добавления записи ios::app
		//устанавливается при создании файла
		ofstream Fin(file_name, ios::app); // добавление в конец файла
		// пишем в файл отправленный массив
		for (unsigned i = 0; i < a.size(); ++i)
		{
			Fin << a[i] << " ";
		}
		Fin << endl;
		Fin.close(); /// Функция fclose() закрывает поток файла
		cout << "Добавить. Конец записи." << endl;
		cout << "\n";
	}
}
