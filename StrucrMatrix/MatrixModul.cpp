/// \file MatrixModul.cpp
/// \brief cpp-файл модуль MatrixModul.cpp
/// \brief Класс матрица
/// \author Бурдинская Наталья ВМК-22
/// \date 15.11.2023

// вызов заголовочного файла модуля MatrixModul.cpp
#include "MatrixModul.h"

// Получение матрицы путём удаление id строки и jd столбца
MatrixClass MatrixClass::Del_Line_Column(const MatrixClass* MainMatr, int id, int jd) const {
	MatrixClass result(MainMatr->Get_Line() - 1, MainMatr->Get_Column() - 1);
	for (int i = 0; i < MainMatr->Get_Line(); i++)
	{
		for (int j = 0; j < MainMatr->Get_Column(); j++)
		{
			if (i < id && j < jd) { result.Set_Element(i, j, MainMatr->Get_Element(i, j)); };
			if (i < id && j > jd) { result.Set_Element(i, j - 1, MainMatr->Get_Element(i, j)); };
			if (i > id && j < jd) { result.Set_Element(i - 1, j, MainMatr->Get_Element(i, j)); };
			if (i > id && j > jd) { result.Set_Element(i - 1, j - 1, MainMatr->Get_Element(i, j)); };
		}
	}
	return result;
}

// Проверка того, чтобы строки и столбцы были неотрицательными
bool MatrixClass::Nonnegative_Line_Column(int line, int column) const {
	if (line >= 0 && column >= 0) return true;
	else {
		throw std::runtime_error("Недопустимые значения для строк и/или столбцов");
		return false;
	}
}

// Проверка того, чтобы количество строк и столбцов матриц было одинаково
// (для операторов *=, -=, +=)
bool MatrixClass::Line_Equality_Column(const MatrixClass& Matrix) const {
	if (MatrixVector.size() == Matrix.Get_Line() && MatrixVector[0].size() == Matrix.Get_Column()) return true;
	else {
		throw std::runtime_error("Количество строк и столбцов матриц должны быть одинаковы");
		return false;
	}
}

// Установка новых размеров строк и столбцов
void MatrixClass::New_Line_Column(int line, int column) {
	MatrixVector.resize(line);
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		MatrixVector[i].resize(column);
	}
}

// Конструктор матрицы
MatrixClass::MatrixClass() {
	New_Line_Column(2, 2);
}

// Конструктор матрицы с параметрами строка и столбец
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

// геттеры элементов матрицы
// const т.к. метод не меняет значений полей
// Операция: получение элемента [n][m] матрицы
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

// Операция: получение количества строк
int MatrixClass::Get_Line() const {
	return MatrixVector.size();
}

// Операция: получение количества столбцов
int MatrixClass::Get_Column() const {
	return MatrixVector[0].size();
}

// Операция: получение матрицы
void MatrixClass::Get_Matrix() const {
	cout.precision(4);
	cout << endl;
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			cout << setfill(' ') << setw(8) << fixed << setprecision(2) << MatrixVector[i][j];
		}
		cout << endl;
	}
}

// сеттеры элементов матрицы
// Операция: ввод количества строк и столбцов
void MatrixClass::Set_Line_Column(int line, int column) {
	try {
		if (Nonnegative_Line_Column(line, column)) {
			New_Line_Column(line, column);
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
	}
}

// Операция: ввод количества строк
void MatrixClass::Set_Line(int line) {
	MatrixVector.resize(line);
}

// Операция: ввод количества столбцов
void MatrixClass::Set_Column(int column) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		MatrixVector[i].resize(column);
	}
}

// Операция: ввод нового [n][m] элемента матрицы
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
// Операция: заполнение матрицы одним значением deft
void MatrixClass::Matrix_Default(double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = deft;
		}
	}
}

// Операция: заполнить матрицу случайными значениями от min до max
void MatrixClass::Matrix_Random(double min, double max) {
	// Генерирует случайное число, используя текущею дату, для непредсказуемости результата
	srand(time(0)); // инициализация генератора случайных чисел текущим временем в секундах time
		for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			// целые числа
			MatrixVector[i][j] = (1.0 * rand() / RAND_MAX * (max - min) + min);
			//MatrixVector[i][j] = 1.0 * (rand() % 10) * (max - min) + min;
			// вещественные числа
			//MatrixVector[i][j] = 1.0 * rand() / RAND_MAX * (max - min) + min;
		}
	}
}

// Операция: сложение матриц 
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

// Операция: сложение матрицы с числом deft
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

// Операция: вычитание матриц
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

// Операция: вычитание матрицы с числом deft
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

// Операция: умножение матрицы на число deft
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

// Операция: умножение матрицы на матрицу
MatrixClass MatrixClass::operator* (const MatrixClass& Matrix) const {
	MatrixClass result(MatrixVector.size(), Matrix.Get_Column());
	try {
		if (MatrixVector[0].size() == Matrix.Get_Line()) {
			double sum;
			for (int i = 0; i < MatrixVector.size(); i++)
			{
				for (int j = 0; j < Matrix.Get_Column(); j++)
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

// Операция: собственное умножение матрицы на матрицу
void MatrixClass::operator*= (const MatrixClass& Matrix) {
	MatrixClass Betta(MatrixVector.size(), MatrixVector[0].size());
	MatrixClass result(MatrixVector.size(), Matrix.Get_Column());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			Betta.Set_Element(i, j, MatrixVector[i][j]);
		}
	}
	result = Betta * Matrix;
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = result.Get_Element(i, j);
		}
	}
	Betta.~MatrixClass();
	result.~MatrixClass();
}

// Операция: собственное умножение матрицы на число deft
void MatrixClass::operator*= (double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = MatrixVector[i][j] * deft;
		}
	}
}

// Операция: собственное вычитание матриц
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

// Операция: собственное вычитание числа deft из матрицы
void MatrixClass::operator-= (double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = MatrixVector[i][j] - deft;
		}
	}
}

// Операция: собственное сложение матриц
void MatrixClass::operator+= (const MatrixClass& Matrix) {
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

// Операция: собственное сложение числа deft с матрицей
void MatrixClass::operator+= (double deft) {
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			MatrixVector[i][j] = MatrixVector[i][j] + deft;
		}
	}
}

// Операция: транспонирование матрицы
MatrixClass MatrixClass::Trans_Matrix() const {
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

// Операция: диагональная матрица
MatrixClass MatrixClass::Diagonal_Matrix() const {

	MatrixClass result(MatrixVector[0].size(), MatrixVector.size());
	for (int i = 0; i < MatrixVector.size(); i++)
	{
		for (int j = 0; j < MatrixVector[0].size(); j++)
		{
			if (i == j) result.Set_Element(i, j, MatrixVector[i][j]);
		}
	}
	return result;
}

// Операция: поиск определителя матрицы и ранга
double MatrixClass::Determinant(int rang) const {
	if (!(this->Get_Line() == this->Get_Column())) cout << "Для поиска определителя матрица должны быть квадратной";
	else {
		if (rang == 1) return this->Get_Element(0, 0);
		else if (rang == 2) return this->Get_Element(0, 0) * this->Get_Element(1, 1) - this->Get_Element(0, 1) * this->Get_Element(1, 0);
		else {
			double Det = 0;
			for (int i = 0; i < rang; i++)
			{
				MatrixClass Between = Del_Line_Column(this, 0, i);
				Det = Det + pow(-1, i + 1 + 1) * this->Get_Element(0, i) * Between.Determinant(rang - 1);
				Between.~MatrixClass();
			}
			return Det;
		}

	}
}

// Операция: построение обратной матрицы
MatrixClass MatrixClass::Inverse_Matrix() const {
	if (!(MatrixVector.size() == MatrixVector[0].size())) cout << "Для поиска обратной матрицы, матрица должна быть квадратной";
	else if (Determinant(this->Get_Line()) == 0) cout << "Матрица не имеет обратную, определитель = 0";
	else {
		MatrixClass Obrat(this->Get_Line(), this->Get_Line());
		for (int i = 0; i < this->Get_Line(); i++)
		{
			for (int j = 0; j < this->Get_Column(); j++)
			{
				MatrixClass Betta = Del_Line_Column(this, i, j);
				Obrat.Set_Element(i, j, Betta.Determinant(Betta.Get_Column()) * pow(-1, i + j + 2));
				Betta.~MatrixClass();
			}
		}
		Obrat = Obrat.Trans_Matrix();
		return Obrat * (1 / Determinant(this->Get_Line()));
	}
}

// Деструктор класса матрица
MatrixClass::~MatrixClass() {
	MatrixVector.clear();
}
