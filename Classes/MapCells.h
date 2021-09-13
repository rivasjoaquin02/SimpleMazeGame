//
// Created by strange on 11/9/2021.
//

#ifndef SIMPLEMAZEGAME_MAPCELLS_H
#define SIMPLEMAZEGAME_MAPCELLS_H

class MapCells {
protected:
    /* Cell */
    char id;
public:
    /* constructor */
    MapCells();

    /* Get & Set */
    char GetId() const;
    void SetId(char Id);

    bool IsPlayer() const;
    bool IsEnemy() const;
    bool IsGoal() const;
    bool IsBlock() const;
};


#endif //SIMPLEMAZEGAME_MAPCELLS_H
