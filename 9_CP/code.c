#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    double real;
    double imag;
} Complex;

int compare_complex(const void *a, const void *b) {
    Complex *complex_a = (Complex *)a;
    Complex *complex_b = (Complex *)b;

    double mod_a_squared = complex_a->real * complex_a->real + complex_a->imag * complex_a->imag;
    double mod_b_squared = complex_b->real * complex_b->real + complex_b->imag * complex_b->imag;

    if (mod_a_squared < mod_b_squared) return -1;
    if (mod_a_squared > mod_b_squared) return 1;
    return 0;
}

void heapify(Complex arr[], char **lines, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && compare_complex(&arr[left], &arr[largest]) > 0) {
        largest = left;
    }

    if (right < n && compare_complex(&arr[right], &arr[largest]) > 0) {
        largest = right;
    }

    if (largest != i) {
        Complex temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        char *temp_line = lines[i];
        lines[i] = lines[largest];
        lines[largest] = temp_line;

        heapify(arr, lines, n, largest);
    }
}

void heapSort(Complex arr[], char **lines, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, lines, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        Complex temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        char *temp_line = lines[0];
        lines[0] = lines[i];
        lines[i] = temp_line;

        heapify(arr, lines, i, 0);
    }
}

int binarySearch(Complex arr[], int n, Complex key) {
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (compare_complex(&arr[m], &key) == 0) {
            return m;
        }
        if (compare_complex(&arr[m], &key) < 0) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    FILE *file_in = fopen("data_random.txt", "r");
    if (file_in == NULL) {
        printf("Ошибка при открытии файла.\n");
        return 1;
    }

    int num_lines = 0;
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), file_in) != NULL) {
        num_lines++;
    }

    rewind(file_in);

    Complex *complex_numbers = malloc(num_lines * sizeof(Complex));
    char **lines = malloc(num_lines * sizeof(char *));
    if (complex_numbers == NULL || lines == NULL) {
        printf("Ошибка выделения памяти.\n");
        fclose(file_in);
        return 1;
    }
    
    for (int i = 0; i < num_lines; i++) {
        complex_numbers[i].real = 0;
        complex_numbers[i].imag = 0;

        if (fgets(buffer, sizeof(buffer), file_in) == NULL) {
            printf("Ошибка чтения данных из файла.\n");
            fclose(file_in);
            free(complex_numbers);
            for (int j = 0; j < i; j++) {
                free(lines[j]);
            }
            free(lines);
            return 1;
        }

        sscanf(buffer, "%lf %lf", &complex_numbers[i].real, &complex_numbers[i].imag);

        size_t buf_len = strlen(buffer);
        if (buf_len > 0 && buffer[buf_len - 1] != '\n' && buf_len < sizeof(buffer) - 1) {
            buffer[buf_len] = '\n';
            buffer[buf_len + 1] = '\0';
        }

        lines[i] = malloc(buf_len + 1);
        if (lines[i] == NULL) {
            printf("Ошибка выделения памяти для строки.\n");
            fclose(file_in);
            free(complex_numbers);
            for (int j = 0; j <= i; j++) {
                free(lines[j]);
            }
            free(lines);
            return 1;
        }
        strcpy(lines[i], buffer);
    }

    // Вывод входных данных
    printf("Входные данные:\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
    }
    
    fclose(file_in);

    heapSort(complex_numbers, lines, num_lines);

    FILE *file_out = fopen("output.txt", "w");
    if (file_out == NULL) {
        printf("Ошибка при открытии файла для записи.\n");
        free(complex_numbers);
        for (int i = 0; i < num_lines; i++) {
            free(lines[i]);
        }
        free(lines);
        return 1;
    }

    for (int i = 0; i < num_lines; i++) {
        fprintf(file_out, "%s", lines[i]);
    }

    fclose(file_out);

    Complex key;
    do {
        printf("Введите вещественную и мнимую части комплексного числа через пробел (или введите '0 0' для выхода): ");
        scanf("%lf %lf", &key.real, &key.imag);

        // Если пользователь ввел 0 0, завершаем выполнение
        if (key.real == 0 && key.imag == 0) {
            break;
        }

        // Поиск введенного числа
        int index = binarySearch(complex_numbers, num_lines, key);
        if (index != -1) {
            printf("Найдено комплексное число: %s\n", lines[index]);
        } else {
            printf("Комплексное число не найдено.\n");
        }
    } while (key.real != 0 || key.imag != 0);

    // Освобождение ресурсов...
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);
    free(complex_numbers);

    return 0;
}
