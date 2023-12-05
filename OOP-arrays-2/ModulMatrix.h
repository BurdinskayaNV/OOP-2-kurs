/// \file ModulMatrix.h
/// \brief ������������ ���� ������ ModulMatrix.cpp
/// \brief ������� ������������ ���
/// \author ���������� ������� ���-22
/// \date 20.10.2023

#pragma once
// ����������� ��� ����������� ������� ����� ������������� setw setprecision.
#include <iomanip>
// ��������� ����� �������, �������� � ����� ��� ������ � ����� � ��������
#include <time.h> 
/// ������������� ���������� ��� ���������� ������ �� ����� � ��� ������ � ����.
#include <fstream>
/// ��������� ������� cin cout, ����������� ������� �� ����������� ������� � ������� � ���.
#include <iostream>
/// ����������� ������ C++, ����������� ������������ ������.
// ��� � ��� ����������� ����������, �� ���������� � ������������ ��� std.
#include <vector>
/// ������ ����� ���������� �� ���� ������ ��� �������� std::
using namespace std;
// �������� �������� ��� ���� vector<vector<int>> �������
using vector_int = vector<vector<int>>;
// vector -- �����-������ ��� ������������� �������
// vector -- ��������� �����, ������� ������������ ������� ����
// ��� ��������� � ���� �������� (����� ��� �������� �������). 
// ��� ��������� �������� ����������� ������ ������� ������ 
// < > ��� ���������� ��������� ���� vector
// <vector< >> ������ ������ �������� �������� - �������

// ������������ ���� ��� �������
namespace NamespaceMatrix
{
	// ��������� ���������� �������, �������� N x M, ���������� �������
	vector_int CreateRandomMatrix(vector_int matr, int n, int m);

	// ��������� ������ �� ������� ���������� ������� N � �
	// ��������� ������ �� ����������
	void Print_Vector(const vector_int& matr, int n, int m);

	// ������� �������� ����� ������� N � M, � ������� ������������ ��������
	// �� ����� ����� ������� vector_int &matr
	// �� ������ ����� ������� vector_int &matr, ��������� ������������� ��������
	vector_int Perestanovka(vector_int& matr, int n, int m);
}

// ������������ ���� ��� ������� � �����
namespace NamespaceFile
{
	//��������� ������ ������� matr, �������� N x M, � ���� fmatrix.txt
	void WriteFile(vector_int matr, int n, int m);

	//��������� ���������� ������ ������� matr, �������� N x M, � ���� fmatrix.txt
	void AddFile(vector_int matr, int n, int m);

	// ��������� ������ ������� matr, �������� N x M, �� ����� fmatrix.txt
	vector_int ReadFile(vector_int matr, int n, int m);
}

