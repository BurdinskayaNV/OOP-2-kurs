// Бурдинская Наталья - Тело основной программы zd2_number4.cpp
// Даны два действительных положительных числа
// Найти среднее арифметическое и среднее геометрическое этих чисел
// Включение заголовочных файлов стандартной библиотеки
// Автоматическое тестирование ASSERT
// Аргументы командной строки cmd arg для функции main
#include "modul_number4.h" // вызов заголовочного файла модуля 

// главная функция программы
int main(int argc, char* argv[])
{
	float a, b;  //Исходные переменные
	string str_argv;
	int k;	k = argc;
	// проверка работы функции SredArif на разных входных данных
    Test_SredArif();
    // проверка работы функции SredGeom на разных входных данных
    Test_SredGeom();
    // даны два действительных положительных числа
    // Вещественные литералы обязательно содержат точку в своей записи.
    // вызвать в программе один раз, перед выводом чисел.
    cout << fixed << setprecision(2); // 12 позиций на всё число, два знака после запятой

    // cmd arg
    // argv[0] - имя файла zd2_number4.exe
	// значит начинаем argv[1]	
    if (k > 1)  // условия что я ввожу аргументы
	{
		str_argv = argv [1];
		if (str_argv == "help")	// Если введут help
		{
		  cout << "For the program to work correctly, enter the first argument: <calc>" << endl;
		  cout << "After <calc>, enter the values <a> and <b>" << endl;
		}	
		if (str_argv == "calc") // Если введут calc - calculate
		{
		  a = stof (argv[2]);
		  b = stof (argv[3]);
	      // вызов функции SredArif, расчёт среднего арифметического чисел а и b, вывод результа на экран
          cout << "Arithmetic mean progression = " << SredArif(a, b) << endl;
          // вызов функции SredGeom, расчёт среднего геометрического чисел а и b, вывод результа на экран
          cout << "Geometric mean progression = " << SredGeom(a, b) << endl; 
		}
	}
	else
	{
	   cout << "a = "; cin >> a; // вводим а
       cout << "b = "; cin >> b; // вводим b
	   // вызов функции SredArif, расчёт среднего арифметического чисел а и b, вывод результа на экран
       cout << "Arithmetic mean progression = " << SredArif(a, b) << endl;
       // вызов функции SredGeom, расчёт среднего геометрического чисел а и b, вывод результа на экран
       cout << "Geometric mean progression = " << SredGeom(a, b) << endl; 
	}
    return 0;
}
