#include "Game.h"
#include <iostream>
#include <cstdlib>  /* srand, rand */
#include <ctime>    /* time */
#include <fstream>  /* DrawStart, DrawWin, DrawLose */

using namespace std;

Game::Game() {
    IsGameOver = false;
    IsGameWin = false;

    //TODO: change rand for modern rand
    // Initialize random seed
    srand (time(nullptr));
}

bool Game::GetGameOver() const {return IsGameOver;}
void Game::SetGameOver() {IsGameOver = true;}

bool Game::GetGameWin() const {return IsGameWin;}
void Game::SetGameWin() {IsGameWin = true;}

void Game::DrawStart() {
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

void Game::DrawWin() {
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

void Game::DrawLose() {
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


void Game::PlayerMove(Character *Player, Map *Map) {
    cout << "Type (w,s,a,d) in order to move the player... ";

    char i;
    cin >> i;
    switch (i) {
        case 'w':
            if (!(Map->Cells[Player->GetX()-1][Player->GetY()].IsBlock())){
                // win & lose
                if (Map->Cells[Player->GetX()-1][Player->GetY()].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()-1][Player->GetY()].IsEnemy()) SetGameOver();

                // delete last position in map
                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                // set new position in Player
                Player->SetPosition(Player->GetX()-1, Player->GetY());
                // set new position in Map
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
            }
            break;
        case 's':
            if (!(Map->Cells[Player->GetX()+1][Player->GetY()].IsBlock())){
                if (Map->Cells[Player->GetX()+1][Player->GetY()].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()+1][Player->GetY()].IsEnemy()) SetGameOver();

                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                Player->SetPosition(Player->GetX()+1, Player->GetY());
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
            }
            break;
        case 'a':
            if (!(Map->Cells[Player->GetX()][Player->GetY()-1].IsBlock())){
                if (Map->Cells[Player->GetX()][Player->GetY()-1].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()][Player->GetY()-1].IsEnemy()) SetGameOver();

                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                Player->SetPosition(Player->GetX(), Player->GetY()-1);
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
            }
            break;
        case 'd':
            if (!(Map->Cells[Player->GetX()][Player->GetY()+1].IsBlock())){
                if (Map->Cells[Player->GetX()][Player->GetY()+1].IsGoal())SetGameWin();
                if (Map->Cells[Player->GetX()][Player->GetY()+1].IsEnemy())SetGameOver();

                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                Player->SetPosition(Player->GetX(), Player->GetY()+1);
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
            }
            break;
        default:
            cout << "Incorrect Key\n";
            break;
    }
}

void Game::EnemyMove(Character *Enemy, Map *Map) {

    //random move
    int XoY = rand() %2;
    const int oldX = Enemy->GetX();
    const int oldY = Enemy->GetY();
    int newX, newY;

    if (XoY == 0){ //move in X axis
        int Xaxis = rand() %2;

        //TODO: redundant code
        switch (Xaxis) {

            case 0: // 'w' move
                newX = oldX-1;

                //move always is not a block or the goal
                if (!(Map->Cells[newX][oldY].IsBlock()) and !(Map->Cells[newX][oldY].IsGoal())){
                    if (Map->Cells[newX][oldY].IsPlayer()) SetGameOver();

                    Map->DeleteEnemyPosition(oldX, oldY);
                    Enemy->SetPosition(newX, oldY);
                    Map->SetEnemyPosition(newX, oldY);
                }
                break;
            case 1: // 's' move
                newX = oldX+1;

                //move always is not a block or the goal
                if (!(Map->Cells[newX][oldY].IsBlock()) and !(Map->Cells[newX][oldY].IsGoal())){
                    if (Map->Cells[newX][oldY].IsPlayer()) SetGameOver();

                    Map->DeleteEnemyPosition(oldX, oldY);
                    Enemy->SetPosition(newX, oldY);
                    Map->SetEnemyPosition(newX, oldY);
                }
                break;
            default:
                cout << "default Xaxis";
                break;
        }
    }
    else { //move in Y axis
        int Yaxis = rand() %2;

        switch (Yaxis) {
            case 0: // 'a' move
                newY = oldY-1;

                if (!(Map->Cells[oldX][newY].IsBlock()) and !(Map->Cells[oldX][newY].IsGoal())){
                    if (Map->Cells[oldX][newY].IsPlayer()) SetGameOver();

                    Map->DeletePlayerPosition(oldX,oldY);
                    Enemy->SetPosition(oldX,newY);
                    Map->SetEnemyPosition(oldX,newY);
                }
                break;
            case 1: // 'd' move
                newY = oldY+1;

                if (!(Map->Cells[oldX][newY].IsBlock()) and !(Map->Cells[oldX][newY].IsGoal())){
                    if (Map->Cells[oldX][newY].IsPlayer()) SetGameOver();

                    Map->DeletePlayerPosition(oldX,oldY);
                    Enemy->SetPosition(oldX,newY);
                    Map->SetEnemyPosition(oldX,newY);
                }
                break;
            default:
                cout << "default Yaxis";
                break;
        }
    }
}

