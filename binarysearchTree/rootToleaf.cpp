#include<iostream>
#include<vector>
using namespace std;
class Node {
    public:
      int val;

      Node* left;
      Node* right;

      Node(int val){
        this->val = val;
        left = right = NULL;
      }
};

Node* insert(Node* root,int val){
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }

    return root;
}
Node* buildBST(int arr[],int n){
    Node* root = NULL;

    for(int i = 0;i < n;i++){
      root = insert(root, arr[i]);
    }

    return root;
}
void printPath(vector<int> path){
    for(int i = 0;i < path.size();i++){
        cout << path[i] << " ";
    }

    cout << endl;
}

void pathNode(Node* root,vector<int> path){
    if(root == NULL){ 
        return;
    }

    path.push_back(root->val);

    if(root->left == NULL && root->right == NULL){
        printPath(path);
        path.pop_back();
        return;
    }
    pathNode(root->left, path);
    pathNode(root->right, path);

    path.pop_back();
}

void path(Node* root){
    vector<int> path;
    pathNode(root, path);
}
int main(){
      int arr[6] = {5,1,3,4,2,7};
      Node* root = buildBST(arr, 6);
      path(root);
    return 0;
}