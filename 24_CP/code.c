#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { TYPE_OPERATOR, TYPE_OPERAND } NodeType;

typedef struct Node {
    NodeType type;
    union {
        char operator;
        int operand;
    };
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(NodeType type, char operator, int operand) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    if (type == TYPE_OPERATOR) {
        node->operator = operator;
    } else {
        node->operand = operand;
    }
    node->left = node->right = NULL;
    return node;
}

void freeTree(Node* node) {
    if (node) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}

void printTree(Node* node) {
    if (!node) return;
    if (node->type == TYPE_OPERAND) {
        printf("%d", node->operand);
    } else {
        if (node->left) printTree(node->left);
        printf(" %c ", node->operator);
        if (node->right) printTree(node->right);
    }
}

// Это упрощенный парсер, который предполагает, что операнды - однозначные числа, и операторы - '+', '-', '*', '/'
Node* parseExpression(const char* exp) {
    // Здесь должен быть код для преобразования строки в дерево выражений
    // Например, можно использовать алгоритм сортировочной станции для преобразования в обратную польскую нотацию,
    // а затем из RPN в дерево выражений.
    return NULL; // Заглушка для примера
}

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;

    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));

    if (!stack->array) return NULL;

    return stack;
}

int isStackEmpty(Stack* stack) {
    return stack->top == -1;
}

int isStackFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item) {
    if (isStackFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isStackEmpty(stack)) return '$';
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (isStackEmpty(stack)) return '$';
    return stack->array[stack->top];
}

int main() {
    const char* expression = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    Node* expressionTree = parseExpression(expression);

    printf("Infix expression: %s\n", expression);
    printf("Expression Tree: ");
    printTree(expressionTree);
    printf("\n");

    freeTree(expressionTree);
    return 0;
}
