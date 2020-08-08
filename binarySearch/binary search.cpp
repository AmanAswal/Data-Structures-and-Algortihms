#include<iostream>
using namespace std;

int binarySearch(int *arr, int x, int size) {
    int start=0, end= size -1;

    while (start <= end)
    {
        int mid = start + (end - start)/2;
        if (x == arr[mid]) {
            return mid;
        }
        else if (x < arr[mid])
            end = mid-1;
        else
            start = mid+1;
    }
    return -1;
}


int main()
{
    int arr[10] ={ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Enter a number to be searched: ";
    cin>>n;
    cout<<"Element found at index "<<binarySearch(arr, n, size)<<endl;

    return 0;
}
