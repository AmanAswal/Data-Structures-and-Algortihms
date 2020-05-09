#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

Node* head;

void Insert(int x)
{
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head == NULL){
        head = temp;
        return;
    }
    Node* temp1 = head;
    while(temp1->next != NULL){
        temp1 = temp1 -> next;
    }
    temp1 -> next = temp;
    
}

void Print()
{
    Node* temp2 = head;
    cout<<"List is: ";
    while(temp2 != NULL)
    { 
        cout<<temp2->data<<" ";
        temp2 = temp2 -> next;
    }
    cout<<endl;
    cout<<endl;
}

void Delete(int n,int size)
{   
    if (n == 0 || n>size){
        cout<<"Invalid position."<<endl;;
        return;
    }
    Node* temp1 = head;
    if(n==1)
    {
        head= temp1 -> next;
        delete(temp1);
    }
    else
    {
        for (int i=0; i<n-2;i++)
        {
        temp1 = temp1 -> next;
        }
        Node* temp2 = temp1 -> next;
        temp1-> next = temp2 -> next;
        delete(temp2);
    }
    
    
}

int main()
{
    head = NULL;
    int x, n, size;
    cout<<"Enter the size: ";
    cin>>size;
    for(int i=0; i<size; i++)
    {
        cout<<"Enter the elements: "<<endl;
        cin>>x;
        Insert(x);
        Print();
    }
    cout<<"Enter a position to delete: ";
    cin>>n;
    cout<<endl;
    Delete(n,size);
    Print();
    
    return 0;
}