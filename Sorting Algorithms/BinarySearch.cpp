#include<iostream>
using namespace std;

int binarySearch(int *arr, int n, int x){
    int start=0, end=n-1;

    while(start <= end)
    {
        int mid = start+(end-start)/2;

        if(arr[mid] == x){
            return mid;
        }
        else if(x < arr[mid]){
            end = mid-1;
        }
        else if(x > arr[mid]){
            start = mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    int n=10;
    int x=4;
    cout<<"Element found at "<<binarySearch(a, n, x)<<" index.";
    return 0;
}
