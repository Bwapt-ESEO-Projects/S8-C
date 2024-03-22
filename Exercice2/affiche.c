#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char *chaine = argv[1];
    int n = atoi(argv[2]);

    for (int i = 0; i < n; i++) {
        printf("%s\n", chaine);
    }
}