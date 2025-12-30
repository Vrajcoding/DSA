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


int diameter(Node* root) {
     if(root == NULL) {
        return 0;
    }

    int currDia = height(root->left) + height(root->right) + 1;
    int leftdia = diameter(root->left);
    int rightdia = diameter(root->right);

    return max(currDia, max(rightdia, leftdia));
}

// approach 2
pair<int, int> diameter2(Node* root) {
    if(root == NULL) {
        return make_pair(0,0);
    }

    pair<int, int> leftInfo = diameter2(root->left);
    pair<int, int> rightInfo = diameter2(root->right);

    int currDia = leftInfo.second + rightInfo.second + 1;
    int finalDia = max(currDia, max(leftInfo.first, rightInfo.first));
    int finalHt = max(leftInfo.second ,rightInfo.second) + 1;

    return make_pair(finalDia, finalHt);
}
int main() {
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    
    Node *root = bulidTree(nodes);
   
    cout << diameter2(root).first << endl;
   
}