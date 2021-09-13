#include <iostream>
#include "Classes/Game.h"

using namespace std;

int main() {

    Game Game;
    Map Map; //TODO: user be enable to setup the grid size of the map
    Character Player(1,1);
    Map.SetPlayerPosition(1,1);

    /* Start Menu */
    Map.DrawStart();

    /* Game Loop */
    while (true){
        //if win the game
        if (Game.GetGameWin()){
            Map.DrawWin();
            break;
        }

        //if lose the game
        if (Game.GetGameOver()){
            Map.DrawLose();
            break;
        }

        //Draw Map
        Map.Draw();

        //Player Move & Change is position in the map
        Game.PlayerMove(&Player, &Map);
    }

    Map.SaveGameMap();



    return 0;
}
