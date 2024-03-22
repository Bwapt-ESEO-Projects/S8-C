#include "trap.h"

struct Trap_t{
    int x;
    int y;
};

extern void trap_init(Trap *trap)
{
    trap->x = rand() % 10;
    trap->y = rand() % 10;
}

extern coordinate trap_get_pos(Trap *trap)
{
    return (coordinate){trap->x, trap->y};
}

struct Trap_t *trap_new(void)
{
    Trap *this = (Trap *)malloc(sizeof(Trap));
    return this;

}

extern void trap_free(Trap *trap)
{
    free(trap);
}

