#include<iostream>
using namespace std;

int main()
{
    int r,c;
    cout<<"Enter the row length: ";
    cin>>r;
    cout<<"Enter the coloum length: ";
    cin>>c;

    int arr[r][c];

    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
        }
    }

    cout<<"Displaying the matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}