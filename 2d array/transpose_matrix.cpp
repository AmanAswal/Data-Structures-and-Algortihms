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

    cout<<"Displaying the original matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    
    // code for tranpose
    for(int i=0; i<r; i++){
        for(int j=i; j<c; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }


    cout<<"Transpose matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    return 0;
}