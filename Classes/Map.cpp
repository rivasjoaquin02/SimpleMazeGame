#include "Map.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

Map::Map(int X, int Y) {
    sizeX = X;
    sizeY = Y;
    LoadGameMap();
}

void Map::Draw() {
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++)
            cout << Cells[i][j].GetId();
        cout << '\n';
    }
    cout << '\n';
}


void Map::LoadGameMap() {
    string line;

    ifstream MyFile("Map.txt");
    if (MyFile.is_open()) {
        for (int i = 0; getline(MyFile, line); i++)
            for (int j = 0; j < line.length(); j++)
                if (line[j] != '0') Cells[i][j].SetId(line[j]);

        MyFile.close();
    } else {
        cout << "Error: Map File no could be READ\n";
    }
}

void Map::SaveGameMap() {
    ofstream MyFile("MapSave.txt");
    if (MyFile.is_open()) {
        for (int i = 0; i < sizeX; i++)
            for (int j = 0; j < sizeY; j++)
                MyFile << Cells[i][j].GetId() <<'\n';

        MyFile.close();
    } else {
        cout << "Error: Map File no could be WRITE\n";
    }
}

void Map::DeletePlayerPosition(int x, int y){Cells[x][y].SetId(' ');}
void Map::DeleteEnemyPosition(int x, int y) {Cells[x][y].SetId(' ');}

void Map::SetPlayerPosition(int x, int y) {Cells[x][y].SetId('P');}
void Map::SetEnemyPosition(int x, int y) {Cells[x][y].SetId('E');}


