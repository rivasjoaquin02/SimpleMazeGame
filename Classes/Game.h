//
// Created by strange on 11/9/2021.
//

#ifndef SIMPLEMAZEGAME_GAME_H
#define SIMPLEMAZEGAME_GAME_H

#include "Character.h"
#include "Map.h"

class Game {
protected:
    bool IsGameOver;
    bool IsGameWin;
    //score
public:

    /* Constructor */
    Game();

    /* Get & Set */
    bool GetGameOver() const;
    void SetGameOver();

    bool GetGameWin() const;
    void SetGameWin();

    /* Draw functions */

    static void DrawStart();
    static void DrawWin();
    static void DrawLose();

    /* Player Move */
    void PlayerMove(Character *Player, Map *Map);
    void EnemyMove(Character *Enemy, Map *Map);
};


#endif //SIMPLEMAZEGAME_GAME_H
