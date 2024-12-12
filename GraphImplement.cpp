#include "GraphPointer.h"
#include <queue>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;



// Declare the collection to store all nodes
vector<graph*> all_nodes;

// BFS Implementation
int findPlaceBreadth(string start, string target) {
    if (start == target) return 0;  // If the start and target are the same

    queue<graph*> q;
    unordered_set<string> visited;  // To track visited nodes
    unordered_map<string, int> distances;  // To track the number of steps from start

    graph* current = nullptr;  // Pointer to traverse the graph

    // Find the starting node and add it to the queue
    for (graph* node : all_nodes) {
        if (node->name == start) {
            q.push(node);
            visited.insert(start);
            distances[start] = 0;
            break;
        }
    }

    while (!q.empty()) {
        current = q.front();
        q.pop();

        // Check all four directions for the current node
        graph* neighbors[] = {current->left, current->right, current->up, current->down};

        for (graph* neighbor : neighbors) {
            if (neighbor != nullptr && visited.find(neighbor->name) == visited.end()) {
                visited.insert(neighbor->name);
                q.push(neighbor);
                distances[neighbor->name] = distances[current->name] + 1;

                // If we find the target, return the number of steps
                if (neighbor->name == target) {
                    return distances[neighbor->name];
                }
            }
        }
    }

    return -1;  // If the target is not found
}

// DFS Implementation
int findPlaceDepth(string start, string target) {
    if (start == target) return 0;  // If the start and target are the same

    stack<graph*> s;
    unordered_set<string> visited;  // To track visited nodes
    unordered_map<string, int> distances;  // To track the number of steps from start

    graph* current = nullptr;  // Pointer to traverse the graph

    // Find the starting node and add it to the stack
    for (graph* node : all_nodes) {
        if (node->name == start) {
            s.push(node);
            visited.insert(start);
            distances[start] = 0;
            break;
        }
    }

    while (!s.empty()) {
        current = s.top();
        s.pop();

        // Check all four directions for the current node
        graph* neighbors[] = {current->left, current->right, current->up, current->down};

        for (graph* neighbor : neighbors) {
            if (neighbor != nullptr && visited.find(neighbor->name) == visited.end()) {
                visited.insert(neighbor->name);
                s.push(neighbor);
                distances[neighbor->name] = distances[current->name] + 1;

                // If we find the target, return the number of steps
                if (neighbor->name == target) {
                    return distances[neighbor->name];
                }
            }
        }
    }

    return -1;  // If the target is not found
}

void outputGraph() {
    cout << "Graph Structure (Adjacency List):" << endl;
    for (graph* node : all_nodes) {
        cout << node->name << " -> ";
        bool first = true;
        if (node->left) {
            cout << (first ? "" : ", ") << node->left->name;
            first = false;
        }
        if (node->right) {
            cout << (first ? "" : ", ") << node->right->name;
            first = false;
        }
        if (node->up) {
            cout << (first ? "" : ", ") << node->up->name;
            first = false;
        }
        if (node->down) {
            cout << (first ? "" : ", ") << node->down->name;
        }
        cout << endl;
    }
}


int main() {
    string input = "";
    string target = "start";
    string start = "gas";
    int counter = 0;

    // Create graph nodes
    graph* zero = new graph("start");
    graph* one = new graph("home");
    graph* two = new graph("store");
    graph* three = new graph("school");
    graph* four = new graph("gym");
    graph* five = new graph("family");
    graph* six = new graph("gas");
    graph* seven = new graph("neighborhood");
    graph* eight = new graph("church");
    graph* nine = new graph("grandparents");
    graph* ten = new graph("sister");
    graph* eleven = new graph("brother");
    graph* twelve = new graph("daughter");

    // Add all nodes to the all_nodes collection
    all_nodes = {zero, one, two, three, four, five, six, seven, eight, nine, ten, eleven, twelve};

    // Set up connections (edges)
    zero->right = one;
    one->left = zero;
    one->down = four;
    two->down = six;
    two->right = three;
    three->left = two;
    three->right = four;
    three->down = seven;
    four->up = one;
    four->left = three;
    four->right = five;
    four->down = eight;
    five->left = four;
    five->right = nine;
    six->up = two;
    six->right = seven;
    seven->left = six;
    seven->up = three;
    seven->right = eight;
    seven->down = ten;
    eight->left = seven;
    eight->up = four;
    eight->right = nine;
    eight->down = eleven;
    nine->left = eight;
    nine->up = five;
    nine->down = twelve;
    ten->up = seven;
    ten->right = eleven;
    eleven->left = ten;
    eleven->up = eight;
    eleven->right = twelve;
    twelve->left = eleven;
    twelve->up = nine;

    outputGraph();

    while (input != "n" && input != "N") {

        cout << "Start: ";
        cin >> start;
        cout << "Target? ";
        cin >> target;

        counter = findPlaceBreadth(start, target);
        cout << "\nFrom " << start << " to " << target << " took " << counter << " steps using breadth first!" << endl;
        counter = findPlaceDepth(start, target);
        cout << "\nFrom " << start << " to " << target << " took " << counter << " steps using depth first!" << endl;

        cout << "\nSearch again? (y/n): ";
        cin >> input;
    }

    // Clean up allocated memory (optional, but good practice)
    for (graph* node : all_nodes) {
        delete node;
    }

    return 0;
}
