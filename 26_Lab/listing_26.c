#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define MAX_SIZE 128

typedef struct {
    int items[MAX_SIZE];
    int front;
    int rear;
} Deque;

void Deque_create(Deque* deque) {
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
    if (deque->rear == -1) {
        deque->rear = deque->front;
    }
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

void merge(Deque* deque, int start, int mid, int end) {
    int left_size = (mid - start + 1 + MAX_SIZE) % MAX_SIZE;
    int right_size = (end - mid + MAX_SIZE) % MAX_SIZE;
    Deque left_half, right_half;
    Deque_create(&left_half);
    Deque_create(&right_half);
    int i = start;
    for (int j = 0; j < left_size; j++) {
        deque_push_back(&left_half, deque->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    for (int j = 0; j < right_size; j++) {
        deque_push_back(&right_half, deque->items[i]);
        i = (i + 1) % MAX_SIZE;
    }
    i = start;
    while (!deque_is_empty(&left_half) && !deque_is_empty(&right_half)) {
        if (left_half.items[left_half.front] <= right_half.items[right_half.front]) {
            deque->items[i] = deque_pop_front(&left_half);
        } else {
            deque->items[i] = deque_pop_front(&right_half);
        }
        i = (i + 1) % MAX_SIZE;
    }
    while (!deque_is_empty(&left_half)) {
        deque->items[i] = deque_pop_front(&left_half);
        i = (i + 1) % MAX_SIZE;
    }
    while (!deque_is_empty(&right_half)) {
        deque->items[i] = deque_pop_front(&right_half);
        i = (i + 1) % MAX_SIZE;
    }
}

void mergeSortDeque(Deque* deque, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        mergeSortDeque(deque, start, mid);
        mergeSortDeque(deque, mid + 1, end);
        merge(deque, start, mid, end);
    } else if (start > end) {
        int mid;
        if (start <= end + MAX_SIZE) {
            mid = (start + end + MAX_SIZE) / 2 % MAX_SIZE;
        } else {
            mid = (start + end) / 2;
        }
        mergeSortDeque(deque, start, mid);
        mergeSortDeque(deque, (mid + 1) % MAX_SIZE, end);
        merge(deque, start, mid, end);
    }
}

void deque_sort(Deque* deque) {
    mergeSortDeque(deque, deque->front, deque->rear);
}

void sigint_handler(int signum) {
    printf("\nReceived SIGINT signal. Exiting.\n");
    exit(0);
}

int main() {
    signal(SIGINT, sigint_handler);
    char command[100] = ""; // Инициализация массива command
    Deque deque1;
    int number;
    Deque_create(&deque1);
    while(strcmp(command, "stop") != 0) {
        scanf("%s", command);
        if (strcmp(command, "deque_is_empty") == 0) {
            int ans = deque_is_empty(&deque1);
            printf("%d\n", ans);
        } else if (strcmp(command, "deque_push_front") == 0) {
            scanf("%d", &number);
            deque_push_front(&deque1, number);
        } else if (strcmp(command, "deque_push_back") == 0) {
            scanf("%d", &number);
            deque_push_back(&deque1, number);
        } else if (strcmp(command, "deque_pop_front") == 0) {
            deque_pop_front(&deque1);
        } else if (strcmp(command, "deque_pop_back") == 0) {
            deque_pop_back(&deque1);
        } else if (strcmp(command, "deque_print") == 0) {
            deque_print(&deque1);
        } else if (strcmp(command, "deque_size") == 0) {
            printf("%d\n", deque_size(&deque1));
        } else if (strcmp(command, "deque_merge") == 0) {
           deque_sort(&deque1);
        }
    }
    return 0;
}
