/// \file RectangleModule.cpp
/// \brief cpp-файл модуль RectangleModule.cpp
/// \brief Класс прямоугольник
/// \author Бурдинская Наталья ВМК-22
/// \date 01.11.2023
// вызов заголовочного файла модуля RectangleModule.cpp
#include "RectangleModule.h"

// Конструктор начальных значений
RectangleClass::RectangleClass() {
	x1 = 0; y1 = 0;
	x2 = 0; y2 = 0;
	x3 = 0; y3 = 0;
}

// Конструктор задание значений
RectangleClass::RectangleClass(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_)
{
	set_x1(x1_);			set_y1(y1_);
	set_x2(x2_);			set_y2(y2_);
	set_x3(x3_);			set_y3(y3_);
}

// геттер координаты x и y i-ой точки прямоугольника
// Операция: Прочитать x и y i-ой точки (i=1,2,3) прямоугольника
// (const т.к. метод не меняет значений полей)
double RectangleClass::get_x1() const { return x1; } double RectangleClass::get_y1() const { return y1; } // i=1
double RectangleClass::get_x2() const { return x2; } double RectangleClass::get_y2() const { return y2; } // i=2
double RectangleClass::get_x3() const { return x3; } double RectangleClass::get_y3() const { return y3; } // i=3

// сеттер координаты x и y i-ой точки прямоугольника
// Операция: Ввод x и y i-ой точки (i=1,2,3) прямоугольника
void RectangleClass::set_x1(double x_1) { x1 = x_1; } void RectangleClass::set_y1(double y_1) { y1 = y_1; } // i=1
void RectangleClass::set_x2(double x_2) { x2 = x_2; } void RectangleClass::set_y2(double y_2) { y2 = y_2; } // i=2 
void RectangleClass::set_x3(double x_3) { x3 = x_3; } void RectangleClass::set_y3(double y_3) { y3 = y_3; } // i=3 

// Операция: Нахождение длины стороны A прямоугольника
double RectangleClass::SideRectangleA() const
{
	//формула длины стороны прямоугольника через координаты двух точек
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// Операция: Нахождение длины стороны B прямоугольника
double RectangleClass::SideRectangleB() const
{
	//формула длины стороны прямоугольника через координаты двух точек
	return sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
}

// Операция: Нахождение угла между сторонами 
double  RectangleClass::AngleRectangle() const
{
	// Вычисляем значение углов через координаты 3-х точек (x1,y1),(x2,y2),(x3,y3)
	/*   A1(x3,y3)   B1(x4,y4)
		 |-----------|
		 |           |
		 |-----------|
		 A(x1,y1)    B(x2,y2)
	*/
	// по этому примеру, в нашей функции первыми формальными параметрами будут координаты вершины угла
	// причем (x1,y1) вершина угла angle_a(A1 A B),
	// координаты векторов АА1(х3-х1,у3-у1) и АВ(х2-х1,у2-у1)
	// скалярное произведение (АА1,АВ) будет (х3-х1)*(х2-х1)+(у3-у1)*(у2-у1)
	// длины сторон |АА1| и |AB| можно будет найти по нашей функции SideRectangle
	// тогда cos(angle_a)= (АА1,АВ)/(SideRectangle(х1,y1,x3,y3)*SideRectangle(х1,y1,x2,y2)) 
	// нам не обязательно переводить угол в градусы
	// у нас прямоугольник, значит угол 90 градусов 
	// достаточно будет показать, что косинус 90 равен 0

	// вычисляем координаты первого вектора между точками (x1,y1) и (x2,y2)
	double x2x1 = x2 - x1;
	double y2y1 = y2 - y1;
	// вычисляем координаты второго вектора между точками (x1,y1) и (x3,y3)	
	double x3x1 = x3 - x1;
	double y3y1 = y3 - y1;
	// находим скалярное произведение этих векторов
	double scalar = x2x1 * x3x1 + y2y1 * y3y1;
	// находим косинус угла
	return scalar / (SideRectangleA() * SideRectangleB());
}
// Операция: Нахождение координаты X четвертой точки прямоугольника
double RectangleClass::СoordinateX4() const
{
	// если угол при вершине (x1,y1) равен 90 градусов
	// значит косинус 90 градусов 0
	if (angle_a == 0)
		return x1 + (x2 - x1) + (x3 - x1);
	else
		cout << "Rectangle type : Other" << endl;
}

// Операция: Нахождение координаты Y четвертой точки прямоугольника
double RectangleClass::СoordinateY4() const
{
	// если угол при вершине (x1,y1) равен 90 градусов
	// значит косинус 90 градусов 0
	if (angle_a == 0)
		return y1 + (y2 - y1) + (y3 - y1);
	else
		cout << "Rectangle type : Other" << endl;
}

// Операция: Нахождение длины диагонали прямоугольника через координаты
double RectangleClass::DiagonalRectangle() const
{
	//формула длины диагонали прямоугольника через координаты двух точек
	return sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
}

// Операция: Расчет периметра P прямоугольника через длины сторон
double RectangleClass::PerimeterAB() const
{
	return 2 * a + 2 * b;
}

// Операция: Расчет площади S прямоугольника через длины сторон
double RectangleClass::SquareAB() const
{
	return a * b;
}

// Операция: Расчет периметра P прямоугольника через координаты точек
double RectangleClass::PerimeterXY() const
{
	return 2 * SideRectangleA() + 2 * SideRectangleB();
}

// Операция: Расчет площади S прямоугольника через координаты точек
double RectangleClass::SquareXY() const
{
	return SideRectangleA() * SideRectangleB();
}

// Операция: Определить вид прямоугольника
void RectangleClass::RectangleType()
{
	bool Okey = false; // если нашли фигуру, чтобы не попасть в ложное условие
	if ((a == b) && (angle_a == 0))
	{
		type = RecType::Sqare; //квадрат    
		Okey = true;
	}
	if ((Okey == false) && (a != b) && (angle_a == 0))
	{
		type = RecType::Rectangle; //прямоугольник
		Okey = true;
	}
	if (Okey == false)
		type = RecType::Other; // не прямоугольник и не квадрат - другое
}

// Операция: Вывод результатов - метод to string
string RectangleClass::OutputResults() const
{
	string ss = "Other";  		//разбиваем перечислимый тип на строки
	if (type == RecType::Sqare)
		ss = "Sqare";
	if (type == RecType::Rectangle)
		ss = "Rectangle";
	string s = "Length side a = " + to_string(a) + "\n" + "Length side b = " + to_string(b) + "\n"
		+ "Length Diagonal = " + to_string(d) + "\n"
		+ "COS Angle Rectangle = " + to_string(angle_a) + "\n" + "It's a " + ss + "\n"
		+ "Сoordinates 4 point = (" + to_string(x4) + "," + to_string(y4) + ")" + "\n"
		+ "Perimeter = " + to_string(PerimeterAB()) + "\n" + "Square = " + to_string(SquareAB()) + "\n";
	return s;
}

// Пример 1 - прямоугольник тестирование основного функционала
// Создать объект Test класса RectangleClass с координатами (1,1) (4,1) (1,3)
// Вычислить длины и углы сторон A и B, диагональ D,
// координаты 4-ой точки, периметр и площадь прямоугольника
// Затем поменять координаты на (1,1) (3,2) (0,3)
// Вычислить координаты 4-ой точки, площадь и периметр
void Test_RectangleClass1()
{
	RectangleClass Test;
	{
		Test.set_x1(1);			Test.set_y1(1);
		Test.set_x2(4);			Test.set_y2(1);
		Test.set_x3(1);			Test.set_y3(3);
	}

	Test.a = Test.SideRectangleA();
	Test.b = Test.SideRectangleB();
	assert(Test.a == 3.0);
	assert(Test.b == 2.0);

	Test.angle_a = Test.AngleRectangle();
	assert(Test.angle_a == 0);

	Test.d = Test.DiagonalRectangle();
	assert(Test.d > 3.5);

	Test.x4 = Test.СoordinateX4();
	assert(Test.x4 == 4);
	Test.y4 = Test.СoordinateY4();
	assert(Test.y4 == 3);

	Test.RectangleType();
	assert(Test.type == 1);

	assert(Test.PerimeterAB() == 10.00);
	assert(Test.SquareAB() == 6.00);
	assert(Test.PerimeterXY() == 10.00);
	assert(Test.SquareXY() == 6.00);
	cout << "Primer 1:" << endl;
	cout << "Test_RectangleClass Primer 1 - successfully OK" << endl;
	cout << "Length A = " << Test.a;
	cout << "	Length В = " << Test.b << endl;
	cout << "Angle А = " << Test.angle_a;
	cout << "	Diagonal D = " << Test.d << endl;
	cout << "Сoordinate X4 = " << Test.x4;
	cout << "	Сoordinate Y4 = " << Test.y4 << endl;
	cout << "Perimeter = " << Test.PerimeterAB();
	cout << "	Square = " << Test.SquareAB() << endl;
	// Затем поменять координаты на (1,1) (3,2) (0,3)
	RectangleClass Test1;
	{
		Test1.set_x1(1);			Test1.set_y1(1);
		Test1.set_x2(3);			Test1.set_y2(2);
		Test1.set_x3(0);			Test1.set_y3(3);
	}
	Test1.angle_a = Test1.AngleRectangle();

	cout << "New Сoordinate X4 = " << Test1.СoordinateX4();
	cout << "	New Сoordinate Y4 = " << Test1.СoordinateY4() << endl;
	cout << "New Perimeter = " << Test1.PerimeterXY();
	cout << "	New Square = " << Test1.SquareXY() << endl;
}

// Пример 2 - прямоугольник статистический массив
// Создать массив 3 объектов Test класса RectangleClass с различными координатами
// Найти сумму периметров прямоугольников и квадратов
void Test_RectangleClass2()
{
	RectangleClass Tests[3]{
		RectangleClass(0, 0, 4, 0, 0, 4), // 16 квадрат
		RectangleClass(1, 1, 4, 1, 1, 3), // 10 прямоугольник
		RectangleClass(1, 2, 3, 1, 1, 5)  // не прямоугольник
	};
	cout << "Primer 2:" << endl;
	cout << "Test_RectangleClass Primer 2 - successfully OK" << endl;
	double summ = 0;
	string ss = "";
	// находим сумму периметров
	for (int i = 0; i < 3; i++)
	{
		Tests[i].angle_a = Tests[i].AngleRectangle();
		Tests[i].RectangleType();
		if (Tests[i].type == 0)	ss = "Rectangle";
		if (Tests[i].type == 1)	ss = "Rectangle";
		if (Tests[i].type == 2)	ss = "Other";
		cout << "Rectangle Type = " << ss << endl;
		if ((Tests[i].type == 0) || (Tests[i].type == 1))
		{
			summ = summ + Tests[i].PerimeterXY();
			cout << "Perimeter " << i + 1 << " Rectangle " << "= " << Tests[i].PerimeterXY() << endl;
		}
		ss = "";
	}
	cout << "Summ = " << summ << endl;
}

// Пример 3 - прямоугольник динамический объект по умолчанию
// Создать динамический объект TestМ класса RectangleClass 
// Найти площадь прямоугольника
void Test_RectangleClass3()
{
	cout << "Primer 3:" << endl;
	cout << "Test_RectangleClass Primer 3 - successfully OK" << endl;
	RectangleClass* TestM = new RectangleClass(0, 0, 4, 0, 0, 4);
	cout << "Length side a = " << TestM->SideRectangleA();
	cout << "	Length side b = " << TestM->SideRectangleB();
	cout << "	COS Angle Rectangle = " << TestM->AngleRectangle() << endl;
	cout << "Square = " << TestM->SquareXY() << endl;
	delete TestM;
}

// Пример 4 - прямоугольник массив из динамических объектов  
// Создать массив из 3 динамических объектов,
// вывести все их площади
void Test_RectangleClass4()
{
	cout << "Primer 4:" << endl;
	cout << "Test_RectangleClass Primer 4 - successfully OK" << endl;
	RectangleClass* Test_Mass[3];
	Test_Mass[0] = new RectangleClass(0, 0, 4, 0, 0, 4);
	Test_Mass[1] = new RectangleClass(-2, 3, 5, 6, 7, -1);
	Test_Mass[2] = new RectangleClass(1, -1, -1, 1, 1, 1);
	for (int i = 0; i < 3; i++)
	{
		cout << "Test_Mass " << i + 1 << " - " << " Square: " << Test_Mass[i]->SquareXY() << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		delete Test_Mass[i];
	}
}

// Пример 5 - прямоугольник сохранить в файл fclass.txt  
// Создать объект Testmass класса RectangleClass с координатами (1,1) (4,1) (1,3)
// Сохранить его в файл и считать в новый объект Testmass1
// вывести плошадь прямоугольника
void Test_RectangleClass5()
{
	cout << "Primer 5:" << endl;
	cout << "Test_RectangleClass Primer 5 - successfully OK" << endl;
	string s = "fclass.txt";
	RectangleClass Testmass(1, 1, 4, 1, 1, 3);
	// area before writing to the file - площадь до записи в файл
	cout << " area before writing to the file : " << Testmass.SquareXY() << endl;
	// Запись в файл
	ofstream Fout;
	Fout.open(s);
	if (Fout.is_open()) {
		Fout << Testmass.get_x1() << endl << Testmass.get_y1() << endl;
		Fout << Testmass.get_x2() << endl << Testmass.get_y2() << endl;
		Fout << Testmass.get_x3() << endl << Testmass.get_y3() << endl;
	}
	cout << "Write. End of recording" << endl;
	Fout.close();
	// Считывание с файла
	RectangleClass Testmass1;
	ifstream Fin;
	Fin.open(s);
	double x, y;
	if (Fin.is_open()) {
		Fin >> x; Fin >> y;
		Testmass1.set_x1(x); Testmass1.set_y1(y);
		Fin >> x; Fin >> y;
		Testmass1.set_x2(x); Testmass1.set_y2(y);
		Fin >> x; Fin >> y;
		Testmass1.set_x3(x); Testmass1.set_y3(y);
	}
	cout << "Read. End of file" << endl;
	Fin.close();
	// area after reading from file - площадь после чтения из файла
	cout << " area after reading from file : " << Testmass.SquareXY() << endl;
}
