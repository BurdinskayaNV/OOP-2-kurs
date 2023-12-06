// Бурдинская Наталья – cpp-файл модуля modul_number4.cpp
#include "modul_number4.h" // вызов заголовочного файла модуля 

//Средняя арифметическая прогрессия - функция sa
float SredArif(float a, float b)
{
   return 0.5*(a+b);  // Возврат значения из функции
}

//Средняя геометрическая прогрессия - функция sg
float SredGeom(float a, float b)
{
   return sqrt(a*b);  // Возврат значения из функции
}

// проверка работы функции SredArif на разных входных данных
float Test_SredArif()
{
   assert( SredArif ( 2, 4) == 3);  // если внутри оператора assert будет ЛОЖЬ, то программа аварийно завершит работу
   assert( SredArif ( 5, 5) == 5);
   assert( SredArif ( 9, 4) == 6.5);
   cout << "test SredArif - OK" << endl;
   return 0;
}

// проверка работы функции SredGeom на разных входных данных
float Test_SredGeom()
{
   assert( SredGeom ( 2, 8) == 4);  // если внутри оператора assert будет ЛОЖЬ, то программа аварийно завершит работу
   assert( SredGeom ( 5, 5) == 5);
   assert( SredGeom ( 3.6, 2.5) == 3);
   cout << "test SredGeom - OK" << endl;
   return 0;
}
