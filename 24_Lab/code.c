#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    TOKEN_NUMBER,
    TOKEN_VARIABLE,
    TOKEN_OPERATOR,
    TOKEN_END
} TokenType;

typedef struct {
    TokenType type;
    union {
        int value; 
        char op;  
        char var;  
    } data;
} Token;

typedef struct Node {
    Token token;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(Token token);
void freeTree(Node** node);
void printTree(const Node* node);
int isOperator(char c);
int getPrecedence(char op);
Node* parseExpression(Token** currentToken);
Node* parseTerm(Token** currentToken);
Node* parseFactor(Token** currentToken);
Node* parseExponent(Token** currentToken);
Node* transformTree(Node* node);
Token* tokenize(const char* str);


Node* createNode(Token token) {
    Node* newNode = malloc(sizeof(Node));
    if (!newNode) {
        perror("Failed to allocate memory for a new node");
        exit(EXIT_FAILURE);
    }
    newNode->token = token;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void freeTree(Node** node) {
    if (node == NULL || *node == NULL) return;
    freeTree(&((*node)->left));
    freeTree(&((*node)->right));
    free(*node);
    *node = NULL;
}

void printTree(const Node* node) {
    if (node == NULL) return;

    if (node->left != NULL && node->right != NULL) {
        printf("(");
    }

    printTree(node->left);

    switch (node->token.type) {
        case TOKEN_NUMBER:
            printf("%d", node->token.data.value);
            break;
        case TOKEN_VARIABLE:
            printf("%c", node->token.data.var);
            break;
        case TOKEN_OPERATOR:
            printf(" %c ", node->token.data.op);
            break;
        default:
            break;
    }

    printTree(node->right);

    if (node->left != NULL && node->right != NULL) {
        printf(")");
    }
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '(' || c == ')';
}

int getPrecedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': 
        case '/': return 2;
        case '+': 
        case '-': return 1;
        default: return 0;
    }
}

Node* parseExpression(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    Node* node = parseTerm(currentToken);
    while (*currentToken && (*currentToken)->type == TOKEN_OPERATOR &&
           getPrecedence((*currentToken)->data.op) <= 1 && (*currentToken)->data.op != ')') {
        Token op = *(*currentToken)++;
        Node* right = parseTerm(currentToken);
        Node* new_node = createNode(op);
        new_node->left = node;
        new_node->right = right;
        node = new_node;
    }
    return node;
}

Node* parseTerm(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    Node* node = parseExponent(currentToken);
    while (*currentToken && (*currentToken)->type == TOKEN_OPERATOR &&
           getPrecedence((*currentToken)->data.op) == 2) {
        Token op = *(*currentToken)++;
        Node* right = parseExponent(currentToken);
        Node* new_node = createNode(op);
        new_node->left = node;
        new_node->right = right;
        node = new_node;
    }
    return node;
}

Node* parseExponent(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    Node* node = parseFactor(currentToken);
    while (*currentToken && (*currentToken)->type == TOKEN_OPERATOR &&
           getPrecedence((*currentToken)->data.op) == 3) {
        Token op = *(*currentToken)++;
        Node* right = parseFactor(currentToken);
        Node* new_node = createNode(op);
        new_node->left = node;
        new_node->right = right;
        node = new_node;
    }
    return node;
}

Node* parseFactor(Token** currentToken) {
    if ((*currentToken)->type == TOKEN_END) return NULL;
    
    if ((*currentToken)->type == TOKEN_NUMBER || (*currentToken)->type == TOKEN_VARIABLE) {
        return createNode(*(*currentToken)++);
    } else if ((*currentToken)->type == TOKEN_OPERATOR && (*currentToken)->data.op == '(') {
        (*currentToken)++;
        Node* node = parseExpression(currentToken);
        //(*currentToken)--;
        if (*currentToken && (*currentToken)->type == TOKEN_OPERATOR && (*currentToken)->data.op == ')') {
            (*currentToken)++; 
            return node;
        } else {
            fprintf(stderr, "Expected closing parenthesis\n");
            exit(EXIT_FAILURE);
        }
    }
    
    fprintf(stderr, "Invalid expression\n");
    exit(EXIT_FAILURE);
}


Token makeNumberToken(const char** str) {
    Token token;
    token.type = TOKEN_NUMBER;
    token.data.value = 0;
    while (isdigit(**str)) {
        token.data.value = token.data.value * 10 + (**str - '0');
        (*str)++;
    }
    return token;
}

Token makeOperatorToken(const char** str) {
    Token token;
    token.type = TOKEN_OPERATOR;
    token.data.op = **str;
    (*str)++;
    return token;
}


Token makeVariableToken(const char** str) {
    Token token;
    token.type = TOKEN_VARIABLE;
    token.data.var = **str;
    (*str)++;
    return token;
}

Token* tokenize(const char* str) {
    Token* tokens = malloc((strlen(str) + 1) * sizeof(Token));
    if (!tokens) {
        perror("Failed to allocate memory for tokens");
        exit(EXIT_FAILURE);
    }
    int count = 0;
    while (*str) {
        if (isspace(*str)) {
            str++;
            continue;
        }

        if (isdigit(*str)) {
            tokens[count++] = makeNumberToken(&str);
        } else if (isalpha(*str)) {
            tokens[count++] = makeVariableToken(&str);
        } else if (isOperator(*str)) {
            tokens[count++] = makeOperatorToken(&str);
        } else {
            fprintf(stderr, "Unexpected character: %c\n", *str);
            exit(EXIT_FAILURE);
        }
    }
    tokens[count].type = TOKEN_END;
    return tokens;
}



Node* transformTree(Node* node) {
    if (!node) return NULL;

   
    node->left = transformTree(node->left);
    node->right = transformTree(node->right);

    
    if (node->token.type == TOKEN_OPERATOR && node->token.data.op == '-') {
        Node *left = node->left, *right = node->right;
        
        if (left && left->token.type == TOKEN_OPERATOR && left->token.data.op == '^' &&
            left->right && left->right->token.type == TOKEN_NUMBER && left->right->token.data.value == 2 &&
            right && right->token.type == TOKEN_OPERATOR && right->token.data.op == '^' &&
            right->right && right->right->token.type == TOKEN_NUMBER && right->right->token.data.value == 2) {

            Node* a = left->left;
            Node* b = right->left;
            left->left = NULL; 
            right->left = NULL;

            
            Node* plusNode = createNode((Token){TOKEN_OPERATOR, {.op = '+'}});
            plusNode->left = a;
            plusNode->right = b;
            Node* minusNode = createNode((Token){TOKEN_OPERATOR, {.op = '-'}});
            minusNode->left = a;
            minusNode->right = b;

            
            Node* multNode = createNode((Token){TOKEN_OPERATOR, {.op = '*'}});
            multNode->left = minusNode;
            multNode->right = plusNode;

            
            free(left->right); left->right = NULL;
            free(right->right); right->right = NULL;
            free(left); left = NULL;
            free(right); right = NULL;
            free(node); 
                    

            return multNode;
        }
    }
    return node; 
}





int main() {
    char input[256];
    printf("Enter an expression: ");
    if (fgets(input, sizeof(input), stdin)) {
        input[strcspn(input, "\n")] = 0;

        Token* tokens = tokenize(input);
        Token* currentToken = tokens;

        Node* root = parseExpression(&currentToken);

        printf("Original expression: ");
        printTree(root);
        printf("\n");

        Node* transformedRoot = transformTree(root);
        printf("Transformed expression: ");
        printTree(transformedRoot);
        printf("\n");

        //freeTree(&transformedRoot); 
        //freeTree(&root);
        free(tokens); 
    }
    return 0;
}

