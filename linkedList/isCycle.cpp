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

    ~Node()
    {

        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List{
  

  public:
  Node* head;
  Node* tail;
  List() {
    head = NULL;
    tail = NULL;
  }

    ~List()
    {

        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }
     void push_front(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail = newNode;
        } else {
           newNode->next = head;
           head = newNode;
        }
    }

    void pop_front() {
        if(head == NULL) {
            cout << "Head is empty";
            return;
        }
        Node* temp = head;
        head = head->next;

         temp->next = NULL;
         delete temp;
    }

    bool isCycle(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) {
                cout << "cycle is existed";
                return true;
            }
        }
        return false;
    }

};

void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool iscycle = false;

    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cout << "cycle is exists";
            iscycle = true;
        }
    }

    if(!iscycle) {
        cout << "Cycle Doesn`t exists";
        return;
    }
   slow = head;
    if(slow == fast) {
       while(fast->next != head) {
         fast = fast->next;
       }

       fast->next = NULL;
    } else {
        Node* prev = fast;
        while(slow != fast) {
            slow = slow->next;
            prev = fast;
            fast = fast->next;
        }

        prev->next = NULL;
    }
}
int main() {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    ll.push_front(4);

    ll.tail->next = ll.head;
    cout << ll.isCycle(ll.head) << endl;
    
    return 0;
}