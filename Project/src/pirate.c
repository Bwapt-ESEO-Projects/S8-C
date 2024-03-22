#include "pirate.h"

#include <stdio.h>
#include <stdlib.h>

struct Pirate_t{
    int x;
    int y;
    bool can_move;
    char current_case;
};

extern void pirate_init(Pirate *pirate)
{
    pirate->x = rand() % 10;
    pirate->y = rand() % 10;
}

extern coordinate pirate_get_pos(Pirate *pirate)
{
    return (coordinate){pirate->x, pirate->y};
}

extern bool pirate_movement(Pirate *pirate, coordinate player) {

    direction d;

    if (pirate_get_pos(pirate).x == player.x || pirate_get_pos(pirate).y == player.y) {
        if (pirate_get_pos(pirate).x == player.x) {
            if (pirate_get_pos(pirate).y < player.y) {
                d = RIGHT;
            } else {
                d = LEFT;
            }
        } else {
            if (pirate_get_pos(pirate).x < player.x) {
                d = DOWN;
            } else {
                d = UP;
            }
        }
    }
    else {
        d = (direction)(rand() % 4);
    }

    switch (d)
    {
    case UP:
            if(pirate->x > 0) {
                pirate->x--;
                return true;
            }
            break;
    case DOWN:
        if(pirate->x < COLONNE-1) {
            pirate->x++;
            return true;
        }
        break;
    case LEFT:
        if(pirate->y > 0) {
            pirate->y--;
            return true;
        }
        break;
    case RIGHT:
        if(pirate->y < LIGNE-1) {
            pirate->y++;
            return true;
        }
        break;
    default:
        break;
        return false;
    }
    return false;
}

extern bool pirate_get_all_can_move(Pirate *pirates[])
{
    for(int i = 0; i < NB_PIRATE; i++) {
        if(!pirate_get_can_move(pirates[i])) {
            return false;
        }
    }
    return true;
}

extern void pirate_set_all_can_move(Pirate *pirates[], bool b)
{
    for(int i = 0; i < NB_PIRATE; i++) {
        pirate_set_can_move(pirates[i], b);
    }
}

extern bool pirate_get_can_move(Pirate *pirate)
{
    return pirate->can_move;
}

extern void pirate_set_can_move(Pirate *pirate, bool b)
{
    pirate->can_move = b;
}

extern char pirate_load_current_case(Pirate *pirate)
{
    return pirate->current_case;
}

extern void pirate_store_current_case(Pirate *pirate, char c)
{
    pirate->current_case = c;
}

struct Pirate_t *pirate_new(void)
{
    Pirate *this = (Pirate *)malloc(sizeof(Pirate));
    return this;

}

extern void pirate_free(Pirate *pirate)
{
    free(pirate);
}