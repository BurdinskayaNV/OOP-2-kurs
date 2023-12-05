// Бурдинская Наталья – Заголовочный файл модуля Modul_zd3_massiv1.cpp

// функция выделение памяти для двумерного массива N х М
int** Memo_Mass(unsigned n, unsigned m);

// процедура ввода двумерного массива N х М
void Vvod_Mass(int** a, unsigned n, unsigned m);

// процедура вывода на экран двумерного массива N х М
void Screen_Mass(int** a, unsigned n, unsigned m);

// функция создание новой матрицы N х М, с помощью перестановок столбцов
int** Perestanovka_Mass(int** a, unsigned n, unsigned m);

// функция освобождение памяти двумерного массива N х М
void Del_Mass(int** a, unsigned n, unsigned m);

