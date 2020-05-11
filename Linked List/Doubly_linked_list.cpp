#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
};

Node* head; // global variable - pointer to head node

// creates a new node and returns pointer to it
Node* getNewNode(int x){
    Node* newNode = new Node();
    newNode -> data=x;
    newNode -> prev=NULL;
    newNode -> next=NULL;
    return newNode;
}

// inserts node at head
void insertAtHead(int x)
{
    Node* newNode = getNewNode(x);
    if(head==NULL){
        head = newNode;
        return;
    }
    head->prev=newNode;
    newNode->next=head;
    head=newNode;
}

// inserts node at tail
void insertAtTail(int x)
{
    Node* newNode = getNewNode(x);
    if(head==NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// print in forward direction
void Print()
{
    Node* temp=head;
    cout<<"Forward: ";
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp-> next;
    }
    cout<<endl;
}

// print in reverse direction
void reversePrint()
{
    Node* temp= head;
    if(temp == NULL){
        return;
    }
    while(temp->next !=NULL){
        temp = temp->next;
    }

    cout<<"Reverse: ";
    while(temp !=NULL){
        cout<<temp->data<<" ";
        temp= temp->prev;
    }
    cout<<endl;
}

int main()
{
    head = NULL;
    insertAtHead(2); Print(); reversePrint();
    insertAtHead(4); Print(); reversePrint();
    insertAtHead(6); Print(); reversePrint();
    insertAtTail(8); Print(); reversePrint();
    insertAtTail(10); Print(); reversePrint();

    return 0;
}