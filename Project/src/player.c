#include "player.h"

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t life;
    bool can_move;
    char current_case;
} Player_t;

static Player_t player;

extern void player_init(void)
{
    player.x = 0;
    player.y = 0;
    player.life = 3;
}

extern bool player_movement(direction d) {
    switch(d) {
        case UP:
            if(player.x > 0) {
                player.x--;
                return true;
            }
            break;
        case DOWN:
            if(player.x < COLONNE-1) {
                player.x++;
                return true;
            }
            break;
        case LEFT:
            if(player.y > 0) {
                player.y--;
                return true;
            }
            break;
        case RIGHT:
            if(player.y < LIGNE-1) {
                player.y++;
                return true;
            }
            break;
    }
    return false;
}

extern coordinate player_get_pos(void)
{
    return (coordinate){player.x, player.y};
}

extern uint8_t player_get_life(void)
{
    return player.life;
}

extern void player_set_life(uint8_t life)
{
    player.life = life;
}

extern void player_print_life(void)
{
    printf("[");

    for(int i = 0; i < player.life; i++) {
        printf("♥");
        if (i < player.life - 1) {
            printf(" ");
        }
    }
    if(player.life < 3){
        for(int i = 0; i < 3 - player.life; i++) {
            printf("  ");
        }
    }
    printf("]\n");
}

extern bool player_get_can_move(void)
{
    return player.can_move;
}

extern void player_set_can_move(bool b)
{
    player.can_move = b;
}

extern char player_load_current_case(void)
{
    return player.current_case;
}

extern void player_store_current_case(char c)
{
    player.current_case = c;
}

extern void player_new(void)
{
}

extern void player_free(void)
{
}