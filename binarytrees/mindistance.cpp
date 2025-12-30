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


// approach 2
Node* LCA2(Node* root,int n1,int n2){
    if(root == NULL) {
        return NULL;
    }
    
    if(root->data == n1 || root->data == n2){
        return root;
    }


    Node* left = LCA2(root->left, n1, n2);
    Node* right = LCA2(root->right, n1, n2);

    if(left && right) {
        return root;
    }

    return left == NULL ? right : left;
}
int dist(Node* root,int n){
    if(root == NULL) {
        return -1;
    }

    if(root->data  == n){
        return 0;
    }

    int leftDis = dist(root->left, n);
    if(leftDis != -1){
      return leftDis + 1;
    }

    int rightDis = dist(root->right, n);
    if(rightDis != -1){
        return rightDis + 1;
    }

    return -1;
}
int minDistance(Node* root,int n1,int n2){
    Node* lca = LCA2(root, n1, n2);

    int dist1 = dist(lca, n1);
    int dist2 = dist(lca, n2);
    
    return dist1 + dist2;
}
int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    int n1 = 5, n2 = 3;
    cout << minDistance(root, n1, n2);
    cout << endl;
    return 0;
}