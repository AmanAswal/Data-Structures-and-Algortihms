#include<iostream>
using namespace std;

int main()
{
    int arr[4][4] = { {2,4,6,8}, {5,9,12,16}, {2,11,5,9}, {3,2,1,8} };
    int r=4, c=4;
    int top=0, bottom=r-1, left=0, right=c-1;
    int dir=0;

    while(top<=bottom && left<=right)
    {
        if(dir==0){
            for(int i=left; i<=right; i++){
                cout<<arr[top][i]<<" ";
            }
            top++;
        }
        else if(dir==1){
            for(int i=top; i<=bottom; i++){
                cout<<arr[i][right]<<" ";
            }
            right--;
        }
        else if(dir==2){
            for(int i=right; i>=left; i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        else if(dir==3){
            for(int i=bottom; i>=top; i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
        dir = (dir+1)%4;
    }  
    

    return 0;
}