# Отчет по лабораторной работе № 26
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Абстрактные типы данных. Рекурсия. Модульное программирование на языке Си.
2. **Цель работы**: Составить и отладить модуль определений и модуль реализации для типа данных стек. Составить программный модуль, сортирующий экземпляр указанного абстрактного типа данных заданным методом, используя только операции, импортированные из модуля UUDT.
3. **Задание (вариант №<номер варианта если есть>)**: 3(Дек), 5(Сортировка слиянием).
4. **Идея, метод, алгоритм решения задачи**: 
    - Создать структуру стек.
    - Реализовать функцию добавления нового элемента в конец стека.
    - Реализовать функцию добавления нового элемента в начало стека.
    - Реализовать функцию удаления элемента из конца стека.
    - Реализовать функцию удаления элемента из начала стека.
    - Реализовать функцию вывода стека на экран.
    - Реализовать функцию вывода размера стека на экран.
    - Реализовать функцию проверки стека на пустоту.
    - Реализовать функцию сортировки слиянием.
5. **Сценарий выполнения работы**: выполнить алгоритм с помощью кода С
6. **Протокол**: 
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Deque;

void Deque_сreate(Deque* deque) {
    deque->front = -1;
    deque->rear = -1;
}

int deque_is_empty(Deque* deque) {
    return (deque->front == -1 && deque->rear == -1);
}


void deque_push_front(Deque* deque, int item) {
    if (deque_is_empty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front = deque->front - 1;
    }
    deque->items[deque->front] = item;
}

void deque_push_back(Deque* deque, int item) {
    if (deque_is_empty(deque)) {
        deque->front = 0;
        deque->rear = 0;
    } else {
        deque->rear = (deque->rear + 1) % MAX_SIZE;
    }
    deque->items[deque->rear] = item;
}

int deque_pop_front(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Deque is empty\n");
        return -1;
    } else if (deque->front == deque->rear) {
        int item = deque->items[deque->front];
        deque->front = -1;
        deque->rear = -1;
        return item;
    } else {
        int item = deque->items[deque->front];
        deque->front = (deque->front + 1) % MAX_SIZE;
        return item;
    }
}

int deque_pop_back(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Deque is empty\n");
        return -1;
    } else if (deque->front == deque->rear) {
        int item = deque->items[deque->rear];
        deque->front = -1;
        deque->rear = -1;
        return item;
    } else if (deque->rear == 0) {
        int item = deque->items[deque->rear];
        deque->rear = MAX_SIZE - 1;
        return item;
    } else {
        int item = deque->items[deque->rear];
        deque->rear = deque->rear - 1;
        return item;
    }
}

int deque_size(Deque* deque) {
    if (deque_is_empty(deque)) {
        return 0;
    } else {
        return (deque->rear - deque->front + MAX_SIZE) % MAX_SIZE + 1;
    }
}

void deque_print(Deque* deque) {
    if (deque_is_empty(deque)) {
        printf("Deque is empty\n");
        return;
    }
    int i = deque->front;
    while (i != deque->rear) {
        printf("%d ", deque->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", deque->items[deque->rear]);
}

void merge(Deque* result, Deque* deque1, Deque* deque2) {
    Deque_сreate(result);

    while (!deque_is_empty(deque1) && !deque_is_empty(deque2)) {
        if (deque1->items[deque1->front] < deque2->items[deque2->front]) {
            deque_push_back(result, deque_pop_front(deque1));
        } else {
            deque_push_back(result, deque_pop_front(deque2));
        }
    }

    while (!deque_is_empty(deque1)) {
        deque_push_back(result, deque_pop_front(deque1));
    }

    while (!deque_is_empty(deque2)) {
        deque_push_back(result, deque_pop_front(deque2));
    }
}

int main() {
    char command[100];
    Deque deque1;
    Deque deque2;
    int number;
    int index;
    Deque_сreate(&deque1);
        while(strcmp(command, "stop") != 0) {
            scanf("%s", command);
            if (strcmp(command, "deque_is_empty") == 0) {
                int ans = deque_is_empty(&deque1);
                printf("%d\n", ans);
            }
            if (strcmp(command, "deque_push_front") == 0) {
                scanf("%d\n", &number);
                deque_push_front(&deque1, number);
            }
            if (strcmp(command, "deque_push_back") == 0) {
                scanf("%d\n", &number);
                deque_push_back(&deque1, number);
            }
            if (strcmp(command, "deque_pop_front") == 0) {
                deque_pop_front(&deque1);
            }
            if (strcmp(command, "deque_pop_back") == 0) {
                deque_pop_back(&deque1);
            }
            if (strcmp(command, "deque_print") == 0) {
                deque_print(&deque1);
            }
            if (strcmp(command, "deque_size") == 0) {
               printf("%d\n", deque_size(&deque1));
            }
        }
    char command2[100];
    Deque_сreate(&deque2);
        while(strcmp(command2, "stop") != 0) {
            scanf("%s", command2);
            if (strcmp(command2, "deque_is_empty") == 0) {
                int ans = deque_is_empty(&deque2);
                printf("%d\n", ans);
            }
            if (strcmp(command2, "deque_push_front") == 0) {
                scanf("%d\n", &number);
                deque_push_front(&deque2, number);
            }
            if (strcmp(command2, "deque_push_back") == 0) {
                scanf("%d\n", &number);
                deque_push_back(&deque2, number);
            }
            if (strcmp(command2, "deque_pop_front") == 0) {
                deque_pop_front(&deque2);
            }
            if (strcmp(command2, "deque_pop_back") == 0) {
                deque_pop_back(&deque2);
            }
            if (strcmp(command2, "deque_print") == 0) {
                deque_print(&deque2);
            }
            if (strcmp(command2, "deque_size") == 0) {
                printf("%d\n", deque_size(&deque2));
            }
        }
    Deque result;
    merge(&result, &deque1, &deque2);
    deque_print(&result);
    return 0;
}

```
7. **Замечания автора** по существу работы: -
8. **Выводы**: Работа является очень важной, так как написание этой программы позволит писать программы на С с использованием собственных модулей и структур.
