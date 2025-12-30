#include<iostream>
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

class Info{
    public:
    bool isBst;
    int min;
    int max;
    int size;

    Info(bool isBst,int min,int max,int size){
        this->isBst = isBst;
        this->min = min;
        this->max = max;
        this->size = size;
    }
};
static int maxSize;
Info* largestBst(Node* root){
    // this is second base case
    // if(root == NULL){
    //     return new Info(true, INT8_MAX,INT8_MIN,0);
    // }
    if(root == NULL) {
        return NULL;
    }
    if(root->left == NULL && root->right == NULL) {
        return new Info(true, root->data, root->data, 1);
    }
    
    Info* left = largestBst(root->left);
    Info* right = largestBst(root->right);
    int currMin = min(root->data, min(left->min, right->min));
    int currMax = max(root->data, max(left->max, right->max));
    int currSize = left->size + right->size + 1;

    if(left->isBst
        && right->isBst 
        && root->data > left->min 
        && root->data < right->max) {
      
       maxSize = max(currSize, maxSize);
       return new Info(true, currMin,currMax,currSize);
        } 

    return new Info(false, currMin, currMax, currSize);    
}
int main(){
      int arr[6] = {5,1,3,4,2,7};
      Node* root = buildBST(arr, 6);
    //   inOrder(root);
    //   cout << search(root, 10) << endl;
    printRange(root, 2,7);
    return 0;
}