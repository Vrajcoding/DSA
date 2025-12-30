// heigth == maxdepthoftree

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

static int idx = -1;
Node* bulidTree(vector<int> nodes) {
    idx++;
    if(nodes[idx] == -1) {
        return NULL;
    }
   Node* currNode =  new Node(nodes[idx]);
   currNode->left = bulidTree(nodes);
   currNode->right = bulidTree(nodes);

   return currNode;
}

int count(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int left = count(root->left);
    int right = count(root->right);

    return left+right+1;
}


int main() {

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    // vector<int> nodes2 = {1, 2, 4, -1, -1, 5, -1, 6, -1, 7, -1, -1, 3, -1, -1}; 
    Node *root = bulidTree(nodes);
    // Node *root2 = bulidTree(nodes2);
   cout << count(root) << endl;

    

    return 0;
}