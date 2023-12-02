# Отчет по лабораторной работе № 11
## по курсу "Фундаментальная информатика"

Студент группы М80-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Обработка последовательности литер входного текстового файла. Простейшие приёмы лексического анализа. Диаграммы состояний и переходов.
2. **Цель работы**: Ознакомиться с конечными автоматами и их реализацией на языке Си.Составить программу на языке Си, выполняющую анализ и обработку вводимого текста в соответствии с выданным преподавателем вариантом задания. В программе не должно быть ограничений на количество и длину строк исходного текста.
3. **Задание**:
- Выделить все десятичные числа от 17 до 77 по модулю и распечатать их значения в словесной форме по-русски.
4. **Идея, метод, алгоритм решения задачи**: 
-Будем использовать состояния для обработки очередного знака входного файла.
5. **Сценарий выполнения работы**: 
- Выделим состояние обработки первой цифры числа. 
- Если текущий знак действительно является цифрой и является началом очередного слова, (или перед этим знаком был знак '+' или '-', являющийся началом слова) то перейдём к состояниям, которые обрабатывают второую цифру числа.
- В состоянии под номером 1 будем ждать начала очередного подходящего числа.
6. **Протокол**:
```
#include <stdio.h>
#include <string.h>
int main(void){
    int state = 2;
    int symbol;
    char *s;
    while ((symbol = getchar()) != EOF){
        switch (state) {
            case 1:
                if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                break;
            case 2:
                if (symbol == '1'){
                    state = 10;
                }
                else if (symbol == '2'){
                    state = 20;
                }
                else if (symbol == '3'){
                    state = 30;
                }
                else if (symbol == '4'){
                    state = 40;
                }
                else if (symbol == '5'){
                    state = 50;
                }
                else if (symbol == '6'){
                    state = 60;
                }
                else if (symbol == '7'){
                    state = 70;
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else if (symbol == '-' || symbol == '+'){
                    state = 3;
                }
                else{
                    state = 1;
                }
                break;
            case 3:
                if (symbol == '1'){
                    state = 10;
                }
                else if (symbol == '2'){
                    state = 20;
                }
                if (symbol == '3'){
                    state = 30;
                }
                else if (symbol == '4'){
                    state = 40;
                }
                else if (symbol == '5'){
                    state = 50;
                }
                else if (symbol == '6'){
                    state = 60;
                }
                else if (symbol == '7'){
                    state = 70;
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 10:
                if (symbol == '7'){
                    state = 999;
                    s = "Семнадцать";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Восемнадцать";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Девятнадцать";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 20:
                if (symbol == '0'){
                    state = 999;
                    s = "Двадцать";
                }
                else if (symbol == '1'){
                    state = 999;
                    s = "Двадцать один";
                }
                else if (symbol == '2'){
                    state = 999;
                    s = "Двадцать два";
                }
                else if (symbol == '3'){
                    state = 999;
                    s = "Двадцать три";
                }
                else if (symbol == '4'){
                    state = 999;
                    s = "Двадцать четыре";
                }
                else if (symbol == '5'){
                    state = 999;
                    s = "Двадцать пять";
                }
                else if (symbol == '6'){
                    state = 999;
                    s = "Двадцать шесть";
                }
                else if (symbol == '7'){
                    state = 999;
                    s = "Двадцать семь";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Двадцать восемь";
                }
                else if (symbol == '9'){
                    state = 999;
                    s = "Двадцать девять";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 30:
                if (symbol == '0'){
                    state = 999;
                    s = "Тридцать";
                }
                else if (symbol == '1'){
                    state = 999;
                    s = "Тридцать один";
                }
                else if (symbol == '2'){
                    state = 999;
                    s = "Тридцать два";
                }
                else if (symbol == '3'){
                    state = 999;
                    s = "Тридцать три";
                }
                else if (symbol == '4'){
                    state = 999;
                    s = "Тридцать четыре";
                }
                else if (symbol == '5'){
                    state = 999;
                    s = "Тридцать пять";
                }
                else if (symbol == '6'){
                    state = 999;
                    s = "Тридцать шесть";
                }
                else if (symbol == '7'){
                    state = 999;
                    s = "Тридцать семь";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Тридцать восемь";
                }
                else if (symbol == '9'){
                    state = 999;
                    s = "Тридцать девять";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 40:
                if (symbol == '0'){
                    state = 999;
                    s = "Сорок";
                }
                else if (symbol == '1'){
                    state = 999;
                    s = "Сорок один";
                }
                else if (symbol == '2'){
                    state = 999;
                    s = "Сорок два";
                }
                else if (symbol == '3'){
                    state = 999;
                    s = "Сорок три";
                }
                else if (symbol == '4'){
                    state = 999;
                    s = "Сорок четыре";
                }
                else if (symbol == '5'){
                    state = 999;
                    s = "Сорок пять";
                }
                else if (symbol == '6'){
                    state = 999;
                    s = "Сорок шесть";
                }
                else if (symbol == '7'){
                    state = 999;
                    s = "Сорок семь";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Сорок восемь";
                }
                else if (symbol == '9'){
                    state = 999;
                    s = "Сорок девять";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 50:
                if (symbol == '0'){
                    state = 999;
                    s = "Пятьдесят";
                }
                else if (symbol == '1'){
                    state = 999;
                    s = "Пятьдесят один";
                }
                else if (symbol == '2'){
                    state = 999;
                    s = "Пятьдесят два";
                }
                else if (symbol == '3'){
                    state = 999;
                    s = "Пятьдесят три";
                }
                else if (symbol == '4'){
                    state = 999;
                    s = "Пятьдесят четыре";
                }
                else if (symbol == '5'){
                    state = 999;
                    s = "Пятьдесят пять";
                }
                else if (symbol == '6'){
                    state = 999;
                    s = "Пятьдесят шесть";
                }
                else if (symbol == '7'){
                    state = 999;
                    s = "Пятьдесят семь";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Пятьдесят восемь";
                }
                else if (symbol == '9'){
                    state = 999;
                    s = "Пятьдесят девять";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 60:
                if (symbol == '0'){
                    state = 999;
                    s = "Шестьдесят";
                }
                else if (symbol == '1'){
                    state = 999;
                    s = "Шестьдесят один";
                }
                else if (symbol == '2'){
                    state = 999;
                    s = "Шестьдесят два";
                }
                else if (symbol == '3'){
                    state = 999;
                    s = "Шестьдесят три";
                }
                else if (symbol == '4'){
                    state = 999;
                    s = "Шестьдесят четыре";
                }
                else if (symbol == '5'){
                    state = 999;
                    s = "Шестьдесят пять";
                }
                else if (symbol == '6'){
                    state = 999;
                    s = "Шестьдесят шесть";
                }
                else if (symbol == '7'){
                    state = 999;
                    s = "Шестьдесят семь";
                }
                else if (symbol == '8'){
                    state = 999;
                    s = "Шестьдесят восемь";
                }
                else if (symbol == '9'){
                    state = 999;
                    s = "Шестьдесят девять";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 70:
                if (symbol == '0'){
                    state = 999;
                    s = "Семьдесят";
                }
                else if (symbol == '1'){
                    state = 999;
                    s = "Семьдесят один";
                }
                else if (symbol == '2'){
                    state = 999;
                    s = "Семьдесят два";
                }
                else if (symbol == '3'){
                    state = 999;
                    s = "Семьдесят три";
                }
                else if (symbol == '4'){
                    state = 999;
                    s = "Семьдесят четыре";
                }
                else if (symbol == '5'){
                    state = 999;
                    s = "Семьдесят пять";
                }
                else if (symbol == '6'){
                    state = 999; 
                    s = "Семьдесят шесть";
                }
                else if (symbol == '7'){
                    state = 999;
                    s = "Семьдесят семь";
                }
                else if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                }
                else{
                    state = 1;
                }
                break;
            case 999:
                if (symbol == ',' || symbol == ' ' || symbol == ' ' || symbol == '\n'){
                    state = 2;
                    printf("%s\n", s);
                }
                else {
                    state = 1;
                }
        default:
            break;
        }
    }
    if (state == 999){
        printf("%s\n", s);
    }
}
```
7. **Замечания автора** : -
8. **Выводы**: Работа над этой задачей показала мне сложность и глубину принципов работы конечых автоматов. Эта работа помогла мне лучше понять, как можно использовать конечные автоматы для решения различных задач, и как важно правильно структурировать код для получения нужного результата.
