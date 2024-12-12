#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string data;
    string def;
    Node* left;
    Node* right;

    Node(string n, string d) : data(n), def(d), left(nullptr), right(nullptr) {}
};

void insertBST(string n, Node* &next, string d) {
    if (next == nullptr) {
        next = new Node(n, d); // Insert the new node if current is nullptr
        return;
    }

    if (n < next->data) {
        insertBST(n, next->left, d); // Recurse to left if the word is smaller
    } else if (n > next->data) {
        insertBST(n, next->right, d); // Recurse to right if the word is larger
    }
    // If n == next->data, do nothing as we don't want duplicates in this case
}

void output(Node* root) {
    if (root == nullptr) {
        return;
    }

    output(root->left); // Visit left subtree
    cout << root->data << endl; // Print current node data and definition
    output(root->right); // Visit right subtree
}

int main() {
    string input = "y";
    string words[] = {"abase", "accentuate", "baffle", "belittle", "callow", "capitulate"};
    string definitions[] = {"cause to feel shame", "stress or single out as important", "be a mystery or bewildering to",
                            "lessen the authority, dignity, or reputation of", "young and inexperienced",
                            "surrender under agreed conditions"};

    Node* root = nullptr;

    for (int i = 0; i < 6; i++) {
        insertBST(words[i], root, definitions[i]); // Insert words into the BST
    }

    while (input != "exit") {
        cout << "Words: " << endl;
        output(root);
        cout << "Input word for definition or 'exit' to quit program: ";
        cin >> input;

        // Search for the word in the BST
        Node* temp = root;
        bool found = false;
        while (temp != nullptr) {
            if (input < temp->data) {
                temp = temp->left; // Move left
            } else if (input > temp->data) {
                temp = temp->right; // Move right
            } else {
                cout << "Definition of " << input << ": " << temp->def << endl;
                found = true;
                break;
            }
        }

        if (!found && input != "exit") {
            cout << "Word not found!" << endl;
        }
    }

    return 0;
}
