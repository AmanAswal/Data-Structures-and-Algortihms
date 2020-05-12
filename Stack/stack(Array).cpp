#include<iostream>
using namespace std;

#define MAX_SIZE 101

class Stack{
private:
    int A[MAX_SIZE];
    int top;
public:
    Stack()
    {
        top = -1;
    }

    void Push(int x)
    {
        if(top == MAX_SIZE-1)
        {
            cout<<"Error: Stack overflow"<<endl;
            return;
        }
        A[++top] = x;
    }

    void Pop()
    {
        if(top == -1)
        {
            cout<<"Error: No element to return"<<endl;
            return;
        }
        top --;
    }

    int Top()
    {
        // cout<<"Top element: "<<A[top];
        return A[top];
    }

    int isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    // not a operation of Stack
    void Print()
    {
        cout<<"Stack: ";
        for(int i=0; i<=top; i++)
        {
            cout<<A[i]<<" ";
        }
        cout<<endl;
    }

};



int main()
{
    Stack S;
    S.Push(2); S.Print();
    S.Push(5); S.Print();
    S.Push(10); S.Print();
    S.Pop(); S.Print();
    S.Push(12); S.Print();
    S.Top(); 

    return 0;
}
