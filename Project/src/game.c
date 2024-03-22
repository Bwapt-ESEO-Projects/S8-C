#include "game.h"

void game_init(Trap *traps[], Pirate *pirates[])
{
    game_map_init();
    game_player_init();
    game_treasure_init();
    game_traps_init(traps);
    game_pirates_init(pirates);
}

void game_map_init(void)
{
    map_new();
    map_init();
}

void game_player_init(void)
{
    player_new();
    player_init();
    map_set_case(player_get_pos().x, player_get_pos().y, PLAYER_SYMBOL);
    player_store_current_case(EMPTY_SYMBOL);
}

void game_treasure_init(void)
{
    treasure_new();
    treasure_init();
    while (!map_is_empty(treasure_get_pos().x, treasure_get_pos().y))
    {
        treasure_init();
    }
    map_set_case(treasure_get_pos().x, treasure_get_pos().y, TREASURE_SYMBOL);
}

void game_traps_init(Trap *traps[])
{
    for (int i = 0; i < NB_TRAP; i++)
    {
        traps[i] = trap_new();
        game_trap_init(traps[i]);
    }
}

void game_trap_init(Trap *trap)
{
    trap_init(trap);

    while (!map_is_empty(trap_get_pos(trap).x, trap_get_pos(trap).y))
    {
        trap_init(trap);
    }
    map_set_case(trap_get_pos(trap).x, trap_get_pos(trap).y, TRAP_SYMBOL);
}

void game_pirates_init(Pirate *pirates[])
{
    for (int i = 0; i < NB_PIRATE; i++)
    {
        pirates[i] = pirate_new();
        game_pirate_init(pirates[i]);
    }
}

void game_pirate_init(Pirate *pirate)
{
    pirate_init(pirate);

    while (!map_is_empty(pirate_get_pos(pirate).x, pirate_get_pos(pirate).y))
    {
        pirate_init(pirate);
    }
    map_set_case(pirate_get_pos(pirate).x, pirate_get_pos(pirate).y, PIRATE_SYMBOL);
    pirate_store_current_case(pirate, EMPTY_SYMBOL);
}

bool game_check_trap(coordinate player, coordinate trap)
{
    if (player.x == trap.x && player.y == trap.y)
    {
        return true;
    }
    return false;
}

bool game_check_pirate(coordinate player, coordinate pirate)
{
    if (player.x == pirate.x && player.y == pirate.y)
    {
        return true;
    }
    return false;
}

void game_turn_reset(Pirate *pirates[])
{
    map_set_case(player_get_pos().x, player_get_pos().y, player_load_current_case());

    for (int i = 0; i < NB_PIRATE; i++)
    {
        map_set_case(pirate_get_pos(pirates[i]).x, pirate_get_pos(pirates[i]).y, pirate_load_current_case(pirates[i]));
    }

    player_set_can_move(false);
    pirate_set_all_can_move(pirates, false);
}

void game_check_ennemy(Trap *traps[], Pirate *pirates[])
{
    int i = 0;
    while (i < NB_TRAP && !game_check_trap(player_get_pos(), trap_get_pos(traps[i])))
    {
        i++;
    }
    if (i < NB_TRAP)
    {
        player_set_life(player_get_life() - 1);
    }

    i = 0;
    while (i < NB_PIRATE && !game_check_pirate(player_get_pos(), pirate_get_pos(pirates[i])))
    {
        i++;
    }
    if (i < NB_PIRATE)
    {
        player_set_life(player_get_life() - 1);
        game_pirate_init(pirates[i]);
    }
}

void game_move_pirates(Pirate *pirates[])
{
    for (int i = 0; i < NB_PIRATE; i++)
    {
        pirate_set_can_move(pirates[i], pirate_movement(pirates[i], player_get_pos()));

        if (pirate_get_can_move(pirates[i]))
        {
            if (map_get_case(pirate_get_pos(pirates[i]).x, pirate_get_pos(pirates[i]).y) != PIRATE_SYMBOL)
            {
                pirate_store_current_case(pirates[i], map_get_case(pirate_get_pos(pirates[i]).x, pirate_get_pos(pirates[i]).y));
            }
            else
            {
                pirate_store_current_case(pirates[i], EMPTY_SYMBOL);
            }
        }
        map_set_case(pirate_get_pos(pirates[i]).x, pirate_get_pos(pirates[i]).y, PIRATE_SYMBOL);
    }
}

void game_print(void)
{
    system("clear");
    map_print();
    player_print_life();
}

bool game_check_win(coordinate player, coordinate treasure)
{
    if (player.x == treasure.x && player.y == treasure.y)
    {
        return true;
    }
    return false;
}

bool game_check_end(void)
{
    if (player_get_life() == 0 || game_check_win(player_get_pos(), treasure_get_pos()))
    {
        return true;
    }
    return false;
}

void game_end(bool victory)
{
    if (victory)
    {
        printf("You win !\n");
    }
    else
    {
        printf("You loose !\n");
    }
}

void game_free(Trap *traps[], Pirate *pirates[])
{
    map_free();
    player_free();
    treasure_free();

    for (int i = 0; i < NB_TRAP; i++)
    {
        trap_free(traps[i]);
    }

    for (int i = 0; i < NB_PIRATE; i++)
    {
        pirate_free(pirates[i]);
    }
}