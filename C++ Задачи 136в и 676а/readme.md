# C++ Задачи 136в одномерный массив и 676а двумерный массив. Компиляция в командной строке.
- Решена задача из первого раздела задачника вариант 4 номер 136в.
Даны натуральное число n, действительные числа a1,..., an. Вычислить: в) |a1| + ... + |an|. Компиляция в командной строке в PowerShell
>     cd c:\2курс\массив
> 
>     g++ zd3_massiv.cpp -o zd3_massiv.exe
> 
>     ./zd3_massiv.exe

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/f273093b-b7b7-499b-98f9-c47484d14e4a)

- Сделано автоматическое тестирование программы с помощью макроса assert

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/543dd762-79bc-4043-9394-b5cea9932f32)

-  Решена задача из первого раздела задачника вариант 4 номер 676а.
Дана целочисленная матрица размера 6х9. Найти матрицу получающуюся из данной:
a) перестановкой столбцов - первого с последним, второго с предпоследним и т.д.
Созданы отдельные функции для выделения динамической памяти, создание новой матрицы путем перестановки столбцов, освобождение памяти матрицы, процедуры заполнения матрицы случайными числами и вывод на экран. Есть комментарии и документирование кода.
- Вынесены функции и процедуры в отдельный модуль Modul_zd3_massiv1.cpp и его заголовочный файл Modul_zd3_massiv1.h. Компиляция в командной строке в PowerShell  несколько файлов.
>     g++ zd3_massiv1.cpp Modul_zd3_massiv1.cpp -o zd3_massiv1.exe
> 
>     ./zd3_massiv1.exe

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/63eb682e-f2b6-4f4c-bfee-29968ccc98b4)

- Скомпилируйте Modul_zd3_massiv1.cpp файл модуля в статическую библиотеку lib/Modul_zd3_massiv1.o
>      md /2курс/массив/lib
> 
>      g++ -c Modul_zd3_massiv1.cpp -o lib/Modul_zd3_massiv1.o
> 
>      ar rcs lib/Modul_zd3_massiv1.a lib/Modul_zd3_massiv1.o
> 
>      g++ zd3_massiv1.cpp lib/Modul_zd3_massiv1.a -o zd3_massiv111.exe
> 
>      ./zd3_massiv111.exe

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/42522a9c-6aaa-4bd2-bd7c-3b51dc42b898)
![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/559b6373-07e0-48bb-8d3f-ed942d40fb2a)

