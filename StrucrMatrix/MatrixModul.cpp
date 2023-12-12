/// \file MatrixModul.cpp
/// \brief cpp-���� ������ MatrixModul.cpp
/// \brief ����� �������
/// \author ���������� ������� ���-22
/// \date 15.11.2023

// ����� ������������� ����� ������ MatrixModul.cpp
#include "MatrixModul.h"

// ��������� ������� ���� �������� id ������ � jd �������
MatrixClass MatrixClass::Del_Line_Column(MatrixClass MainMatr, int id, int jd) const {
	MatrixClass result(MainMatr.Get_Line() - 1, MainMatr.Get_Column() - 1);
	for (int i = 0; i < MainMatr.Get_Line(); i++)
	{
		for (int j = 0; j < MainMatr.Get_Column(); j++)
		{
			if (i < id && j < jd) { result.Set_Element(i, j, MainMatr.Get_Element(i, j)); };
			if (i < id && j > jd) { result.Set_Element(i, j - 1, MainMatr.Get_Element(i, j)); };
			if (i > id && j < jd) { result.Set_Element(i - 1, j, MainMatr.Get_Element(i, j)); };
			if (i > id && j > jd) { result.Set_Element(i - 1, j - 1, MainMatr.Get_Element(i, j)); };
		}
	}
	return result;
}

// �������� ����, ����� ������ � ������� ���� ����������������
bool MatrixClass::Nonnegative_Line_Column(int line, int column) const {
	if (line >= 0 && column >= 0) return true;
	else {
		throw std::runtime_error("������������ �������� ��� ����� �/��� ��������");
		return false;
	}
}

// �������� ����, ����� ���������� ����� � �������� ������ ���� ���������
// (��� ���������� *=, -=, +=)
bool MatrixClass::Line_Equality_Column(const MatrixClass& Matrix) const {
	if (MatrixVector.size() == Matrix.Get_Line() && MatrixVector[0].size() == Matrix.Get_Column()) return true;
	else {
		throw std::runtime_error("���-�� ����� � �������� ������ ������ ���� ���������");
		return false;
	}
}

// ��������� ����� �������� ����� � ��������
void MatrixClass::New_Line_Column(int line, int column) {
	MatrixVector.resize(line);
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		MatrixVector[i].resize(column);
	}
}

// ����������� �������
MatrixClass::MatrixClass() {
	New_Line_Column(2, 2);
}

// ����������� ������� � ����������� ������ � �������
MatrixClass::MatrixClass(int line, int column) {
	try {
		if (Nonnegative_Line_Column(line, column)) {
			New_Line_Column(line, column);
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		New_Line_Column(2, 2);
	}
}

// ������� ��������� �������
// const �.�. ����� �� ������ �������� �����
// ��������: ��������� �������� [n][m] �������
float MatrixClass::Get_Element(int n, int m) const {
	try {
		if (Nonnegative_Line_Column(n, m)) {
			return MatrixVector[n][m];
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// ��������: ��������� ���������� �����
int MatrixClass::Get_Line() const {
	return MatrixVector.size();
}

// ��������: ��������� ���������� ��������
int MatrixClass::Get_Column() const {
	return MatrixVector[0].size();
}

// ��������: ��������� �������
void MatrixClass::Get_Matrix() const {
	cout.precision(4);
	cout << endl;
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			cout << setw(12) << fixed << setprecision(3) << MatrixVector[i][j];
		}
		cout << endl;
	}
}

// ������� ��������� �������
// ��������: ���� ���������� ����� � ��������
void MatrixClass::Set_Line_Column(int line, int column) {
	try {
		if (Nonnegative_Line_Column(line, column)) {
			New_Line_Column(line, column);
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		//new_line_column(2, 2);
	}
}

// ��������: ���� ���������� �����
void MatrixClass::Set_Line(int line) {
	MatrixVector.resize(line);
}

// ��������: ���� ���������� ��������
void MatrixClass::Set_Column(int column) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		MatrixVector[i].resize(column);
	}
}

// ��������: ���� ������ [n][m] �������� �������
void MatrixClass::Set_Element(int line, int column, double deft) {
	try {
		if (Nonnegative_Line_Column(line, column)) {
			MatrixVector[line][column] = deft;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}
// ��������: ���������� ������� ����� ��������� deft
void MatrixClass::Matrix_Default(double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = deft;
		}
	}
}

// ��������: ��������� ������� ���������� ���������� �� min �� max
void MatrixClass::Matrix_Random(double min, double max) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			// ����� �����
			MatrixVector[i][j] = 1.0 * (rand() % 10) * (max - min) + min;
			// ������������ �����
			//MatrixVector[i][j] = 1.0 * rand() / RAND_MAX * (max - min) + min;
		}
	}
}

// ��������: �������� ������ 
MatrixClass MatrixClass::operator+ (const MatrixClass& Matrix) const {
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	try {
		if (Line_Equality_Column(Matrix)) {
			for (int i = 0; i < MatrixVector.size(); i++)
			{
				for (int j = 0; j < MatrixVector[0].size(); j++)
				{
					result.Set_Element(i, j, MatrixVector[i][j] + Matrix.Get_Element(i, j));
				}
			}
			return result;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return result;
	}
}

// ��������: �������� ������� � ������ deft
MatrixClass MatrixClass::operator+ (double deft) const {
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			result.Set_Element(i, j, MatrixVector[i][j] + deft);
		}
	}
	return result;
}

// ��������: ��������� ������
MatrixClass MatrixClass::operator- (const MatrixClass& Matrix) const {
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	try {
		if (Line_Equality_Column(Matrix)) {
			for (int i = 0; i < MatrixVector.size(); i++)
			{
				for (int j = 0; j < MatrixVector[0].size(); j++)
				{
					result.Set_Element(i, j, MatrixVector[i][j] - Matrix.Get_Element(i, j));
				}
			}
			return result;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return result;
	}
}

// ��������: ��������� ������� � ������ deft
MatrixClass MatrixClass::operator- (double deft) const {
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			result.Set_Element(i, j, MatrixVector[i][j] - deft);
		}
	}
	return result;
}

// ��������: ��������� ������� �� ����� deft
MatrixClass MatrixClass::operator* (double deft) const {
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			result.Set_Element(i, j, MatrixVector[i][j] * deft);
		}
	}
	return result;
}

// ��������: ��������� ������� �� �������
MatrixClass MatrixClass::operator* (const MatrixClass& Matrix) const {
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	try {
		if (Line_Equality_Column(Matrix)) {
			double sum;
			for (int i = 0; i < MatrixVector.size(); i++)
			{
				for (int j = 0; j < MatrixVector[0].size(); j++)
				{
					sum = 0;
					for (int n = 0; n < MatrixVector[0].size(); n++)
					{
						sum = sum + MatrixVector[i][n] * Matrix.Get_Element(n, j);
					}
					result.Set_Element(i, j, sum);
				}
			}
			return result;
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return result;
	}
}

// ��������: ����������� ��������� ������� �� �������
void MatrixClass::operator*= (const MatrixClass& Matrix) {
	MatrixClass between(MatrixVector.size(), MatrixVector[0].size());
	MatrixClass result(MatrixVector.size(), MatrixVector[0].size());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			between.Set_Element(i, j, MatrixVector[i][j]);
		}
	}
	result = between * Matrix;
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = result.Get_Element(i, j);
		}
	}
	between.~MatrixClass();
	result.~MatrixClass();
}

// ��������: ����������� ��������� ������� �� ����� deft
void MatrixClass::operator*= (double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = MatrixVector[i][j] * deft;
		}
	}
}

// ��������: ����������� ��������� ������
void MatrixClass::operator-= (const MatrixClass& Matrix) {
	try {
		if (Line_Equality_Column(Matrix)) {
			for (int i = 0; i < MatrixVector.size(); i++)
			{
				for (int j = 0; j < MatrixVector[0].size(); j++)
				{
					MatrixVector[i][j] = MatrixVector[i][j] - Matrix.Get_Element(i, j);
				}
			}
		}

	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// ��������: ����������� ��������� ����� deft �� �������
void MatrixClass::operator-= (double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = MatrixVector[i][j] - deft;
		}
	}
}

// ��������: ����������� �������� ������
void MatrixClass::operator+= (MatrixClass Matrix) {
	try {
		if (Line_Equality_Column(Matrix)) {
			for (int i = 0; i < MatrixVector.size(); i++)
			{
				for (int j = 0; j < MatrixVector[0].size(); j++)
				{
					MatrixVector[i][j] = MatrixVector[i][j] + Matrix.Get_Element(i, j);
				}
			}
		}

	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// ��������: ����������� �������� ����� deft � ��������
void MatrixClass::operator+= (double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = MatrixVector[i][j] + deft;
		}
	}
}

// ��������: ���������������� �������
MatrixClass MatrixClass::Trans_Matrix() {
	MatrixClass result(MatrixVector[0].size(), MatrixVector.size());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			result.Set_Element(i, j, MatrixVector[j][i]);
		}
	}
	return result;
}

// ��������: ������������ �������
void MatrixClass::Diagonal_Matrix() {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			if (!(i == j)) MatrixVector[i][j] = 0;
		}
	}
}

// ��������: ����� ������������ ������� � �����
double MatrixClass::Determinant(MatrixClass Matr, int rang) const {
	if (!(Matr.Get_Line() == Matr.Get_Column())) cout << "��� ������ ������������ ������� ������ ���� ����������";
	else {
		if (rang == 1) return Matr.Get_Element(0, 0);
		else if (rang == 2) return Matr.Get_Element(0, 0) * Matr.Get_Element(1, 1) - Matr.Get_Element(0, 1) * Matr.Get_Element(1, 0);
		else {
			double Det = 0;
			for (int i = 0; i < rang; i++)
			{
				MatrixClass Between = Del_Line_Column(Matr, 0, i);
				Det = Det + pow(-1, i + 1 + 1) * Matr.Get_Element(0, i) * Determinant(Between, rang - 1);
				Between.~MatrixClass();
			}
			return Det;
		}

	}
}

// ��������: ���������� �������� �������
MatrixClass MatrixClass::Inverse_Matrix(MatrixClass Matr) const {
	if (!(MatrixVector.size() == MatrixVector[0].size())) cout << "��� ������ �������� �������, ������� ������ ���� ����������";
	else if (Determinant(Matr, Matr.Get_Line()) == 0) cout << "������� �� ����� ��������, ������������ = 0";
	else {
		MatrixClass Minor(Matr.Get_Line(), Matr.Get_Line());
		for (int i = 0; i < Matr.Get_Line(); i++)
		{
			for (int j = 0; j < Matr.Get_Column(); j++)
			{
				MatrixClass Between = Del_Line_Column(Matr, i, j);
				Minor.Set_Element(i, j, Determinant(Between, Between.Get_Column()) * pow(-1, i + j + 2));
				Between.~MatrixClass();
			}
		}
		Minor = Minor.Trans_Matrix();
		return Minor * (1 / Determinant(Matr, Matr.Get_Line()));
	}
}

// ���������� ������ �������
MatrixClass::~MatrixClass() {
	MatrixVector.clear();
}