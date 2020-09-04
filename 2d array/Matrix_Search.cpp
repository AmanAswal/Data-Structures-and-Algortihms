#include<iostream>
using namespace std;

int main()
{
    int arr[4][4] = { {11,12,13,14}, {21,22,23,24}, {31,32,33,34}, {41,42,43,44} };
    int x;
    cout<<"Enter the number to be searched : ";
    cin>>x;
    int row = 4, column = 4;

    // similar to binary search

    int i=0, j = column-1;
    bool present = false;

    while(i<row && column>=0)
    {
        if(x == arr[i][j]){
            cout<<"Element is present at index (" << i << "," << j <<")"<<endl;
            present = true;
            break;
        }
        else if(x > arr[i][j]){
            i++;
        }
        else if(x < arr[i][j]){
            j--;
        }
    }

    if(present == false){
        cout<<"Element is not present."<<endl;
    }

    return 0;
}
