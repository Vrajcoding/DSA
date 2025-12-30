#include <bits/stdc++.h>
using namespace std;

// show in leetcode
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class List
{

public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList(Node *head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    Node* merge(Node* rightHead, Node* leftHead) {
        Node* i = rightHead;
        Node* j = leftHead;
        List ans;

        while(i && j) {
            if(i->data <= j->data) {
                ans.push_back(i->data);
                i = i->next;
            } else {
                ans.push_back(j->data);
                j = j->next;
            }
        }

        while(i) {
            ans.push_back(i->data);
            i = i->next;
        }

        while (j)
        {
           ans.push_back(j->data);
            j = j->next;
        }

        return ans.head;
        
    }
    Node* mergeKLists(vector<Node*> &list) {
        Node* head = NULL;
        for(int i = 0;i < list.size();i++) {
            head = merge(list[i], list[i+1]);
        }
        return head;
    }
};

int main()
{
    List ll1;
    List ll2;
    List ll3;
    ll1.push_back(1);
    ll1.push_back(4);
    ll1.push_back(5);

    ll2.push_back(1);
    ll2.push_back(3);
    ll2.push_back(4);
    vector<Node*> lists;
    lists.push_back(ll1.head);
    lists.push_back(ll2.head);
    
    return 0;
}