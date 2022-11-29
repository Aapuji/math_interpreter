#include "lexer.h"

const char *OPERATORS[] = {"+", "-", "*", "/", "^"};

typedef enum OPER {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_POW
} OPER;

int index_of(char **arr, size_t length, char *item) {
    for (size_t i = 0; i < length; i++) {
        if (arr[i] == item)
            return i;
    }
    return -1;
}

char **split(char *str, size_t length, char *delim) {
    
    // for (int i = 0; i < length; i++) {
        
    // }
}

// int lex(linked *dest, FILE *src, int n);