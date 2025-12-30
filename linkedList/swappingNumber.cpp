#include <bits/stdc++.h>
using namespace std;
// completed
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
    int getSize(Node* head) {
        int size = 0;
        Node* temp = head;

        while (temp)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }

    Node* traversal(Node* head,int k){
        Node* prev = NULL;
        Node* curr = head;
        for(int i = 0;i < k;i++) {
           prev = curr;
           curr = curr->next;
        }

        return prev;
    }
    void swapping(Node* head,int k) {
        int sz = getSize(head);
        Node* stHead = traversal(head, k);
        Node* endHead = traversal(head->next, (sz-k));

        cout << stHead->data << endl;
        cout << endHead->data << endl;
        cout << sz << endl;
        int temp = stHead->data;
        stHead->data = endHead->data;
        endHead->data = temp;
    }
};

int main()
{

    //7,9,6,6,7,8,3,0,9,5
    List ll;
    ll.push_back(7);
    ll.push_back(9);
    ll.push_back(6);
    ll.push_back(6);
    ll.push_back(7);
    ll.push_back(8);
    ll.push_back(3);
    ll.push_back(0);
    ll.push_back(9);
    ll.push_back(5);
    ll.swapping(ll.head, 5);
    ll.printList(ll.head);
    return 0;
}