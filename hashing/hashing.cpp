#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node
{
public:
    string key;
    int val;
    Node *next;

    Node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

class HashTable
{
    int totalSize;
    int currSize;
    Node **table;

    int hashfunction(string key)
    {
        int idx = 0;

        for (int i = 0; i < key.size(); i++)
        {
            idx = idx + (key[i] + key[i]) % totalSize;
        }

        return idx % totalSize;
    }

    void rehash()
    {
        Node **oldtable = table;
        int oldTotal = totalSize;

        totalSize = totalSize * 2;
        table = new Node *[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = NULL;
        }

        for (int i = 0; i < oldTotal; i++)
        {
            Node *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }

            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }

        delete[] oldtable;
    }

public:
    HashTable(int size = 5)
    {
        totalSize = size;
        currSize = 0;
        table = new Node *[totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key, int val)
    {
        int idx = hashfunction(key);

        Node *newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)totalSize;

        if (lambda > 1)
        {
            rehash();
        }
    }

    bool exists(string key)
    {
        int idx = hashfunction(key);
        Node *temp = table[idx];

        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    int search(string key)
    {
        int idx = hashfunction(key);
        Node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->next;
        }

        return -1;
    }
};

int main()
{

    HashTable ht;

    ht.insert("in", 150);
    ht.insert("ch", 150);
    ht.insert("np", 50);
    ht.insert("jp", 10);

    if(ht.exists("in")) {
        cout << "India" << "=" << ht.search("in") << endl;
    } else {
        cout << "doest exits";
    }

    return 0;
}