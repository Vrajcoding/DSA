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

void preoreder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preoreder(root->left);
    preoreder(root->right);
}

void inorder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> Q;
    Q.push(root);

    while (!Q.empty())
    {

        Node *curr = Q.front();
        Q.pop();

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

    cout << endl;
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
int main()
{

    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    Node *root = bulidTree(nodes);

    levelOrderNewLine(root);

    cout << endl;
    return 0;
}