//
// Created by strange on 11/9/2021.
//

#include "Map.h"
#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

Map::Map() {
    LoadGameMap();
}

void Map::Draw() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            cout << Cells[i][j].GetId();
        cout << '\n';
    }
    cout << '\n';
}

void Map::DrawStart() {
    string line;

    ifstream MyFile("Start.txt");
    if (MyFile.is_open()) {
        for (int i = 0; getline(MyFile, line); i++) {
            cout << line << '\n';
        }
        MyFile.close();
    } else {
        cout << "Error: Start File no could be open\n";
    }
}

void Map::DrawWin() {
    string line;

    ifstream MyFile("Win.txt");
    if (MyFile.is_open()) {
        for (int i = 0; getline(MyFile, line); i++) {
            cout << line << '\n';
        }
        MyFile.close();
    } else {
        cout << "Error: Win File no could be open\n";
    }
}

void Map::DrawLose() {
    string line;

    ifstream MyFile("Lose.txt");
    if (MyFile.is_open()) {
        for (int i = 0; getline(MyFile, line); i++) {
            cout << line << '\n';
        }
        MyFile.close();
    } else {
        cout << "Error: Lose File no could be open\n";
    }
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
        cout << "Error: Map File no could be read\n";
    }
}

void Map::SaveGameMap() {
    ofstream MyFile("MapSave.txt");
    if (MyFile.is_open()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                MyFile << Cells[i][j].GetId();
            MyFile << '\n';
        }

        MyFile.close();
    } else {
        cout << "Error: Map File no could be write\n";
    }
}


void Map::DeletePlayerPosition(int x, int y){Cells[x][y].SetId(' ');}

void Map::SetPlayerPosition(int x, int y) {Cells[x][y].SetId('P');}

void Map::SetEnemyPosition(int x, int y) {Cells[x][y].SetId('E');}

