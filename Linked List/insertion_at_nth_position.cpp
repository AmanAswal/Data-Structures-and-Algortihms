#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};


void Insert(Node** head, int data, int n){
    Node* temp1 = new Node();
    temp1 -> data= data;
    temp1 -> next = NULL;
    if( n==1){
        temp1-> next=*head;
        *head= temp1;
        return;
    }
    else
    {
        Node* temp2 = *head;
        for(int i=0; i< n-2; i++)
        {
            temp2 = temp2 -> next;
        }
        temp1 -> next = temp2-> next;
        temp2 -> next = temp1;    
    }
    
}

void Print(Node* head)
{
    Node* p = head;
    cout<<"List is: ";
    while( p!= NULL)
    {   
        cout<<p-> data<<" ";
        p = p -> next;
    }
    cout<<endl;
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    int x,n,size;
    cout<<"Enter the size of list: ";
    cin>>size;
    cout<<endl;
    for(int i=0; i< size; i++)
    {
        cout<<"Enter the data: ";
        cin>>x;
        cout<<"Enter the position: ";
        cin>>n;
        
        Insert(&head,x,n);
        Print(head);
    }    
    
    return 0;
}