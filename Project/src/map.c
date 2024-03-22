#include "map.h"

#include <stdio.h>
#include <stdlib.h>

static char **game_map;

extern void map_init(void)
{
    for(int i=0; i< LIGNE; i++)
    {
        for(int j=0; j<COLONNE; j++)
        {
            game_map[i][j] = ' ';
        }
    }
}

extern void map_print()
{
    for(int j= 0; j<LIGNE; j++)
    {
        //ligne de delimitation
        for(int i=0; i<COLONNE; i++)
        {
            printf("+---");
        }
        printf("+\n");
        //ligne de contenu
        for(int i=0; i<COLONNE; i++)
        {
            printf("| ");
            printf("%c",game_map[j][i]); //contenu
            printf(" ");
        }
        printf("|\n");
    }
    //ligne de delimitation
    for(int i=0; i<COLONNE; i++)
    {
        printf("+---");
    }
    printf("+\n");
}

extern char map_get_case(int x, int y)
{
    return game_map[x][y];
}

extern void map_set_case(int x, int y, char c)
{
    game_map[x][y] = c;
}

extern bool map_is_empty(int x, int y)
{
    if(game_map[x][y] == ' ')
    {
        return true;
    }
    return false;
}

extern void map_new(void) {
    game_map = (char **)malloc(LIGNE * sizeof(char *));
    for (int i = 0; i < LIGNE; i++) {
        game_map[i] = (char *)malloc(COLONNE * sizeof(char));
    }
}

extern void map_free(void)
{
    for (int i = 0; i < LIGNE; i++) {
        free(game_map[i]);
    }
    free(game_map);
}