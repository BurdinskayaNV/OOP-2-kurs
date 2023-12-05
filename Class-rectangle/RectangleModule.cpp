/// \file RectangleModule.cpp
/// \brief cpp-���� ������ RectangleModule.cpp
/// \brief ����� �������������
/// \author ���������� ������� ���-22
/// \date 01.11.2023
// ����� ������������� ����� ������ RectangleModule.cpp
#include "RectangleModule.h"

// ����������� ��������� ��������
RectangleClass::RectangleClass() {
	x1 = 0; y1 = 0;
	x2 = 0; y2 = 0;
	x3 = 0; y3 = 0;
}

// ����������� ������� ��������
RectangleClass::RectangleClass(double x1_, double y1_, double x2_, double y2_, double x3_, double y3_)
{
	set_x1(x1_);			set_y1(y1_);
	set_x2(x2_);			set_y2(y2_);
	set_x3(x3_);			set_y3(y3_);
}

// ������ ���������� x � y i-�� ����� ��������������
// ��������: ��������� x � y i-�� ����� (i=1,2,3) ��������������
// (const �.�. ����� �� ������ �������� �����)
double RectangleClass::get_x1() const { return x1; } double RectangleClass::get_y1() const { return y1; } // i=1
double RectangleClass::get_x2() const { return x2; } double RectangleClass::get_y2() const { return y2; } // i=2
double RectangleClass::get_x3() const { return x3; } double RectangleClass::get_y3() const { return y3; } // i=3

// ������ ���������� x � y i-�� ����� ��������������
// ��������: ���� x � y i-�� ����� (i=1,2,3) ��������������
void RectangleClass::set_x1(double x_1) { x1 = x_1; } void RectangleClass::set_y1(double y_1) { y1 = y_1; } // i=1
void RectangleClass::set_x2(double x_2) { x2 = x_2; } void RectangleClass::set_y2(double y_2) { y2 = y_2; } // i=2 
void RectangleClass::set_x3(double x_3) { x3 = x_3; } void RectangleClass::set_y3(double y_3) { y3 = y_3; } // i=3 

// ��������: ���������� ����� ������� A ��������������
double RectangleClass::SideRectangleA() const
{
	//������� ����� ������� �������������� ����� ���������� ���� �����
	return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

// ��������: ���������� ����� ������� B ��������������
double RectangleClass::SideRectangleB() const
{
	//������� ����� ������� �������������� ����� ���������� ���� �����
	return sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2));
}

// ��������: ���������� ���� ����� ��������� 
double  RectangleClass::AngleRectangle() const
{
	// ��������� �������� ����� ����� ���������� 3-� ����� (x1,y1),(x2,y2),(x3,y3)
	/*   A1(x3,y3)   B1(x4,y4)
		 |-----------|
		 |           |
		 |-----------|
		 A(x1,y1)    B(x2,y2)
	*/
	// �� ����� �������, � ����� ������� ������� ����������� ����������� ����� ���������� ������� ����
	// ������ (x1,y1) ������� ���� angle_a(A1 A B),
	// ���������� �������� ��1(�3-�1,�3-�1) � ��(�2-�1,�2-�1)
	// ��������� ������������ (��1,��) ����� (�3-�1)*(�2-�1)+(�3-�1)*(�2-�1)
	// ����� ������ |��1| � |AB| ����� ����� ����� �� ����� ������� SideRectangle
	// ����� cos(angle_a)= (��1,��)/(SideRectangle(�1,y1,x3,y3)*SideRectangle(�1,y1,x2,y2)) 
	// ��� �� ����������� ���������� ���� � �������
	// � ��� �������������, ������ ���� 90 �������� 
	// ���������� ����� ��������, ��� ������� 90 ����� 0

	// ��������� ���������� ������� ������� ����� ������� (x1,y1) � (x2,y2)
	double x2x1 = x2 - x1;
	double y2y1 = y2 - y1;
	// ��������� ���������� ������� ������� ����� ������� (x1,y1) � (x3,y3)	
	double x3x1 = x3 - x1;
	double y3y1 = y3 - y1;
	// ������� ��������� ������������ ���� ��������
	double scalar = x2x1 * x3x1 + y2y1 * y3y1;
	// ������� ������� ����
	return scalar / (SideRectangleA() * SideRectangleB());
}
// ��������: ���������� ���������� X ��������� ����� ��������������
double RectangleClass::�oordinateX4() const
{
	// ���� ���� ��� ������� (x1,y1) ����� 90 ��������
	// ������ ������� 90 �������� 0
	if (angle_a == 0)
		return x1 + (x2 - x1) + (x3 - x1);
	else
		cout << "Rectangle type : Other" << endl;
}

// ��������: ���������� ���������� Y ��������� ����� ��������������
double RectangleClass::�oordinateY4() const
{
	// ���� ���� ��� ������� (x1,y1) ����� 90 ��������
	// ������ ������� 90 �������� 0
	if (angle_a == 0)
		return y1 + (y2 - y1) + (y3 - y1);
	else
		cout << "Rectangle type : Other" << endl;
}

// ��������: ���������� ����� ��������� �������������� ����� ����������
double RectangleClass::DiagonalRectangle() const
{
	//������� ����� ��������� �������������� ����� ���������� ���� �����
	return sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
}

// ��������: ������ ��������� P �������������� ����� ����� ������
double RectangleClass::PerimeterAB() const
{
	return 2 * a + 2 * b;
}

// ��������: ������ ������� S �������������� ����� ����� ������
double RectangleClass::SquareAB() const
{
	return a * b;
}

// ��������: ������ ��������� P �������������� ����� ���������� �����
double RectangleClass::PerimeterXY() const
{
	return 2 * SideRectangleA() + 2 * SideRectangleB();
}

// ��������: ������ ������� S �������������� ����� ���������� �����
double RectangleClass::SquareXY() const
{
	return SideRectangleA() * SideRectangleB();
}

// ��������: ���������� ��� ��������������
void RectangleClass::RectangleType()
{
	bool Okey = false; // ���� ����� ������, ����� �� ������� � ������ �������
	if ((a == b) && (angle_a == 0))
	{
		type = RecType::Sqare; //�������    
		Okey = true;
	}
	if ((Okey == false) && (a != b) && (angle_a == 0))
	{
		type = RecType::Rectangle; //�������������
		Okey = true;
	}
	if (Okey == false)
		type = RecType::Other; // �� ������������� � �� ������� - ������
}

// ��������: ����� ����������� - ����� to string
string RectangleClass::OutputResults() const
{
	string ss = "Other";  		//��������� ������������ ��� �� ������
	if (type == RecType::Sqare)
		ss = "Sqare";
	if (type == RecType::Rectangle)
		ss = "Rectangle";
	string s = "Length side a = " + to_string(a) + "\n" + "Length side b = " + to_string(b) + "\n"
		+ "Length Diagonal = " + to_string(d) + "\n"
		+ "COS Angle Rectangle = " + to_string(angle_a) + "\n" + "It's a " + ss + "\n"
		+ "�oordinates 4 point = (" + to_string(x4) + "," + to_string(y4) + ")" + "\n"
		+ "Perimeter = " + to_string(PerimeterAB()) + "\n" + "Square = " + to_string(SquareAB()) + "\n";
	return s;
}

// ������ 1 - ������������� ������������ ��������� �����������
// ������� ������ Test ������ RectangleClass � ������������ (1,1) (4,1) (1,3)
// ��������� ����� � ���� ������ A � B, ��������� D,
// ���������� 4-�� �����, �������� � ������� ��������������
// ����� �������� ���������� �� (1,1) (3,2) (0,3)
// ��������� ���������� 4-�� �����, ������� � ��������
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

	Test.x4 = Test.�oordinateX4();
	assert(Test.x4 == 4);
	Test.y4 = Test.�oordinateY4();
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
	cout << "	Length � = " << Test.b << endl;
	cout << "Angle � = " << Test.angle_a;
	cout << "	Diagonal D = " << Test.d << endl;
	cout << "�oordinate X4 = " << Test.x4;
	cout << "	�oordinate Y4 = " << Test.y4 << endl;
	cout << "Perimeter = " << Test.PerimeterAB();
	cout << "	Square = " << Test.SquareAB() << endl;
	// ����� �������� ���������� �� (1,1) (3,2) (0,3)
	RectangleClass Test1;
	{
		Test1.set_x1(1);			Test1.set_y1(1);
		Test1.set_x2(3);			Test1.set_y2(2);
		Test1.set_x3(0);			Test1.set_y3(3);
	}
	Test1.angle_a = Test1.AngleRectangle();

	cout << "New �oordinate X4 = " << Test1.�oordinateX4();
	cout << "	New �oordinate Y4 = " << Test1.�oordinateY4() << endl;
	cout << "New Perimeter = " << Test1.PerimeterXY();
	cout << "	New Square = " << Test1.SquareXY() << endl;
}

// ������ 2 - ������������� �������������� ������
// ������� ������ 3 �������� Test ������ RectangleClass � ���������� ������������
// ����� ����� ���������� ��������������� � ���������
void Test_RectangleClass2()
{
	RectangleClass Tests[3]{
		RectangleClass(0, 0, 4, 0, 0, 4), // 16 �������
		RectangleClass(1, 1, 4, 1, 1, 3), // 10 �������������
		RectangleClass(1, 2, 3, 1, 1, 5)  // �� �������������
	};
	cout << "Primer 2:" << endl;
	cout << "Test_RectangleClass Primer 2 - successfully OK" << endl;
	double summ = 0;
	string ss = "";
	// ������� ����� ����������
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

// ������ 3 - ������������� ������������ ������ �� ���������
// ������� ������������ ������ Test� ������ RectangleClass 
// ����� ������� ��������������
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

// ������ 4 - ������������� ������ �� ������������ ��������  
// ������� ������ �� 3 ������������ ��������,
// ������� ��� �� �������
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

// ������ 5 - ������������� ��������� � ���� fclass.txt  
// ������� ������ Testmass ������ RectangleClass � ������������ (1,1) (4,1) (1,3)
// ��������� ��� � ���� � ������� � ����� ������ Testmass1
// ������� ������� ��������������
void Test_RectangleClass5()
{
	cout << "Primer 5:" << endl;
	cout << "Test_RectangleClass Primer 5 - successfully OK" << endl;
	string s = "fclass.txt";
	RectangleClass Testmass(1, 1, 4, 1, 1, 3);
	// area before writing to the file - ������� �� ������ � ����
	cout << " area before writing to the file : " << Testmass.SquareXY() << endl;
	// ������ � ����
	ofstream Fout;
	Fout.open(s);
	if (Fout.is_open()) {
		Fout << Testmass.get_x1() << endl << Testmass.get_y1() << endl;
		Fout << Testmass.get_x2() << endl << Testmass.get_y2() << endl;
		Fout << Testmass.get_x3() << endl << Testmass.get_y3() << endl;
	}
	cout << "Write. End of recording" << endl;
	Fout.close();
	// ���������� � �����
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
	// area after reading from file - ������� ����� ������ �� �����
	cout << " area after reading from file : " << Testmass.SquareXY() << endl;
}
