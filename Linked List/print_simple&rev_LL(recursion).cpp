#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* Insert(Node** head,int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(*head == NULL){
        *head = temp;
        return *head;
    }
    Node* temp1 = *head;
    while(temp1->next != NULL){
        temp1 = temp1 -> next;
    }
    temp1 -> next = temp;
    return *head;
}

void Print(Node* head)
{
    if ( head == NULL){
        return;
    }
    cout<<head->data<<" ";
    Print(head->next); 
}

void reversePrint(Node* head)
{
    if ( head == NULL){
        return;
    }
    reversePrint(head->next);
    cout<<head->data<<" ";  
}


int main()
{
    Node* head = NULL;
    int x, size;
    cout<<"Enter the size of list: ";
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the element: ";
        cin>>x;
        Insert(&head,x);
    }
    cout<<"List is: ";
    Print(head);
    cout<<endl;
    cout<<"Reverese List is: ";
    reversePrint(head);    
    return 0;
}