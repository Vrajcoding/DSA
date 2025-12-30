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
bool Nodetopath(Node* root,int n,vector<int> &path){
    if(root == NULL) {
        return false;
    }

    path.push_back(root->data);
    if(root->data == n){
        return true;
    }

   bool left =  Nodetopath(root->left, n, path);
   bool right = Nodetopath(root->right, n, path);

   if(left || right) {
    return true;
   }
   path.pop_back();
   return false;
}


int LCA(Node* root,int n1,int n2){
   vector<int> path1;
   vector<int> path2;

   Nodetopath(root, n1, path1);
   Nodetopath(root, n2, path2);


   int lca = -1;

   for(int i = 0,j = 0;i < path1.size() && j < path2.size();i++, j++){
    if(path1[i] != path2[j]){
        return lca;
    }

    lca = path1[i];
   }

   return lca;
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

int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

    int n1 = 4, n2 = 5;
    cout << LCA2(root, n1, n2)->data;
    cout << endl;
    return 0;
}