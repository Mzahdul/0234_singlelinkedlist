#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    int noMhs;
    Node* next;
};

class SingleLinkedList 
{
    Node *START;

public:
    SingleLinkedList() 
    {
        START = NULL;
    }

    void addNode() 
    {
        int nim;
        cout << "masukan nomer mahasiswa : ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;

        if (START == NULL  || nim <= START->noMhs)
        {
            if (START != NULL && nim <= START->noMhs) 
            {
                cout << "\nDuplikasi noMhs tidak di ijinkan\n" << endl;
                return;
            }

            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }
            
        Node *previous = START;
        Node *current = START;

        while (current != NULL && nim >= current->noMhs) 
        {
            if (nim == current->noMhs) 
            {
                cout << "\nDuplikasi noMHS tidak di ijinkan\n" << endl;
                return;
            }
            previous = current;
            current = current->next;
        }

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }

    bool listEmpty() 
    {
        return START == NULL;
    }

    bool search(int nim, Node *&previous, Node *&current) 
    {
        previous = START;
        current = START;

        while (current != NULL && nim != current->noMhs) 
        {
            previous = current;
            current = current->next;
        }

        return current != NULL;
    }

};
