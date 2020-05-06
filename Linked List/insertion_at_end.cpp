#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

// Node* head;

// insert function
void Insert(Node** head,int x)
{
    Node* temp = new Node();
    temp -> data = x;
    temp -> next = NULL;
    if(*head == NULL){
        *head = temp;
    }
    else
    {   
        Node* temp1 = *head;
        while(temp1->next!=NULL)
    {
        temp1 = temp1->next;
    }
    temp1 -> next = temp;
    }
    
}

void Print(Node* head)
{
    Node *temp1 = head;
    cout<<"List is: ";
    while(temp1 != NULL)
    {
        cout<< temp1-> data<<" ";
        temp1 = temp1-> next;
    }
    cout<<endl;
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    int n, x;
    cout<<"How many numbers?"<<endl;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter the number: ";
        cin>>x;
        Insert(&head,x);
        Print(head);
    }
    return 0;
}