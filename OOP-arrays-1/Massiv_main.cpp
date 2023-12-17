/// \file Massiv_main.cpp
/// \brief тело основной программы
/// \brief использован одномерный динамический массив
/// \brief выделение памяти для массива, освобождение памяти массива
/// \brief передача массива в функции, возврат из функции через return, указатели *
/// \brief применение srand(time(NULL)) и rand()
/// \brief демонстрация работы с библиотекой <fstream>
/// \brief созданы пространства имён NamespaceMassiv и NamespaceFile
/// \brief автоматическое тестирование программы с помощью assert
/// \brief реализованы функции работы с массивом
/// \brief оформлен через модуль из трёх файлов
/// \brief создан репозиторий в GitHub
/// \brief 
/// \brief использован vector вместо классического массива
/// \brief Аргументы командной строки cmd arg для функции main
/// \author Бурдинская Наталья ВМК-22
/// \date 29.10.2023

/* Задача 136в: Даны натуральное число n,
*  действительные числа a1,..., an.
*  Вычислить: в) |a1| + ... + |an| */

// вызов заголовочного файла модуля ModulMassiv.cpp
#include "ModulMassiv.h"
// пространство имён для работы с матрицей
using namespace NamespaceMassiv;
// пространство имён для работы с матрицей в файлах
using namespace NamespaceFile;

int main(int argc, char* argv[]) //главная функция, вызываемая при запуске программы
{
	// Функция setlocale задаёт локализацию программы. 
	// LC_ALL указывает программе, что локализированы будут все функции.
	// «Rus» локализация произойдёт на русский язык.
	setlocale(LC_ALL, "RUSSIAN");
	// Аргументы командной строки cmd arg для функции main
	// argv[0] - имя файла Massiv_main.exe
	// значит начинаем argv[1] и argv[2] 
	// в нашем случае argc = 3
	// (argv[0] имя самого проекта, argv[1] размерность массива и argv[2] имя файла для ввода и сохранения данных)
	if (argc == 3) {
		int n = stoi(argv[1]); // преобразовать строку в int 
		string file_name = argv[2];
	}
	else { //блок try-catch
		cout << "Number of array elements" << endl;
		try {
			int n = ReadArrLength(); // отсутствует argv[1] или не переведется из стоки в int
		}
		catch (const std::length_error err) {   
			cout << err.what() << endl; // выводим сообщение об ошибке
		}
		cout << "Input filename:" << endl;
		try {
			string file_name = ReadFileName(); // отсутствует argv[2] или некорректный ввод имени файла
		}
		catch (const std::invalid_argument inval) {//ловим исключение
			cout << inval.what() << endl;
		}
	}

	int n = stoi(argv[1]); // преобразовать строку в int 
	vector<double> arr; // описываем массив как вектор
	arr.resize(n); // даем ему размерность n из переданного аргумента argv[1]

	// Задаем размерность массива
	//cout << "Dimension of the massiv N " << endl;
	//cout << "n = "; cin >> n;
	
	Vvod_Mass(arr); // выполняем ввод массива
	Screen_Mass(arr); // выводим на экран массив введеных коэффициентов
	cout << "\n";

	// проверка работы функции Sum_Mass на разных входных данных
	Test_Sum_Mass();
	cout << "Summa |a1| + ... + |an| = " << Sum_Mass(arr) << endl;
	cout << "\n";

	// выполняем запись массива в файл
	WriteFile(arr);
	cout << "\n";
	// читаем из файла массив и выдаем на консоль
	string file_name = argv[2]; // название файла
	try   // проверка на исключения
	{
		// Заполняем массив arr1 из файла fmass.txt
		// это защищенный блок кода 
		// при чтении массива может возникнуть исключение 
		// Находим количество элементов массива из файла
		unsigned size_1 = SizeFile(file_name);
	}
	catch (const exception& error) // файл не открыт или пуст
	{	
		// Код, который выполняется при возникновении исключения типа
		// Exception генерируется в блоке try
		// Зарегистрировать сообщение об ошибке в объекте exception
		cout << error.what() << endl;
	}
	vector<double> arr1;
	arr1.resize(n); // Задаем размер size
	arr1 = ReadFile(n);
	Screen_Mass(arr1); // выводим на экран массив введеных коэффициентов
	arr.clear();
	return 0;
}
