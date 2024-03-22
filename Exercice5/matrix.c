#include <stdio.h>
#include <stdlib.h>

int main() {
    int lignes, colonnes;

    printf("Entrez le nombre de lignes de la matrice : ");
    scanf("%d", &lignes);

    printf("Entrez le nombre de colonnes de la matrice : ");
    scanf("%d", &colonnes);

    int *matrice = (int*) malloc(lignes * colonnes * sizeof(int));

    for(int i = 0; i < colonnes; i++) {
        for(int j = 0; j < lignes; j++) {
            printf("Entrez une valeur à la position [%d, %d] : ", i, j);
            scanf("%d", &matrice[i * j]);
        }
    }

    for(int i = 1; i < colonnes; i++) {
        for(int j = 1; j < lignes; j++) {
            printf("%d", matrice[i * j]);
        }
        printf("\n");
    }

    free(matrice);

    return 0;
}