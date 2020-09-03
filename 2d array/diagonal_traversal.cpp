#include<iostream>
using namespace std;

int main()
{
    int arr[4][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16} };

    for(int g=0; g<4; g++){
        for(int i=0, j = g; j<4; i++, j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}