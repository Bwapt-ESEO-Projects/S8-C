#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "game.h"
#include "getch.h"
#include "types.h"

int main()
{
    char car;
    bool fin = false;

    srand(time(NULL));

    Trap *traps[NB_TRAP];
    Pirate *pirates[NB_PIRATE];

    game_init(traps, pirates);

    game_print();

    while (!fin)
    {
        game_turn_reset(pirates);

        car = getch();
        switch (car)
        {
        case 'a':
            fin = true;
            break;
        case 'z':
            player_set_can_move(player_movement(UP));
            break;
        case 's':
            player_set_can_move(player_movement(DOWN));
            break;
        case 'q':
            player_set_can_move(player_movement(LEFT));
            break;
        case 'd':
            player_set_can_move(player_movement(RIGHT));
            break;
        }

        if (car == 'z' || car == 's' || car == 'q' || car == 'd')
        {
            player_store_current_case(map_get_case(player_get_pos().x, player_get_pos().y));

            game_move_pirates(pirates);

            game_check_ennemy(traps, pirates);
            
            map_set_case(player_get_pos().x, player_get_pos().y, PLAYER_SYMBOL);

            game_print();
        }

        fin = game_check_end();
    }

    game_end(game_check_win(player_get_pos(), treasure_get_pos()));

    game_free(traps, pirates);
}
