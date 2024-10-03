#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    
    Node(){}
    Node(int data, Node* next = nullptr){
        this->data = data;
        this->next = next;
    }
};

Node* init(vector<int> &v)
{
    Node *head = NULL;
    if(v.size() == 0) return head;
    head = new Node(v[0]);
    Node *temp = head;
    for(int i = 1; i < v.size(); i++)
    {
        Node *n = new Node(v[i]);
        temp->next = n;
        temp = n;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}


Node* reverse(Node* head)
{
    if(head == NULL) return NULL;
    if(head->next == NULL) 
    {
        return head;
    }
    Node* curHead = reverse(head->next);
    head->next->next = head;
    return curHead;
}


int main()
{
    // vector<int> v;
    vector<int> v = {1,1,2,5,5,3};
    Node *head = init(v);

    Node* curHead = reverse(head);
    head->next = nullptr;
    head = curHead;

    print(head);
}   