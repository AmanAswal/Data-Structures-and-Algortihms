#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* top = NULL;

void Push(int x)
{
    Node* temp = new Node();
    temp-> data= x;
    temp-> next= top;
    top = temp;
}

void Pop()
{
    Node* temp;
    if(top==NULL)
    {
        return;
    }
    temp = top;
    top = temp-> next;
    delete (temp);
}

int main()
{
    Push(2);
    Push(4);
    Pop();
    Push(3);
    return 0;
}