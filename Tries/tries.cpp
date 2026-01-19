#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
class Node {
    unordered_map<char, Node*> children;
    bool endOfString;
public:
    Node() {
        endOfString = false;
    }
};

class Tries {
    Node* root;
    public:
    Tries() {
        root = new Node();
    }

    void insert(string key) {
         Node* temp = root;
         for(int i = 0;i < key.size();i++){
            if(temp->children.count(key[i]) == 0) {
                temp->children[key[i]] = new Node();
            }

            temp = temp->children[key[i]];
         }

         temp->endOfString = true;
    }

    bool search(string key){
        Node* temp = root;
        for(int i = 0;i < key.size();i++){
            if(temp->children.count(key[i])){
               temp = temp->children[key[i]];
            } else {
                return false;
            }
        }

        return temp->endOfString;
    }

}

int main() {

    return 0;
}