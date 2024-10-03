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

Node* insertHead(Node *head, int data)
{
    Node *newHead = new Node(data,head);
    return newHead;
}

Node* insertTail(Node* head, int data)
{
    Node *newNode = new Node(data);
    if(head == NULL) 
    {
        head = newNode;
        return head;
    }
    Node *temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

Node* insertKth(Node* head, int data, int k)
{
    if(k == 1)
    {
        head = insertHead(head,data);
        return head;
    }
    int cur = 0;
    Node *temp = head;
    while(temp != NULL)
    {
        cur++;
        if(cur == k-1)
        {
            Node *middleNode = new Node(data,temp->next);
            temp->next = middleNode;
            return head; 
        }
        temp = temp->next;
    }
    return head;
}

Node* insertElementMatched(Node* head,int data, int element)
{
    if(head == NULL) return head;
    if(head->data == element)
    {
        head = insertHead(head,data);
        return head;
    }

    Node *temp = head;
    while(temp->next != NULL)
    {
        if(temp->next->data == element)
        {
            Node* newNode = new Node(data,temp->next);
            temp->next = newNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

Node* deleteHead(Node *head)
{
    if(head == NULL || head->next == NULL) return NULL;
    Node *nextHead = head->next;
    delete head;
    return nextHead; 
}

Node* deleteTail(Node *head)
{
    if(head == NULL || head->next == NULL) return NULL;
    Node *temp = head;
    while(temp->next->next != NULL) temp = temp->next;
    Node *tail = temp->next;
    temp->next = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node* head,int k)
{
    if(k == 1)
    {
        head = deleteHead(head);
        return head;
    }
    int cur = 0;
    Node *temp = head;
    while(temp->next != NULL)
    {
        cur++;
        if(cur == k-1)
        {
            Node *deleteNode = temp->next;
            temp->next = temp->next->next;
            delete deleteNode;
            return head;
        }
        temp = temp->next;
    }
    return head;
}

void deleteDuplicates(Node* head)
{
    if(head == NULL) return;
    set<int> s;
    s.insert(head->data);
    while(head->next != NULL)
    {
        int nextVal = head->next->data;
        if(s.find(nextVal) != s.end())
        {
            Node* nextNode = head->next;
            head->next = nextNode->next;
            delete nextNode;
        }
        s.insert(nextVal);
        head = head->next;
    }
}


int main()
{
    // vector<int> v;
    vector<int> v = {1,1,2,5,5,3};
    Node *head = init(v);

    // head = insertHead(head,100);
    // head = insertTail(head,56);
    // head = insertTail(head,156);
    // head = insertKth(head,10,3);
    // head = insertElementMatched(head,10,3);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteKth(head,6);
    deleteDuplicates(head);
    print(head);
}   