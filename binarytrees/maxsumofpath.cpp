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
int maxSum(Node* root,int maxsum){
    if(root == NULL) {
        return 0;
    }

    int leftVal = maxSum(root->left,maxsum);
    int rightVal = maxSum(root->right,maxsum);

    int totalSum = leftVal + rightVal + root->data;

    return max(totalSum, maxsum);
}

int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = bulidTree(nodes);

   cout <<  maxSum(root, 0) << endl;
    return 0;
}