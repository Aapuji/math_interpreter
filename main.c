#include "lib.h"

int main(void) {
    linked *ll = linked_factory();
    if (!ll) perror("Malloc Error - linked");

    token *tok = token_factory(TT_OPER, "Hello World");
    if (!tok) perror("Malloc Error - token");

    printf("%i\n", tok->type);
    printf("%s\n", tok->raw);

    node *n = node_factory(tok);
    if (!n) perror("Malloc Error - node");

    printf("NODE: %s\n", n->value.raw);

    enqueue(ll, tok);

    printf("%i %s\n", ll->head->value.type, ll->tail->value.raw);
    return 0;
}