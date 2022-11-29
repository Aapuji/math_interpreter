#include "lib.h"
#include "lexer.h"

int main(void) {
    linked *ll = linked_factory();
    if (!ll) perror("Malloc Error - linked");

    token *tok = token_factory(TT_OPER, "Hello World");
    if (!tok) perror("Malloc Error - token");

    printf("%i\n", tok->type);
    printf("%s\n", tok->raw);

    enqueue(ll, tok);

    printf("%i %s\n", ll->head->value.type, ll->tail->value.raw);

    char *arr[] = {"Hello", "Bye", "Bye Bye", "Bonjour"};
    int index = index_of(arr, 4, "Welcome");
    printf("Index: %i", index);

    return 0;
}