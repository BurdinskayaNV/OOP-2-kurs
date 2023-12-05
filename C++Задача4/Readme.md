# C++ Задача 4 Компиляция в командной строке
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
