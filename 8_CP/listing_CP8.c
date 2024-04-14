#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    size_t data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    size_t size;
} CircularLinkedList;

typedef struct {
    Node* current;
} Iterator;

// Инициализация пустого списка
void initList(CircularLinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
int moveNext(Iterator* iter) {
    if (iter->current != NULL) {
        iter->current = iter->current->next;
        return iter->current != NULL;
    }
    return 0;
}

void initIterator(Iterator* iter, const CircularLinkedList* list) {
    iter->current = list->head;
}
size_t GetCurrentData(const Iterator* iter) {
    if (iter->current != NULL) {
        return iter->current->data;
    }
    return 0;
}


// Печать списка
void printList(const CircularLinkedList* list) {
    if (list->size == 0) {
        printf("Список пуст\n");
        return;
    }
    Iterator iter;
    initIterator(&iter, list);
    do {
        printf("%zu ", GetCurrentData(&iter));
    } while (moveNext(&iter) && iter.current != list->head);
    printf("\n");
}


// Вставка элемента в конец списка
void insertEnd(CircularLinkedList* list, size_t data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Ошибка выделения памяти\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    if (list->size == 0) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode; // Ссылка на себя, так как список кольцевой
    } else {
        list->tail->next = newNode;
        newNode->next = list->head;
        list->tail = newNode;
    }
    list->size++;
}

// Удаление элемента из списка по значению
void deleteNode(CircularLinkedList* list, size_t data) {
    if (list->size == 0) {
        printf("Список пуст, невозможно удалить элемент\n");
        return;
    }
    Iterator iter;
    initIterator(&iter, list);
    Node* prev = NULL;
    do {
        if (GetCurrentData(&iter) == data) {
            Node* current = iter.current;
            if (current == list->head) {
                list->head = current->next;
                list->tail->next = list->head;
            } else if (current == list->tail) {
                prev->next = list->head;
                list->tail = prev;
            } else {
                prev->next = current->next;
            }
            free(current);
            list->size--;
            printf("Элемент %zu удален из списка\n", data);
            return;
        }
        prev = iter.current;
    } while (moveNext(&iter) && iter.current != list->head);
    printf("Элемент %zu не найден в списке\n", data);
}

// Подсчет длины списка
size_t length(const CircularLinkedList* list) {
    return list->size;
}

// Удаление каждого k-ого элемента списка
void deleteEveryKth(CircularLinkedList* list, size_t k) {
    if (list->size == 0 || k <= 1) {
        printf("Невозможно выполнить операцию\n");
        return;
    }

    Iterator iter;
    initIterator(&iter, list);
    Node* prev = NULL;
    size_t count = 0;

    do {
        count++;
        if (count == k) {
            Node* current = iter.current;
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            if (current == list->tail) {
                list->tail = prev;
            }

            Node* nextNode = current->next;
            free(current);
            iter.current = nextNode;
            count = 0;
            list->size--;
        } else {
            prev = iter.current;
        }
    } while (moveNext(&iter) && iter.current != list->head);
}

/*void destroyList(CircularLinkedList* list) {
    Iterator iter;
    initIterator(&iter, list);
    Node* current;
    do {
        current = iter.current;
        moveNext(&iter);
        free(current);
    } while (current != list->head);
    list->head = list->tail = NULL;
    list->size = 0;
}*/

int main() {
    CircularLinkedList list;
    initList(&list);
    char command[100] = ""; // Инициализация массива command
    int number;
    while (strcmp(command, "Stop") != 0) {
        scanf("%s", command);
        if (strcmp(command, "Insert_End") == 0) {
            scanf("%d\n", &number);
            insertEnd(&list, number);
        }
        if (strcmp(command, "Print_List") == 0) {
            printList(&list);
        }
        if (strcmp(command, "Length") == 0) {
            printf("Длина списка: %zu\n", length(&list));
        }
        if (strcmp(command, "delete_Node") == 0) {
            scanf("%d\n", &number);
            deleteNode(&list, number);
        }
        if (strcmp(command, "Delete_Kths") == 0) {
            scanf("%d\n", &number);
            deleteEveryKth(&list, number);
        }
    }
    //destroyList(&list);
    return 0;
}
