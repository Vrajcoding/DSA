#include <iostream>
#include <vector>
#include <queue>
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
Node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}
int kthAncestor(Node* root,int node,int K){
    if(root == NULL) {
        return -1;
    }

    if(root->data == node) {
        return 0;
    }

    int leftDis = kthAncestor(root->left, node, K);
    int rightDis = kthAncestor(root->right, node, K);

    if(leftDis == -1 && rightDis == -1){
        return -1;
    }

    int validDis = leftDis == -1 ? rightDis : leftDis;
    if(validDis + 1 == K) {
        cout << root->data << endl;
    }

    return validDis + 1;
}

int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    int n1 = 4, n2 = 5;
    kthAncestor(root,5,2);
    return 0;
}