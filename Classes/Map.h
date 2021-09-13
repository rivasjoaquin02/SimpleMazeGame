//
// Created by strange on 11/9/2021.
//

#ifndef SIMPLEMAZEGAME_MAP_H
#define SIMPLEMAZEGAME_MAP_H

#include "MapCells.h"

class Map {
public:
    MapCells Cells[100][100];

    /* Map constructor */
    Map();

    /* Draw functions */
    void Draw();
    static void DrawStart();
    static void DrawWin();
    static void DrawLose();

    /* Load & Save Map */
    void LoadGameMap();
    void SaveGameMap();

    /* delete last player position */
    void DeletePlayerPosition(int x, int y);

    /* Set Player Position */
    void SetPlayerPosition(int x, int y);
    /* Set Enemy Position */
    void SetEnemyPosition(int x, int y);
};


#endif //SIMPLEMAZEGAME_MAP_H
