//
// Created by strange on 11/9/2021.
//

#include "Character.h"

Character::Character(int X, int Y) {
    x = X;
    y = Y;
}

void Character::SetPosition(int X, int Y) {
    x = X;
    y = Y;
}
int Character::GetX() const {return x;}
int Character::GetY() const {return y;}
