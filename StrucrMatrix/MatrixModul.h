/// \file MatrixModul.h
/// \brief ������������ ���� ������ MatrixModul.cpp
/// \brief ����� �������
/// \author ���������� ������� ���-22
/// \date 15.11.2023

//��������� cin cout, ����������� ������� �� �����.������� � ������� � ���
#include <iostream>
// ������ � �������
#include <fstream>
// ���������� ������� setlocale ��� ��������� ������� ������ � �������� ��������� �� ������� �����
#include <locale>
#include <cmath>  // ������ � ��������������� ����������� � ���������
#include <cassert> // ��� assert
#include <iomanip> // ��� ����������� ������� ����� ������������� setw setprecision
#include <string> // ��� ������ �� ��������
#include <vector> // ����� ��������
// ������ ����� ���������� �� ���� ������, ��������� � std, ���������������, ��� �������� std::
using namespace std;

// ����� - ������� MatrixClass
class MatrixClass {
private:
	// ���� ������ ��� ����� vector ��������� ������
	vector <vector <double> > MatrixVector;

	// ��������� ������� ���� �������� id ������ � jd �������
	MatrixClass Del_Line_Column(MatrixClass MainMatr, int id, int jd) const;

	// �������� ����, ����� ������ � ������� ���� ����������������
	bool Nonnegative_Line_Column(int line, int column) const;

	// �������� ����, ����� ���������� ����� � �������� ������ ���� ���������
	// (��� ���������� *=, -=, +=)
	bool Line_Equality_Column(const MatrixClass& Matrix) const;

	// ��������� ����� �������� ����� � ��������
	void New_Line_Column(int line, int column);

public:
	// ����������� �������
	MatrixClass();
	// ����������� ������� � ����������� ������ � �������
	MatrixClass(int line, int column);

	// ������� ��������� �������
	// const �.�. ����� �� ������ �������� �����
	// ��������: ��������� �������� [n][m] �������
	float Get_Element(int n, int m) const;
	// ��������: ��������� ���������� �����
	int Get_Line() const;
	// ��������: ��������� ���������� ��������
	int Get_Column() const;
	// ��������: ��������� �������
	void Get_Matrix() const;

	// ������� ��������� �������
	// ��������: ���� ���������� ����� � ��������
	void Set_Line_Column(int line, int column);
	// ��������: ���� ���������� �����
	void Set_Line(int line);
	// ��������: ���� ���������� ��������
	void Set_Column(int column);
	// ��������: ���� ������ [n][m] �������� �������
	void Set_Element(int line, int column, double deft);

	// ��������: ���������� ������� ����� ��������� deft
	void Matrix_Default(double deft);
	// ��������: ��������� ������� ���������� ���������� �� min �� max
	void Matrix_Random(double min, double max);

	// ��������: �������� ������ 
	MatrixClass operator+ (const MatrixClass& Matrix) const;
	// ��������: �������� ������� � ������ deft
	MatrixClass operator+ (double deft) const;

	// ��������: ��������� ������
	MatrixClass operator- (const MatrixClass& Matrix) const;

	// ��������: ��������� ������� � ������ deft
	MatrixClass operator- (double deft) const;

	// ��������: ��������� ������� �� ����� deft
	MatrixClass operator* (double deft) const;

	// ��������: ��������� ������� �� �������
	MatrixClass operator* (const MatrixClass& Matrix)const;

	// ��������: ����������� ��������� ������� �� �������
	void operator*= (const MatrixClass& Matrix);

	// ��������: ����������� ��������� ������� �� ����� deft
	void operator*= (double deft);

	// ��������: ����������� ��������� ������
	void operator-= (const MatrixClass& Matrix);

	// ��������: ����������� ��������� ����� deft �� �������
	void operator-= (double deft);

	// ��������: ����������� �������� ������
	void operator+= (MatrixClass Matrix);

	// ��������: ����������� �������� ����� deft � ��������
	void operator+= (double deft);

	// ��������: ���������������� �������
	MatrixClass Trans_Matrix();

	// ��������: ������������ �������
	void Diagonal_Matrix();

	// ��������: ����� ������������ ������� � �����
	double Determinant(MatrixClass Matr, int rang) const;

	// ��������: ���������� �������� �������
	MatrixClass Inverse_Matrix(MatrixClass Matr) const;

	// ���������� ������ �������
	~MatrixClass();
};
