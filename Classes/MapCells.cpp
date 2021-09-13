#include "MapCells.h"

MapCells::MapCells() {
    id = ' ';
}

char MapCells::GetId() const {return id;}
void MapCells::SetId(char Id) {id = Id;}

bool MapCells::IsPlayer() const {return id == 'P';}
bool MapCells::IsEnemy() const {return id == 'E';}
bool MapCells::IsGoal() const {return id == '$';}
bool MapCells::IsBlock() const {return id == '1';}