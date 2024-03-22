#include <stdio.h>

typedef struct {
    int heure;
    int minute;
    int seconde;
} s_temps;

s_temps add_temps(s_temps* temps1_ptr, s_temps* temps2_ptr) {

    temps1_ptr->heure = temps1_ptr->heure + temps2_ptr->heure;
    temps1_ptr->minute = temps1_ptr->minute + temps2_ptr->minute;
    temps1_ptr->seconde = temps1_ptr->seconde + temps2_ptr->seconde;

    return *temps1_ptr;
}

int main() {
    s_temps temps_1 = {1, 10, 10};
    s_temps temps_2 = {2, 20, 20};

    s_temps temps_3 = add_temps(&temps_1, &temps_2);

    printf("%dh%dmin%ds\n", temps_3.heure, temps_3.minute, temps_3.seconde);
}