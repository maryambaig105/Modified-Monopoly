//
// Created by Maryam Baig ID30454 on 3/5/23.
//
#include "Player.h"
#include<iostream>
int Player::move(int steps){
    position=this->where_am_I();
    Node * ptr=this->position;///start moving from players position
    int passed=0;///if player passed starting node
    for(int i=0;i<steps;i++){
        ptr=ptr->next;
        if(ptr==this->board.returnfirst()){
            passed=1;
        }

    }
    this->position=ptr;
    return passed;
}

Node *Player:: where_am_I(){
    return this->position;
}

void Player::pay_to_player(Player &other,int money){
    this->balance=this->balance-money; ///remove money from current player
    other.deposit_money(money); ///give money to other player
}

int Player::get_balance(){
    return this->balance;
}

void Player::deposit_money(int money){
    this->balance=this->balance+money;
}

void Player::buy_slot(int price){
    this->position->owner=this->name;
    this->balance=this->balance-price;
}

bool Player::is_bankrupt(){
    if(this->balance<0){
        return true;
    }
    return false;
}

void Player::display(){
    ////each posiiton is 6 characters, leave spaces according to players position on board
    Node * ptr =this->position,*head=this->board.returnfirst();
    int position=0;
    string space="";
    while(head!=ptr){
        head=head->next;
        position++;
    }
    for(int i=0;i<position*6;i++){
        space+=" ";
    }
    cout<<space<<this->name<<" "<<this->balance<<endl;
}