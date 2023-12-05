# OOP-2-kurs
## Практические работы ООП за 2 курс
### 1. C++ Задача 4 Компиляция в командной строке
- Решена задача из первого раздела задачника вариант 4 номер 4.
Даны два действительных положительных числа. Найти среднее арифметическое и среднее геометрическое этих чисел. Компиляция в командной строке в PowerShell
>     cd c:\2курс\1модуль
> 
>     g++ zd2_number4.cpp -o zd2_number4.exe
> 
>     ./zd2_number4.exe

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/44104e02-6173-414f-ad46-3ed2976cf3f6)

-  Создано две отдельные функции для вычислений среднего арифметического и среднего геометрического чисел. Есть комментарии и документирование кода.
- Вынесены функции вычислений в отдельный модуль modul_number4.cpp и его заголовочный файл modul_number4.h. Компиляция в командной строке в PowerShell  несколько файлов.
>     g++ zd2_number4.cpp modul_number4.cpp -o zd2_number4.exe
> 
>     ./zd2_number4.exe

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/b059b4cd-544d-4428-9c2c-0e25ceee9ab4)

- Скомпилируйте modul_number4.cpp файл модуля в статическую библиотеку lib/modul_number4.o
>      md /2курс/1модуль/lib
> 
>      g++ -c modul_number4.cpp -o lib/modul_number4.o
> 
>      ar rcs lib/modul_number4.a lib/modul_number4.o
> 
>      g++ zd2_number4111.cpp lib/modul_number4.a -o zd2_number4111.exe
> 
>      ./zd2_number4111.exe

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/7c4ab8c1-dab2-4523-a5d9-9c121ee68808)

- Сделано автоматическое тестирование программы с помощью макроса assert

![image](https://github.com/BurdinskayaNV/OOP-2-kurs/assets/148595309/caab6e43-2422-4183-97d0-729b12288e8e)

### 2. C++ Задачи 136в одномерный массив и 676а двумерный массив. Компиляция в командной строке.
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
