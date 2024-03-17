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

int findDepth(binaryTree *node) {
    if (node == NULL) {
        return 0;
    }
    int ans = 1;
    while (node->left != NULL) {
        node = node->left;
        ans = ans + 1;
    }
    return ans;
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


int findMinDepth(binaryTree *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    if (root->left == NULL) {
        return findMinDepth(root->right) + 1;
    }
    if (root->right == NULL) {
        return findMinDepth(root->left) + 1;
    }
    return (findMinDepth(root->left) < findMinDepth(root->right) ? findMinDepth(root->left) : findMinDepth(root->right)) + 1;
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
            //printTree(tree, 0);
            int ans = findDepth(tree);
            printf("%d\n", ans);
        }
    }
}
