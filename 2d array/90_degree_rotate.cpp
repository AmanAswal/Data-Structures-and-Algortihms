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
    
    // Here we are rotating the matrix 90 degree clockwise, so we have to 1. transpose and 2. reverse row wise
    // for 90 degree anti-clockwise, 1. transpose and 2. reverse column wise

    // step 1: tranpose
    for(int i=0; i<r; i++){
        for(int j=i; j<c; j++){
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // step 2: reverse row wise
    for(int i=0; i<r; i++){
        int left=0, right = c-1;
        while(left<right)
        {
            int temp = arr[i][left];
            arr[i][left] = arr[i][right];
            arr[i][right] = temp;
            
            left++;
            right--;
        }        
    }


    cout<<"Rotated matrix: "<<endl;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;


    return 0;
}