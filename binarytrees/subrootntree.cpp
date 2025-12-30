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

int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    int curr = max(lh, rh) + 1;

    return curr;
}
bool isIdentical(Node* root1,Node* root2){
    if(root1 == NULL && root2 == NULL) {
        return true;
    } else if(root1 == NULL || root2 == NULL) {
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}
bool iss(Node* root, Node* subroot) {
      if(root == NULL && subroot == NULL) {
        return true;
    } else if(root == NULL || subroot == NULL) {
        return false;
    }

    if(root->data == subroot->data){
        if(isIdentical(root, subroot)) {
            return true;
        }
    }

   int leftiss = iss(root->left, subroot);
   if(!leftiss) {
       return (root->right, subroot);
   }

   return true;
}

// bool isIdentical2(Node* root,Node* right){
//     if(left == NULL && right == NULL){
//         return true;
//     } 

//     bool left = isIdentical2()
// }
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    
    Node *root = bulidTree(nodes);
    Node *subroot = new Node(2);
    subroot->left = new Node(4);
    subroot->right = new Node(7);
   cout << iss(root, subroot) << endl;
}