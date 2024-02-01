//
// Created by Maryam Baig ID30454 on 3/5/23.
//

#ifndef HOMEWORK5__PLAYER_H
#define HOMEWORK5__PLAYER_H
#include <string>
#include "Board.h"
using namespace std;
class Player{
private:
    string name;
    int balance;
    Board &board;
    Node * position=board.returnfirst(); ///initialize position as head (updated in move function)

public:
    ///prametric constructor initialized in header file
    Player(Board &myboard, string names, int capital)
    : board(myboard),name(names),balance(capital)
    { }

    int move(int steps);
    Node * where_am_I();
    void pay_to_player(Player &other,int money);
    int get_balance();
    void deposit_money(int money);
    void buy_slot(int price);
    bool is_bankrupt();
    void display();


};

#endif //HOMEWORK5__PLAYER_H
