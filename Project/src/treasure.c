#include <treasure.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    uint8_t x;
    uint8_t y;
} Treasure_t;

static Treasure_t treasure;

extern void treasure_init(void)
{
    treasure.x = rand() % 10;
    treasure.y = rand() % 10;
}

extern coordinate treasure_get_pos(void)
{
    return (coordinate){treasure.x, treasure.y};
}

extern void treasure_new(void)
{
}

extern void treasure_free(void)
{
}