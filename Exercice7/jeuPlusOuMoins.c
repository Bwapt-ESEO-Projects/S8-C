#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "jeuPlusOuMoins.h"

static int val_mystere;

int acq_val(int *val) {
    int val_test;
    int is_int = 0;

    is_int = scanf("%d", &val_test);

    if ((val_test < 0 || val_test > MAX) && is_int != 1) {
        return 1;
    } 
    else {
        *val = val_test;
        return 0;
    }

}

void init_jeu() {
    srand(time(NULL));
    val_mystere = rand() % (MAX + 1);
}

int verification(int val) {
    if (val > val_mystere) {
        return 1;
    } 
    else if (val < val_mystere) {
        return -1;
    } 
    else {
        return 0;
    }
}

