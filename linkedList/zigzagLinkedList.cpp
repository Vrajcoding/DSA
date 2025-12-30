#include<bits/stdc++.h>
using namespace std;

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

    void printList()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }   

    Node* spilteAtMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev) {
            prev->next = NULL;
        }

        return slow;
    }

   Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr) {
        Node* next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    return prev;
   }
    Node* zigZag(Node* head) {

        Node* rightHead = spilteAtMid(head);
        Node* rightRevHead = reverse(rightHead);

        Node* left = head;
        Node* right = rightRevHead;
        Node* tail = right;

        while(left && right) {
            Node* nextLeft = left->next;
            Node* nextRight = right->next;
            
            left->next = right;
            right->next = nextLeft;

            tail = right;

            left = nextLeft;
            right = nextRight;
        }

        if(right) {
            tail->next = right;
        }

        return head;
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
   ll.printList();
   ll.head = ll.zigZag(ll.head);
   ll.printList();
    return 0;
}