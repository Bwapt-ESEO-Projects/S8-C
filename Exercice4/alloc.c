#include <stdio.h>
#include <stdlib.h>

int main () {
    int n;
    printf("Entrez la taille du tableau : ");
    scanf("%d", &n);     // Taille du tableau

    int *tab = (int*) malloc(n * sizeof(int));

    if(tab == NULL) {
        printf("L'allocation en mémoire à échouée.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if(i == 0)
            tab[i] = 1;
        else
            tab[i] = tab[i-1] + 2;
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ", tab[i]);
    
    printf("\n");

    free(tab);

    return 0;
}