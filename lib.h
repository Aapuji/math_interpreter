#ifndef LIB_H
#define LIB_H

#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * @brief Enum representing token types
 * 
 */
typedef enum {
    TT_IDENT, /* Identifier Token */
    TT_OPER, /* Operator Token */
    TT_KEY, /* Keyword Token */
    TT_LIT /* Literal Token */
} token_t;

/**
 * @brief Token - has a type (token_t) and a raw string value of the token (char *)
 * 
 */
typedef struct token {
    token_t type;
    char *raw;
} token;

/**
 * @brief Node in linked list.
 * 
 */
typedef struct node {
    token value;
    struct node *next;
} node;

/**
 * @brief Linked list.
 * 
 */
typedef struct linked {
    node *head;
    node *tail;
    size_t size;
} linked;

/**
 * @brief Creates a token given the token type and raw value. Returns pointer to the token or NULL if error occurred.
 * 
 * @param tt Token type of the token
 * @param str String representation of token
 * @return token* 
 */
token *token_factory(token_t tt, char *str);

/**
 * @brief Creates a node from a token. Often used in conjunction with the NEW_NODE macro. Returns a pointer to a node or NULL if error occurred.
 * 
 * @param tok A token to create the node from
 * @return int 
 */
node *node_factory(token *tok);

/**
 * @brief Creates a linked list. Returns a pointer to a linked list or NULL if error occurred.
 * @param src Pointer to linked list
 * @return int 
 */
linked *linked_factory();

/**
 * @brief Appends a node to the end of the linked list. Returns size of linked list after operation.
 * 
 * @param ll Pointer to linked list to modify
 * @param tok Token to append
 * @return size_t 
 */
size_t enqueue(linked *ll, token *tok);

/**
 * @brief Removes the first element of a linked list. Returns size of linked list after operation.
 * 
 * @param ll Pointer to linked list
 * @return size_t 
 */
size_t dequeue(linked *ll);

/**
 * @brief Returns a pointer to first element of a linked list.
 * 
 * @param ll Pointer to linked list
 * @return token *
 */
token *head(linked *ll);

/**
 * @brief A quick way to initialize a node. Creates a node pointer with name @ NODE_NAME and passed with token TOK_NAME.
 * 
 */
#define NEW_NODE(NODE_NAME, TOK_NAME) node *NODE_NAME = node_factory(TOK_NAME)

#endif