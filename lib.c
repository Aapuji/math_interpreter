#include "lib.h"

token *token_factory(token_t tt, char *str) {
    token *tok = malloc(sizeof(tok));
    if (!tok) return NULL;

    tok->type = tt;
    tok->raw = str;

    return tok;
}


node *node_factory(token *tok) {
    node *n = malloc(sizeof(node));
    if (!n) return NULL;

    n->value = *tok;
    n->next = NULL;

    return n;
}

linked *linked_factory() {
    linked *ll = malloc(sizeof(linked));
    if (!ll) return NULL;

    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;

    return ll;
}

size_t enqueue(linked *ll, token *tok) {
    NEW_NODE(node, tok);

    if (ll->tail == NULL)
        ll->head = node;
    
    ll->tail = node;
    return ++ll->size;
}

size_t dequeue(linked *ll) {
    if (ll->size == 0) return 0;
    if (ll->size == 1) {
        free(ll->tail);
        ll->head = NULL;
        ll->tail = NULL;
        return 1;
    }

    free(ll->tail);
    ll->head = ll->head->next;
    return --ll->size;
}

token *head(linked *ll) {
    return &ll->head->value;
}