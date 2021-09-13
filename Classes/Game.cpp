//
// Created by strange on 11/9/2021.
//

#include <iostream>
#include "Game.h"

using namespace std;

Game::Game() {
    IsGameOver = false;
    IsGameWin = false;
}

bool Game::GetGameOver() const {return IsGameOver;}
void Game::SetGameOver() {IsGameOver = true;}

bool Game::GetGameWin() const {return IsGameWin;}
void Game::SetGameWin() {IsGameWin = true;}

//TODO: el jugador no gana la partida al llegar al objetivo
//TODO: el jugador no pierde al tocar a un enemigo
void Game::PlayerMove(Character *Player, Map *Map) {
    cout << "Type (w,s,a,d) in order to move the player\n";

    char i;
    cin >> i;
    switch (i) {
        case 'w':
            if (!(Map->Cells[Player->GetX()-1][Player->GetY()].IsBlock())){
                // delete last position in map
                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                // set new position in Player
                Player->SetPosition(Player->GetX()-1, Player->GetY());
                // set new position in Map
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
                // win & lose
                if (Map->Cells[Player->GetX()][Player->GetY()].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()][Player->GetY()].IsEnemy()) SetGameOver();
            }
            break;
        case 's':
            if (!(Map->Cells[Player->GetX()+1][Player->GetY()].IsBlock())){
                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                Player->SetPosition(Player->GetX()+1, Player->GetY());
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
                // win & lose
                if (Map->Cells[Player->GetX()][Player->GetY()].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()][Player->GetY()].IsEnemy()) SetGameOver();
            }
            break;
        case 'a':
            if (!(Map->Cells[Player->GetX()][Player->GetY()-1].IsBlock())){
                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                Player->SetPosition(Player->GetX(), Player->GetY()-1);
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
                // win & lose
                if (Map->Cells[Player->GetX()][Player->GetY()].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()][Player->GetY()].IsEnemy()) SetGameOver();
            }
            break;
        case 'd':
            if (!(Map->Cells[Player->GetX()][Player->GetY()+1].IsBlock())){
                Map->DeletePlayerPosition(Player->GetX(), Player->GetY());
                Player->SetPosition(Player->GetX(), Player->GetY()+1);
                Map->SetPlayerPosition(Player->GetX(), Player->GetY());
                // win & lose
                if (Map->Cells[Player->GetX()][Player->GetY()].IsGoal()) SetGameWin();
                if (Map->Cells[Player->GetX()][Player->GetY()].IsEnemy()) SetGameOver();
            }
            break;
        default:
            cout << "Incorrect Key\n";
            break;
    }
}