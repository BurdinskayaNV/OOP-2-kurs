/// \file RectangleMain.cpp
/// \brief тело основной программы
/// \brief Геометрическая фигура - прямоугольник
/// \brief Задание координат точек вершин прямоугольника
/// \brief Вычисление длины сторон прямоугольника
/// \brief Вычисление длины диагонали прямоугольника
/// \brief Вычисление углов прямоугольника
/// \brief Вычисление координат 4-ой точки прямоугольника
/// \brief Вычисление площади и периметра через стороны
/// \brief Вычисление площади и периметра через координаты
/// \brief Определение вида прямоугольника
/// \brief автоматическое тестирование программы с помощью assert
/// \brief оформлен через модуль из трёх файлов
/// \brief создан репозиторий в GitHub
/// \brief созданы 6 геттеров и 6 сеттеров
/// \brief реализованы методы для доступа и изменения данных
/// \brief контроль постоянства, конструктор с параметрами
/// \brief пример 1 - тестирование кода простого класса
/// \brief пример 2 - статистический массив из объектов
/// \brief пример 3 - динамический объект по умолчанию
/// \brief пример 4 - массив из динамических объектов  
/// \brief пример 5 - работа с файлом fclass.txt 
/// \author Бурдинская Наталья ВМК-22
/// \date 01.11.2023

// вызов заголовочного файла модуля RectangleModule.cpp
#include "RectangleModule.h"

//главная функция, вызываемая при запуске программы
int main()
//int main()
{
	// Rect - экземпляр класса RectangleClass
	RectangleClass Rect;
	// Функция setlocale задаёт локализацию программы. 
	// LC_ALL указывает программе, что локализированы будут все функции.
	// «Rus» локализация произойдёт на русский язык
	setlocale(LC_ALL, "russian");
	// вызвать в программе один раз, перед выводом чисел.
	cout << fixed << setprecision(1); // один знак после запятой

	// Тест с assert-ами, проверяет все функции работы с классом
	cout << "======================================================" << endl;
	Test_Asserts();
	cout << "======================================================" << endl;
	cout << endl;

	// Производим тестирование кода на Примере 1
	// Пример 1 - прямоугольник тестирование основного функционала
	// Создать объект Test класса RectangleClass с координатами (1,1) (4,1) (1,3)
	// Вычислить длины и углы сторон A и B, диагональ D,
	// координаты 4-ой точки, периметр и площадь прямоугольника
	// Затем поменять координаты на (1,1) (3,2) (0,3)
	// Вычислить координаты 4-ой точки, площадь и периметр
	cout << "======================================================" << endl;
	Test_RectangleClass1();
	cout << "======================================================" << endl;
	cout << endl;

	//Производим тестирование кода на Примере 2
	// Пример 2 - прямоугольник. статистический массив 
	// Создать массив 3 объектов Test класса RectangleClass с различными координатами
	// Определить виды отъектов и найти сумму периметров только прямоугольников и квадратов
	cout << "======================================================" << endl;
	Test_RectangleClass2();
	cout << "======================================================" << endl;
	cout << endl;

	// Пример 3 - прямоугольник. динамический объект по умолчанию
	// Создать массив TestМ класса RectangleClass 
	// Найти площадь прямоугольника
	cout << "======================================================" << endl;
	Test_RectangleClass3();
	cout << "======================================================" << endl;
	cout << endl;

	// Пример 4 - прямоугольник. массив из динамических объектов  
	// Создать массив из 3 динамических объектов,
	// вывести все их площади
	cout << "======================================================" << endl;
	Test_RectangleClass4();
	cout << "======================================================" << endl;
	cout << endl;

	// Пример 5 - прямоугольник сохранить в файл fclass.txt  
	// Создать объект Testmass класса RectangleClass с координатами (1,1) (4,1) (1,3)
	// Сохранить его в файл и считать в новый объект Testmass1
	// вывести плошадь прямоугольника
	cout << "======================================================" << endl;
	Test_RectangleClass5();
	cout << "======================================================" << endl;
	cout << endl;

	char stop = '1';
	while (stop == '1')
	{
		cout << "======================================================" << endl;
		// введите координаты точек прямоугольника
		cout << "Введите координаты точек ващего прямоугольника..." << endl;
		double tm;
		for (unsigned i = 0; i < 3; i++)
		{
			cout << "Введите координаты Х " << i + 1 << " : "; // Введите координаты Х
			cin >> tm;
			switch (i)
			{
			case 0: Rect.set_x1(tm); break;
			case 1: Rect.set_x2(tm); break;
			case 2: Rect.set_x3(tm); break;
			}
			cout << "Введите координаты Y " << i + 1 << " : "; // Введите координаты Y
			cin >> tm;
			switch (i)
			{
			case 0: Rect.set_y1(tm); break;
			case 1: Rect.set_y2(tm); break;
			case 2: Rect.set_y3(tm); break;
			}
		}
		cout << "======================================================" << endl;

		char ask1; // Переменная вопроса 1 ДА или 0 НЕТ "Начнем менять координаты? 1/0"
		cout << "Начнем менять координаты ? 1-ДА / 0-НЕТ : ";
		cin >> ask1;
		while (ask1 == '1')
		{   // Введите номер координаты изменения (i = 1,2,3)
			cout << "Введите номер координаты изменения (i = 1,2,3) : ";
			char ask;
			cin >> ask;
			switch (ask)
			{
			case '1': {cout << "Новая Х = "; cin >> tm; Rect.set_x1(tm);
				cout << "Новая У = "; cin >> tm; Rect.set_y1(tm); break; }
			case '2': {cout << "Новая Х = "; cin >> tm; Rect.set_x2(tm);
				cout << "Новая У = "; cin >> tm; Rect.set_y2(tm); break; }
			case '3': {cout << "Новая Х = "; cin >> tm; Rect.set_x3(tm);
				cout << "Новая У = "; cin >> tm; Rect.set_y3(tm); break; }
			}
			cout << "Новые координаты:" << endl; // новые координаты
			cout << "x1 = " << Rect.get_x1() << " y1 = " << Rect.get_y1() << endl;
			cout << "x2 = " << Rect.get_x2() << " y2 = " << Rect.get_y2() << endl;
			cout << "x3 = " << Rect.get_x3() << " y3 = " << Rect.get_y3() << endl;

			cout << "Продолжить изменения? 1-ДА / 0-НЕТ : "; // для продолжения изменения введите 1 ДА или 0 НЕТ
			cin >> ask1;
		}

		//Находим угол. Если он прямой, тогда косинус угла равен нулю
		double angle_a = Rect.AngleRectangle();
		//Находим длины сторон а, b и диагонали d 
		double a = Rect.SideRectangleA();
		double b = Rect.SideRectangleB();
		double d = Rect.DiagonalRectangle();
		//Находим Нахождение координаты X и Y четвертой точки прямоугольника 
		double x4 = Rect.СoordinateX4();
		double y4 = Rect.СoordinateY4();
		Rect.RectangleType(); // определяем тип прямоугольника

		try {
			string str_exit = Rect.RefundResults();
			cout << str_exit << endl; // выводим результат как строку - string
		}
		catch (const std::invalid_argument inval) { // Некорректный аргумент
			cout << inval.what() << endl;
		}

		cout << "======================================================" << endl;
		cout << "Начать сначала? 1-ДА / 0-НЕТ : "; // Начни сначала 1 ДА, 0 НЕТ
		cin >> stop; // вводим поле stop 1 ДА или 0 НЕТ
	}
}

