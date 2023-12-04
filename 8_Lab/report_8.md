# Отчет по лабораторной работе № 8
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Системы программирования на языке Си
2. **Цель работы**: Изучение конкретной системы программирования на Си и получение навыков подготовки и отладки программы.
3. **Задание**:
- изучить и освоить возможности лабораторной СП по содержащейся в практикуме документации и другим источникам, в том числе основные этапы процесса компиляции и подготовки программы к выполнению.
- составить и отладить простейшую программу на Си в терминальном классе.
- Изучить различные СП на Си на другой платформе: Visual Studio Code
4. **Идея, метод, алгоритм решения задачи**:
- Воспользуемся текстовым редактором emacs для написания простейшего кода.
- Скомпилируем и запустим этот код в терминале Linux.
- Напишем, скомпилируем и запустим этот же код в СП Visual Studio Code.
5. **Сценарий выполнения работы**:
- Скачаем emacs с помощью команды `sudo apt install` в терминале Linux.
```bash
sudo apt install emacs
```
- Создадим и откроем файл `lab8.c` с помощью команды `emacs`.
```bash
emacs lab8.c
```
- Запишем простейший код в этот файл
- Скомпилируем эту программу с помощью команды `cc`.
```bash
сс lab8.c
```
- Устраним синтаксические ошибки в программе.
- Запустим файл `a.out`, содержащий вывод исходной программы.
```bash
./a.out
```
- Запишем и скомпилируем тот же код в СП Visual Studio Code.
6. **Протокол**:
```bash
ivan@ivan-ASUS:~$ cc lab8.c
cc1: fatal error: lab8.c: Нет такого файла или каталога
compilation terminated.
ivan@ivan-ASUS:~$ emacs lab8.c
ivan@ivan-ASUS:~$ cd
ivan@ivan-ASUS:~$ ls
 fff        README.md   Видео       Изображения    'Рабочий стол'
 Inf_Labs   snap        Документы   Музыка          Шаблоны
 lab8.c~    turing      Загрузки    Общедоступные
ivan@ivan-ASUS:~$ cd Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ ls
1_Lab  2_Lab  5_Lab  6_Lab  7_Lab  8_Lab  README.md
ivan@ivan-ASUS:~/Inf_Labs$ cd 8_Lab
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ cd
ivan@ivan-ASUS:~$ ls
 fff        README.md   Видео       Изображения    'Рабочий стол'
 Inf_Labs   snap        Документы   Музыка          Шаблоны
 lab8.c~    turing      Загрузки    Общедоступные
ivan@ivan-ASUS:~$ cd Inf_Labs
ivan@ivan-ASUS:~/Inf_Labs$ cd 8_Lab
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ ls
lab8.c
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ gcc -std=c99 -Wall -pedantic lab8.c
lab8.c: In function ‘main’:
lab8.c:4:28: error: expected ‘;’ before ‘return’
    4 |   printf("Hello, Charles!")
      |                            ^
      |                            ;
    5 |     return 0;
      |     ~~~~~~                  
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ emacs lab8.c
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ gcc -std=c99 -Wall -pedantic lab8.c
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ ./a.out
Hello, Charles!ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ ls
a.out  lab8.c  lab8.c~  studuo_test  studuo_test.c
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ ./studio_test
bash: ./studio_test: Нет такого файла или каталога
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ ./a.out
Hello, Charles!ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ cat lab8.c
#include <stdio.h>

int main(){
  printf("Hello, Charles!");
    return 0;
}
ivan@ivan-ASUS:~/Inf_Labs/8_Lab$ 
```
7. **Замечания автора**: Отсутсвуют.
8. **Выводы**: В ходе выполнения лабораторной работы я познакомился с методом программирования на Си в терминальном классе Linux. Я также научился создавать и компилировать программы на Си в СП Visual Studio Code. Эти знания могут быть полезными при написании простых и продвинутых программ на Си.
