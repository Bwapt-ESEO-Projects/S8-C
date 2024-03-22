#include <stdio.h>
#include <stdbool.h>

#include "jeuPlusOuMoins.h"

int main() {
    int ret;
    int val;
    bool victory = 0;
    
    init_jeu();

    printf("Veuillez entrer une valeur : \n");

    while(victory != 1) {
        ret = 1;
    
        while (ret != 0) {

            ret = acq_val(&val);
            
            if(ret != 0)
            {
                printf("La valeur entrée n'est pas correcte.\n");
            }
        }
        
        ret = verification(val);

        if (ret < 0) {
            printf("C'est plus !\n");
        } else if (ret > 0) {
            printf("C'est moins !\n");
        } else {
            printf("C'est gagné !\n");
            victory = 1;
        }
    }
    
    return 0;
}