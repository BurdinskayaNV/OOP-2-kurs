/// \file MainVector.cpp
/// \brief демонстрация работы с динамическим 2-х мерным массивом
/// \brief Этот файл содержит функцию "main". 
/// \brief Здесь начинается и заканчивается выполнение программы.
/// \author Бурдинская Наталья ВМК-22
/// \date 20.10.2023
/*
* 676 Дана целочисленная матрица размера 4х9.
* Найти матрицу получающуюся из данной:
* перестановкой столбцов - первого с последним,
*  второго с предпоследним и т.д.
*/
// вызов заголовочного файла модуля ModulMatrix.cpp
#include "ModulMatrix.h"
/// определяет функцию setlocale для установки русской локали и выводить сообщение на русском языке.
#include <locale>
// пространство имён для работы с матрицей
using namespace NamespaceMatrix;
// пространство имён для работы с матрицей в файлах
using namespace NamespaceFile;

int main(int argc, char const* argv[])
{
	int n; int m;
	// Функция setlocale задаёт локализацию программы. 
	// LC_ALL указывает программе, что локализированы будут все функции.
	// «Rus» локализация произойдёт на русский язык.
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Dimension of the matrix N x M " << endl;
	cout << "n = "; cin >> n;
	cout << "m = "; cin >> m;
	vector_int matr; // динамическая матрица (пока пуста) NхM
	// выделение памяти под n элементов (с типом vector<int> )
	// потому что столбцов m, а строк будет n в vector<vector<int>>
	matr.resize(n); // строки
	// выделение памяти под строки матрицы 
	for (int i = 0; i < n; ++i)
		matr[i].resize(m);
	// обращение к элементам 4 x 5
	//matr[0][0] = 1; matr[0][1] = 2; matr[0][2] = 3; matr[0][3] = 4; matr[0][4] = 5;
	//matr[1][0] = 1; matr[1][1] = 2; matr[1][2] = 3; matr[1][3] = 4; matr[1][4] = 5;
	//matr[2][0] = 1; matr[2][1] = 2; matr[2][2] = 3; matr[2][3] = 4; matr[2][4] = 5;
	//matr[3][0] = 1; matr[3][1] = 2; matr[3][2] = 3; matr[3][3] = 4; matr[3][4] = 5;

	// процедура заполнение матрицы, размером N x M, случайными числами
	// n и m размерность матрицы фактический параметр в процедурах и функциях
	// массив векторов matr тоже фактический параметр
	matr = CreateRandomMatrix(matr, n, m);
	// процедура вывода матрицы на консоль
	cout << "matrix 1" << endl;
	Print_Vector(matr, n, m);
	//процедура записи матрицы matr, размером N x M, в файл fmatrix.txt
	WriteFile(matr, n, m);

	// вызов процедуры перестановки столбцов в матрице
	matr = Perestanovka(matr, n, m);
	// процедура вывода матрицы на консоль с новой матрицей
	cout << "matrix 2" << endl;
	Print_Vector(matr, n, m);
	//процедура записи новой матрицы matr, размером N x M, в файл fmatrix.txt
	AddFile(matr, n, m);

	try
	{
		// Заполняем матрицу mart, и еt размерность N х M из файла fmatrix.txt
		matr = ReadFile(matr, n, m);
		cout << endl;
		Print_Vector(matr, n, m);
	}
	catch (const std::exception& e)
	{
		cout << e.what() << endl;
	}

	cout << "Read. End of file" << endl;
	cout << "\n";

	matr.clear(); // освобождение памяти 
	// функция clear вызывается автоматически при уничтожении переменной

	return 0;
}
