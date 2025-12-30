#include<bits/stdc++.h>
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

    void printList(Node* head)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }   

    Node* travarSal(Node* head,int m) {
          Node* curr = head;
          Node* prev = NULL;
          for(int i = 0;i < m;i++) {
             prev = curr;
             curr = curr->next;
          }

       return prev;
    }

    void removeNNode(int m,int n) {
        Node* stprev = travarSal(head, m);
        Node* endprev = travarSal(stprev->next, n);
        stprev->next = endprev->next;
        endprev->next = NULL;
    }
};

int main()
{
    List ll;
     ll.push_back(1);
      ll.push_back(2);
       ll.push_back(3);
      ll.push_back(4);
   ll.push_back(5);
   ll.push_back(6);
   ll.push_back(7);
   ll.push_back(8);
   ll.printList(ll.head);
   ll.removeNNode(3,2);
   ll.printList(ll.head);
    return 0;
}