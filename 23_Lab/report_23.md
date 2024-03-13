# Отчет по лабораторной работе № 23
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Татаркин Иван Владимирович

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Динамические структуры данных.Обработка деревьев.
2. **Цель работы**: Определить глубину минимальной вершины двоичного дерева.
3. **Задание (вариант №<номер варианта если есть>)**: 15
4. **Идея, метод, алгоритм решения задачи**: 
    - Создать бинарное дерево.
    - Реализовать функцию добавления нового узла в дерево.
    - Реализовать функцию удаления узла из дерева
    - Реализовать функцию текстового вывода дерева.
    - Реализовать требуемую в условии задачи фунцию.
5. **Сценарий выполнения работы**: выполнить алгоритм с помощью кода С
6. **Протокол**: 
```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct binaryTree_s {
    float data;
    struct binaryTree_s *left;
    struct binaryTree_s *right;
} binaryTree;

binaryTree *createNode(float data){
    binaryTree *newNode = (binaryTree *)malloc(sizeof(binaryTree));
    if (newNode == NULL){
        printf("Malloc returned Null\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

binaryTree *findMin(binaryTree *node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

void deleteNode(binaryTree **root, float key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->data) {
        deleteNode(&(*root)->left, key);
    } else if (key > (*root)->data) {
        deleteNode(&(*root)->right, key);
    } else {
        if ((*root)->left == NULL) {
        binaryTree *temp = (*root)->right;
        free(*root);
        *root = temp;
        } else if ((*root)->right == NULL) {
            binaryTree *temp = (*root)->left;
            free(*root);
            *root = temp;
        } else {
            binaryTree *temp = findMin((*root)->right);
            (*root)->data = temp->data;
            deleteNode(&(*root)->right, temp->data);
        }
    }
}


void printTree(binaryTree *root, int space) {
    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%.2f\n", root->data);
    printTree(root->left, space);
}

void push(binaryTree ** tree, float data){
    binaryTree *newNode = createNode(data);
    binaryTree *tmp = *tree;
    if (tmp == NULL){
        *tree = newNode;
    }
    else if (data < tmp->data){
        if (tmp->left == NULL){
            tmp->left = newNode;
        }
        else {
            push(&(tmp->left), data);
        }
    }
    else if (data > tmp->data){
        if (tmp->right == NULL){
            tmp->right = newNode;
        }
        else {
            push(&(tmp->right), data);
        }
    }
}


int minDepth(binaryTree *node){
    if (node == NULL){
        return 0;
    }
    int leftDepth = minDepth(node->left);
    int rightDepth = minDepth(node->right);
    
    if (leftDepth == 0 || rightDepth == 0){
        return leftDepth + rightDepth + 1;
    } else {
        return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
    }
}

int main(){
    binaryTree *tree = NULL;
    float number;
    char command[100];
    while(1) {
        scanf("%s", command);
        if (strcmp(command, "PushNewNode") == 0) {
            scanf("%f", &number);
            push(&tree, number);
        }
        if (strcmp(command, "PrintTree") == 0) {
            printTree(tree, 0);
        }
        if (strcmp(command, "DeleteNode") == 0) {
            scanf("%f", &number);
            deleteNode(&tree, number);
        }
        if (strcmp(command, "FindDepth") == 0) {
            printTree(tree, 0);
            int ans = minDepth(tree);
            printf("%d\n", ans);
        }
    }
}
```
7. **Замечания автора** по существу работы: -
8. **Выводы**: Работа является очень важной, так как написание этой программы позволит писать программы на С с использованием методов работы сo структурами.
