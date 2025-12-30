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
void inOrder(Node* root){
    if(root == NULL) {
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

bool search(Node* root,int key){
    if(root == NULL) {
        return false;
    }

    if(root->val == key){
        return true;
    }
    if(root->val < key) {
        return search(root->right,key);
    } else {
        return search(root->left, key);
    }
}
Node* getInorderSuceeser(Node* root){
    while (root->left != NULL)
    {
        root = root->left;
    }

    return root;  
}
Node* deleteNode(Node* root,int val){
    if(root == NULL){
        return NULL;
    }

    if(root->val < val){
        root->right = deleteNode(root->right, val);
    } else if(root->val > val){
        root->left = deleteNode(root->left, val);
    }else {
        // case 1:

        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //case 2: 1 child
        if(root->left == NULL || root->right == NULL){
            return root->left == NULL ? root->right : root->left;
        }

       // case 3: 2 child
       Node* IS = getInorderSuceeser(root->right);
       root->val = IS->val;
       root->right = deleteNode(root->right, IS->val);
       return root;
    }
}

void printRange(Node* root,int st,int end){

    if(root == NULL){
        return;
    }

    if(st <= root->val && root->val <= end){
        printRange(root->left,st, end);
        cout << root->val << " ";
        printRange(root->right, st, end);
    } else if(root->val < st){
         printRange(root->right, st, end);
    } else {
        printRange(root->left,st, end);
    }
}
int main(){
      int arr[6] = {5,1,3,4,2,7};
      Node* root = buildBST(arr, 6);
    //   inOrder(root);
    //   cout << search(root, 10) << endl;
    printRange(root, 2,7);
    return 0;
}