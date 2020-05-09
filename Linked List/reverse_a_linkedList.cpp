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
    cout<<"List is: ";
    while(head != NULL)
    { 
        cout<<head->data<<" ";
        head = head -> next;
    }
    cout<<endl;
    cout<<endl;
}

Node* Reverse(Node* head){
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while ( current != NULL)
    {
        next = current -> next;
        current-> next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main()
{
    Node* head = NULL;
    int x,n, size;
    cout<<"Enter the size of list: ";
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the element: ";
        cin>>x;
        Insert(&head,x);
        Print(head);
    }
    

    head = Reverse(head);
    cout<<"Reverse List: ";
    Print(head);
    
    return 0;
}