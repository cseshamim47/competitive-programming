#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(){}
    Node(int data, Node *next = nullptr){
        this->data = data;
        this->next = next;
    }
};


void traverse(Node *head)
{
    Node *temp = head; // ei line tar ki dorkar ase?
    while(temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {5,10,1,4,66};
    // first way 
    Node x = Node(5);
    Node y = Node(6);
    x.next = &y;
    
    // another way
    Node *head = new Node(arr[0]);
    Node *mover = head;
    
    for(int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    traverse(head);

    
}