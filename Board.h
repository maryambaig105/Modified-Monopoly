//
// Created by Maryam Baig ID30454 on 3/5/23.
//

#ifndef HOMEWORK5__BOARD_H
#define HOMEWORK5__BOARD_H
#include <string>

using namespace std;
struct Node {
    string owner;
    Node* next;
    Node ();
    Node (string o, Node * p);
};

class Board{
private:
    Node * first;
public:
    ///parametric constructor
    Board(int slots);
    ///destructor
    ~Board();
    ///print board
    void display();
    ///return owner of slot
    string who_owns(Node * ptr);
    ///return head Node
    Node * returnfirst();



};
#endif //HOMEWORK5__BOARD_H
