#include <stdio.h>

void permuter_int(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void main() {
    int a = 5;
    int b = 10;
    
    permuter_int(&a, &b);

    printf("a = %d\n", a);
    printf("b = %d\n", b);
}