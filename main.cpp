#include <iostream>
#include "Classes/Game.h"

using namespace std;

int main() {

    Game Game;

    /* map */
    Map Map(10,10);

    /* characters */
    Character Player(1,1);
    Map.SetPlayerPosition(1,1);
    Character Enemy1(3,8);
    Map.SetEnemyPosition(3,8);
    Character Enemy2(4,1);
    Map.SetEnemyPosition(4,1);

    //clear screen
    system("cls");

    /* Start Menu */
    Game::DrawStart();

    /* Game Loop */
    while (true){
        //if win the game
        if (Game.GetGameWin()){
            Game::DrawWin();
            break;
        }

        //if lose the game
        if (Game.GetGameOver()){
            Game::DrawLose();
            break;
        }

        //Draw Map
        Map.Draw();

        //Player-Enemy's Move & Change is position in the map
        Game.PlayerMove(&Player, &Map);
        Game.EnemyMove(&Enemy1, &Map);
        Game.EnemyMove(&Enemy2, &Map);

        //clear screen
        system("cls");
    }

    Map.SaveGameMap();

    return 0;
}
