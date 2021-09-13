//
// Created by strange on 11/9/2021.
//

#ifndef SIMPLEMAZEGAME_CHARACTER_H
#define SIMPLEMAZEGAME_CHARACTER_H


class Character {
protected:
    int x,y;
public:
    /* Constructor */
    Character(int X, int Y);

    /* Set Position */
    void SetPosition(int X,int Y);
    int GetX() const;
    int GetY() const;
};


#endif //SIMPLEMAZEGAME_CHARACTER_H
