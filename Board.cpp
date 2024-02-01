//
// Created by Maryam Baig ID30454 on 3/5/23.
//
#include "Board.h"
#include <iostream>
///default Node constructor
Node::Node(){
    owner="";
    next=NULL;
}
///parametric Node constructor
Node::Node(string o, Node * p){
    owner=o;
    next=p;
}
///paramatric Board constructor
Board ::Board(int slots){
    first=new Node();
    Node *ptr=first;
    ptr->owner ="None";
    for(int i =1;i<slots;i++){ ///start from 1 since first node intialized outside loop

        ptr->next=new Node();
        ptr=ptr->next;
        ptr->owner ="None"; ///initialize owners as none
    }
    ptr->next=first; ///conect last node to first node to make it circular
}

///delete board
Board::~Board()
{
    Node *temp, *current;
    current = first->next;

    while(current != first) {
        temp = current->next;
        delete current;
        current =NULL;
        current = temp;
    }
}

void Board::display(){
    Node * ptr=first;
    string loop1="",loop2="",loop3=""; ///loop1 to measure length of top line of the board, loop2 to print second line
/// of board,loop 3 to print last line of board
    int len=0,count=0; ///len to calculate how many times pattern for loop3 to be repeated, count to count how many
/// spaces needed in loop2
   do
    {
        if(ptr->next==first){ ///if last node dont print another arrow
            cout<<ptr->owner;
            loop1+=ptr->owner;
            count+=4;
        }
       else if(ptr->owner!="None"){
           cout << ptr->owner << " ->";
           loop1+=ptr->owner+" ->";
           count+=6;

       }
       else{
           cout << ptr->owner << "->";
           loop1+=ptr->owner+"->";
           count+=6;

       }
        ptr = ptr-> next;
    } while (ptr != first);
   cout<<endl;

    len=loop1.length();
    loop2+="^";
    for(int i=0;i<count-2;i++){
        loop2+=" ";
    }
    loop2+="|";
    cout<<loop2;
    cout<<endl;

    loop3+="|----<";
    for(int i=0;i<(len-9)/6;i++){ /// len -9 since 9 characters being added before and after for loop, divide by 6
/// since 6 characters in each pattern
        loop3+="-----<";
    }
    loop3+="---v";
    cout<<loop3<<endl;

}

string Board::who_owns(Node*ptr){
    return ptr->owner;
}

Node * Board::returnfirst(){
    return first;
}



