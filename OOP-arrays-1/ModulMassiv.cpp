/// \file ModulMassiv.cpp
/// \brief cpp-файл модуль ModulMassiv.cpp
/// \author Бурдинская Наталья ВМК-22
/// \date 29.10.2023

// вызов заголовочного файла модуля ModulMassiv.cpp
#include "ModulMassiv.h"

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАССИВА
namespace NamespaceMassiv
{
	//---процедура ввода массива размерности n
	// Динамические массивы в функции передаются как векторы
	// ничего не возвращает, просто вводит данные в массив
	void Vvod_Mass(vector<double>& a)
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
	void Screen_Mass(vector<double>& a)
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
	int Sum_Mass(vector<double>& a)
	{
		// определение переменной (объявление + инициализация)
		int sum = 0;
		for (unsigned i = 0; i < a.size(); ++i)
		{
			sum = sum + fabs(a[i]); // fabs - абсолютное значение |a[i]|
		}
		return sum; // возврат суммы sum из функции Sum_Mass
	}

	//---ввод размера массива (для try-catch)
	int ReadArrLength() {
		int len;
		cin >> len;
		if ((len <= 0)) {
			throw length_error("(len <= 0) || (len >= 32769)");
		}
		else {
			return len;
		}
	}

	//---ввод имени файла для ввода и вывода массива (для try-catch)
	string ReadFileName() {
		string file_name;
		;
		char rep[]{ '*', '/', ':', '?', '"', '<', '>', '|' };
		cin >> file_name;
		for (int i = 0; i < 8; i++) {
			if (file_name.find(rep[i]) != file_name.npos) {
				throw invalid_argument("Некорректное имя файла");
			}
			file_name = file_name + ".txt";
			return file_name;
		}
	}

	//---функция поиска количества элементов массива в файле
	unsigned SizeFile(const string& file_name)
	{
		unsigned res = 0; // Переменная для счета количества строк
		string line; // Строка, с помощью которой ищем количество строк
		ifstream file(file_name); // Открытие файла 
		if (!file.is_open()) // Если не открыт файл
		{
			throw runtime_error("File not found"); // Если что, то в ошибку
		}
		// Цикл счёта количества строк -> количества элементов массива
		while (getline(file, line))
		{
			res++; // Цикл будет жить, пока getline делает переходы
		}
		file.close(); // Закрыть файл
		if (res == 0) // Ошибка, если файл пуст
			throw runtime_error("Array not found in file - file is empty");
		return res;
	}

	//---проверка работы функции Sum_Mass на разных входных данных
	// в саму процедуру нет входящих параметров
	void Test_Sum_Mass()
	{
		const double EPS = 10E-8; // допустимая ошибка   
		// массив размерность 3, инициализация всего массива нулями
		vector<double> b{ 0 };
		b.resize(3);
		//проверка через константу EPS, если внутри оператора assert будет ЛОЖЬ,
		//то программа аварийно завершит работу
		b[0] = 0; b[1] = 1; b[2] = 2; // |b0| + |b1| + |b2| = 0 + 1 + 2 = 3
		assert(abs(Sum_Mass(b) - 3) < EPS);

		//обыкновенная проверка, без константы EPS
		b[0] = 2; b[1] = 2; b[2] = 2; // |b0| + |b1| + |b2| = 2 + 2 + 2 = 6
		assert(Sum_Mass(b) == 6); // проверка не через константу EPS

		cout << "test Sum_Mass - OK" << endl;
		b.clear();
		//после окончания работы c массивом обязательно освобождаем его память
	}
}

// ПРОСТРАНСТВО ИМЕН ДЛЯ МАССИВА В ФАЙЛЕ
namespace NamespaceFile
{
	//---процедурa записи в файл fmass.txt
	// массив a – формальные параметры
	// ничего не возвращает, просто пишет массив в файл
	void WriteFile(vector<double>& a)
	{
		// Режим открытия файла для записи ios::out
		// устанавливается при создании файла
		ofstream Fin("fmass.txt", ios::out); //затирает старые и пишет новые данные
		// пишем в файл отправленный массив
		for (unsigned i = 0; i < a.size(); ++i)
		{
			Fin << a[i] << " ";
		}
		Fin << endl;
		Fin.close(); // Функция close() закрывает поток файла
		cout << "Write. End of recording" << endl;
	}

	//---процедурa чтения из файла fmass.txt
	// n – формальные параметры - размерность массива
	// возвращает прочитанный массив a из файла
	vector<double> ReadFile(unsigned n)
	{
		vector<double> a{ 0 };
		a.resize(n);
		ifstream Fout; // объявляем имя Fout для чтения
		//Режим открыть файл для чтения ios::in можно установить при
		//вызове метода open(), необязательно при создании файла(процедура выше)
		Fout.open("fmass.txt", ios::in); //открываем файл для чтения на начале
		//проверяю на наличие файла
		if (!Fout.good())
		{
			cout << "The file fmass.txt was not found !" << endl;
		}
		else
		{
			if (!Fout.eof()) // делаем пока не конец 
				for (int i = 0; i < n; ++i)
				{
					Fout >> a[i];
				}
		}
		Fout.close(); // Функция close() закрывает поток файла
		cout << "Read. End of file" << endl;
		return a;
	}

	//---процедурa добавления записи в файл fmass.txt
	// массив a – формальные параметры
	// ничего не возвращает, просто пишет массив в файл
	void AddFile(vector<double>& a)
	{
		//Режим открытия файла для добавления записи ios::app
		//устанавливается при создании файла
		ofstream Fin("fmass.txt", ios::app); // добавление в конец файла
		// пишем в файл отправленный массив
		for (unsigned i = 0; i < a.size(); ++i)
		{
			Fin << a[i] << " ";
		}
		Fin << endl;
		Fin.close(); /// Функция fclose() закрывает поток файла
		cout << "Add. End of recording" << endl;
		cout << "\n";
	}
}
