#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
    int r=3, c=3;
    bool flag;
    for(int i=0; i<r; i++)
    {   
        int smallestInRow=0;
        for(int j=1; j<c; j++){
            if(arr[i][j] < arr[i][smallestInRow]){
                smallestInRow = j;
            }
        }

        flag = true;
        for(int k=0; k<r; k++){
            if(arr[k][smallestInRow] > arr[i][smallestInRow]){
                flag = false;
                break;
            }
        }

        if(flag){
            cout<<arr[i][smallestInRow]<<endl;
        }
    }
    if(flag==false){
        cout<<"No saddle point\n";
    }
    
    return 0;
}