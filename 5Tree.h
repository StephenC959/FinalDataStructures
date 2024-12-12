#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <string>

using namespace std;

class Tree{

public:


    string data;
    Tree* first;
    Tree* second;
    Tree* third;
    Tree* fourth;
    Tree* last;


    Tree(){}

    Tree(string data1, Tree* next1){
        data = data1;
        first = next1;
    }

    Tree(string data1, Tree* next1, Tree* next2){
        data = data1;
        first = next1;
        second = next2;
    }
    Tree(string data1, Tree* next1, Tree* next2, Tree* next3){
        data = data1;
        first = next1;
        second = next2;
        third = next3;
    }
    Tree(string data1, Tree* next1, Tree* next2, Tree* next3, Tree* next4){
        data = data1;
        first = next1;
        second = next2;
        third = next3;
        fourth = next4;
    }
    Tree(string data1, Tree* next1, Tree* next2, Tree* next3, Tree* next4, Tree* next5){
        data = data1;
        first = next1;
        second = next2;
        third = next3;
        fourth = next4;
        last = next5;
    }

    Tree(string data1){
        data = data1;
    }

};



#endif // TREE_H_INCLUDED
