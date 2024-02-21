#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "players.h"

// Returns true if the player name matches one of the existing players
bool player_exists(player *players, int num_players, char *name)
{
    for(int x = 0; x < num_players; x++){
        if(strcmp(players[x].name,name)==0)
        {
            return true
        }
    }
    return false;
}

// Go through the list of players and update the score for the 
// player given their name
void update_score(player *players, int num_players, char *name, int score)
{
    for(int x = 0; x < num_players; x++)
    {
            if(strcmp(players[x].name,name)==0)
            {
                players[x].score = players[x].score + score;
            }
    }
    
}
