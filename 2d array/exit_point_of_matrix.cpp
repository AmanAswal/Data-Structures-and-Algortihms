#include<iostream>
using namespace std;

int main()
{
    int arr[3][3] = { {0,0,1}, {0,0,0}, {0,0,0} };
    int r=3, c=3;

    int i=0, j=0, dir=1;

    // we loop until we don't find the boundary
    while(i>=0 && j>=0 && i<r && j<c)
    {
        // if 1 is found, change the direction and resets the value to 0
        if(arr[i][j] == 1){
            arr[i][j]=0;
            switch(dir){
                case 1: dir=2; break;
                case 2: dir=3; break;
                case 3: dir=4; break;
                case 4: dir=1; break;
            }
        }
        // move along the direction
        switch(dir){
            case 1: j++; break;
            case 2: i++; break;
            case 3: j--; break;
            case 4: i--; break;
        }
    }
    // compensate the last move 
    switch(dir){
        case 1: j--; break;
        case 2: i--; break;
        case 3: j++; break;
        case 4: i++; break;
    }

    cout<<i<<" "<<j<<endl;

    return 0;
}