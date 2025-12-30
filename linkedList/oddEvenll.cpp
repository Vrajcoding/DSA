#include <bits/stdc++.h>
using namespace std;
// pending
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

    void evenOddList(Node* head) {
         List* even;
         List* odd;
         List* ans;
         Node* temp = head;

         while(temp) {
              if(temp->data % 2 == 0) {
                even->push_back(temp->data);
              } else {
                odd->push_back(temp->data);
              }
         }

          temp = even->head;
         while(temp) {
            ans->push_back(temp->data);
         }

         even->tail->next = odd->head;
         temp = odd->head;
         while(temp) {
            ans->push_back(temp->data);
         }

         ans->printList(ans->head);
    }
};

int main()
{

    //7,9,6,6,7,8,3,0,9,5
    List ll;
    ll.push_back(8);
    ll.push_back(12);
    ll.push_back(10);
    ll.push_back(5);
    ll.push_back(4);
    ll.push_back(1);
    ll.push_back(6);
    ll.printList(ll.head);
    ll.evenOddList(ll.head);
    ll.printList(ll.head);
    return 0;
}