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
Node *bulidTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }

    Node *currNode = new Node(nodes[idx]);
    currNode->left = bulidTree(nodes);
    currNode->right = bulidTree(nodes);

    return currNode;
}
void kThlevelHelper(Node* root,int K,int curr){
    if(root == NULL) {
        return;
    }

    if(curr == K) {
        cout << root->data << " ";
        return;
    }

    kThlevelHelper(root->left, K, curr+1);
    kThlevelHelper(root->right, K, curr+1);
}
void kthLevel(Node* root,int K){
   kThlevelHelper(root, K, 1);
}

// second approach

void kThLevel2(Node* root,int K){
    if(root == NULL) {
        return;
    }
    int count = 1;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr == NULL) {
            count++;
            if(q.empty()) {
                break;
            }
           q.push(NULL);
        } else {
            if(count == K){
                cout << curr->data << " ";
            } 
             if(curr->left) {
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }  
         
        }
    }
}
int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = bulidTree(nodes);
 
    // kthLevel(root,3);
    kThLevel2(root, 3);
      

    cout << endl;
    return 0;
}