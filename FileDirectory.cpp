#include "5Tree.h"
#include <iostream>
#include <stack>
#include <memory>

using namespace std;

void outputTree(Tree* output){

    cout << output -> data << ": \n";

    if(output -> first != nullptr)
        cout << "   " << output -> first -> data << endl;
    if(output -> second != nullptr)
        cout << "   " << output -> second -> data << endl;
    if(output -> third != nullptr)
        cout << "   " << output -> third -> data << endl;
    if(output -> fourth != nullptr)
        cout << "   " << output -> fourth -> data << endl;
    if(output -> last != nullptr)
        cout << "   " << output -> last -> data << endl;
    cout << endl;
    cout << "Enter file name to open, D to delete folder, A to add a new folder, B to go back or E to exit\n";

}

void addElement(Tree* next, Tree* add){
    if(next->first == nullptr){
        next-> first = add;
    }
     else if(next->second == nullptr){
        next->second = add;
    }
     else if(next->third == nullptr){
        next->third = add;
    }
     else if(next->fourth == nullptr){
        next->fourth = add;
    }
     else if(next->last == nullptr){
        next->last = add;
    }
    else{
        std::cout << "Folder full\n";
        return;
    }
    std::cout << "Folder Added\n";

}

void deleteElement(Tree* check, string dElem){
    if (check->first != nullptr && check->first->data == dElem) {
        check->first = nullptr;
    }
    else if (check->second != nullptr && check->second->data == dElem) {
        check->second = nullptr;
    }
    else if (check->third != nullptr && check->third->data == dElem) {
        check->third = nullptr;
    }
    else if (check->fourth != nullptr && check->fourth->data == dElem) {
        check->fourth = nullptr;
    }
    else if (check->last != nullptr && check->last->data == dElem) {
        check->last = nullptr;
    } else {
        std::cout << "Folder does not exist\n";
        return;
    }
    std::cout << "Folder deleted successfully\n";
}

bool checkFolders(Tree* check, string folderName){
    if (check->first != nullptr && check->first->data == folderName) return true;
    if (check->second != nullptr && check->second->data == folderName) return true;
    if (check->third != nullptr && check->third->data == folderName) return true;
    if (check->fourth != nullptr && check->fourth->data == folderName) return true;
    if (check->last != nullptr && check->last->data == folderName) return true;
    return false;
}

Tree* openFolders(Tree* check, string folderName){
    if(check->first->data == folderName){
        return check->first;
    }
     else if(check->second->data == folderName){
        return check->second;

    }
     else if(check->third->data == folderName){
        return check->third;

    }
     else if(check->fourth->data == folderName){
        return check->fourth;
    }
     else if(check->last->data == folderName){
        return check->last;
    }
}


int main(){
    string input = "";
    string name;
    Tree* me = new Tree("me");
    Tree* joe = new Tree("joe");
    Tree* process32 =  new Tree("process32");
    Tree* documents = new Tree("documents");
    Tree* programFiles = new Tree("programFiles");
    Tree* programFilesX86 = new Tree("programFilesX86");
    Tree* users =  new Tree("users", me, joe);


    Tree* mainTree = new Tree("Local Disk(C:)");
    mainTree->first = process32;
    mainTree->second = documents;
    mainTree->third = programFiles;
    mainTree->fourth = programFilesX86;
    mainTree->last = users;



     stack<Tree*> path;
     stack<Tree*> temp;

    path.push(mainTree);

    while(input != "E" && !path.empty()){              //Runs program until exited or everything is deleted
        if(!path.empty()){
            outputTree(path.top());                    //Outputs available folders
            cin >> input;
        }
        else
            input = "E";


        if(input == "A"){                              //Add file to directory
            cout << "Enter File Name: ";
            cin >> name;
            Tree* temp = new Tree(name);
            addElement(path.top(), temp);
        }
        else if(input == "D"){                         //Delete a file from directory
            cout << "Enter File Name: ";
            cin >> name;
            deleteElement(path.top(), name);
        }
        else if(checkFolders(path.top(), input)){      //Traversal through directory
            path.push(openFolders(path.top(),input));
        }
        else if(input == "B" && !path.empty()){        //Returns to last accessed branch
            path.pop();
        }


    }

    cout << "Program Exited\n";


    return 0;
}
