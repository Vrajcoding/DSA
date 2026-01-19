#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
#include<map>
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

void topView(Node* root) {
    queue<pair<Node*, int>> Q;
    map<int, int> m;

    Q.push(make_pair(root, 0));
    while(!Q.empty()){
        pair<Node*, int> curr = Q.front();
        Q.pop();

        Node* currNode = curr.first;
        int hd = curr.second;
        m[hd] = currNode->data;  
        if(currNode->left) {
            pair<Node*, int> left = make_pair(currNode->left, hd-1);
            Q.push(left);
        }

        if(currNode->right) {
           pair<Node*, int> right = make_pair(currNode->right, hd+1);
           Q.push(right);
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }
    
}



int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  vector<int> node2 =   {20, 8, 22, 5, 3, 4, 25, -1, -1, 10, 14, -1, -1, 28, -1, -1, -1, -1, -1, -1, -1, -1};
    
    Node *root = bulidTree(nodes);
    Node *root2 = bulidTree(node2);
    topView(root2);

   return 0;
}