#include <stdio.h>

#define MACRO 42

int main() {
#ifdef MACRO
    printf("Valeur de la macro : %d\n", MACRO);
#else
    printf("La MACRO n'a pas été définie.\n");
#endif
}