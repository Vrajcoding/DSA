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
void levelOrderNewLine(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);

    while (!Q.empty())
    {

        Node *curr = Q.front();
        Q.pop();

        if (curr == NULL)
        {
            if (Q.empty())
            {
                break;
            }
            cout << endl;
            Q.push(NULL);
        }
        else
        {
            cout << curr->data << " ";
            if (curr->left)
            {
                Q.push(curr->left);
            }

            if (curr->right)
            {
                Q.push(curr->right);
            }
        }
    }

    cout << endl;
}
int transform(Node* root){
    if(root == NULL) {
        return 0;
    }

    int leftOld = transform(root->left);
    int rightOld = transform(root->right);
    int currOld = root->data;
    root->data = leftOld + rightOld;
    if(root->left) {
        root->data +=  root->left->data;
    }

    if(root->right) {
       root->data +=  root->right->data;
    }
    return currOld;
}

int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = buildTree(nodes);

   transform(root);
   levelOrderNewLine(root);
    
    return 0;
}