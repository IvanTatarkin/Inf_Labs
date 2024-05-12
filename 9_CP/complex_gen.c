#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    float real;
    float imag;
} Complex;

// Функция для генерации комплексного числа
Complex generateComplex() {
    Complex c;
    c.real = ((float)rand() / (float)(RAND_MAX)) * 10; // Генерация случайного вещественного числа от 0 до 10
    c.imag = ((float)rand() / (float)(RAND_MAX)) * 10; // Генерация случайного вещественного числа от 0 до 10
    return c;
}

// Сравнение для сортировки комплексных чисел по возрастанию их действительных частей
int compareComplex(const void *a, const void *b) {
    float diff = ((Complex *)a)->real - ((Complex *)b)->real;
    if (diff > 0) return 1;
    if (diff < 0) return -1;
    return 0;
}

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    Complex numbers[10];

    // Генерация 10 комплексных чисел
    for (int i = 0; i < 10; i++) {
        numbers[i] = generateComplex();
    }

    // Сортировка комплексных чисел по возрастанию их действительных частей
    qsort(numbers, 10, sizeof(Complex), compareComplex);

    // Вывод отсортированных комплексных чисел
    for (int i = 0; i < 10; i++) {
        printf("%.2f %.2f\n", numbers[i].real, numbers[i].imag);
    }

    return 0;
}
