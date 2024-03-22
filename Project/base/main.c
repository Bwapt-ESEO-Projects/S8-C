#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "grille.h"
#include "getch.h"

#define COLONNE 10
#define LIGNE 10

int main()
{
    char car ;
    int fin = 0;
    char **test_grille;
    int pos_joueur_x = 0;
    int pos_joueur_y = 0;

    srand(time(NULL));
    int pos_tresor_x = rand() % 10;
    int pos_tresor_y = rand() % 10;

    //Allouer memoire pour le tableau
    test_grille = (char **)malloc(LIGNE * sizeof(char *));
    for (int i = 0; i < LIGNE; i++) {
        test_grille[i] = (char *)malloc(COLONNE * sizeof(char));
    }

    //Remplissage du tableau
    for(int i=0; i< LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            test_grille[i][j] = ' ';
        }
    }

    test_grille[pos_joueur_x][pos_joueur_y] = 'j';

    test_grille[pos_tresor_x][pos_tresor_y] = ' ';

    //Affichage du tableau
    grille_print(test_grille, COLONNE, LIGNE);

    while(!fin)
    {
        car = getch();
        test_grille[pos_joueur_x][pos_joueur_y] = ' ';
        switch(car)
        {
            case 'a':
                fin = 1;
                break;
            case 'z':
                pos_joueur_x--; 
                break;
            case 's':
                pos_joueur_x++; 
                break;
            case 'q':
                pos_joueur_y--; 
                break;
            case 'd':
                pos_joueur_y++; 
                break;
        }
        test_grille[pos_joueur_x][pos_joueur_y] = 'j';
        system("clear");
        grille_print(test_grille, COLONNE, LIGNE);

        if(pos_joueur_x == pos_tresor_x && pos_joueur_y == pos_tresor_y)
        {
            fin = 1;
            printf("Bravo vous avez gagné\n");
        }
    }
  
    //Liberation de la memoire pour le tableau
    for (int i = 0; i < LIGNE; i++) {
        free(test_grille[i]);
    }
    free(test_grille);

}
