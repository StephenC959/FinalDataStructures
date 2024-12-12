#ifndef GRAPHPOINTER_H_INCLUDED
#define GRAPHPOINTER_H_INCLUDED

#include <string>

class graph {
public:
    std::string name;
    graph* left;
    graph* right;
    graph* up;
    graph* down;

    graph() : left(nullptr), right(nullptr), up(nullptr), down(nullptr) {}
    graph(std::string location) : name(location), left(nullptr), right(nullptr), up(nullptr), down(nullptr) {}
};


#endif // GRAPHPOINTER_H_INCLUDED
