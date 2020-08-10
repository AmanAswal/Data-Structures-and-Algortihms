#include<iostream>
using namespace std;

int search(int *arr, int n, int x)
{
    int start = 0, end = n-1;
    while (start <= end)
    {
        int mid = start + (end-start)/2;

        if (x == arr[mid])
            return mid;

        else if (mid-1 >= start && arr[mid-1] == x)
            return mid-1;

        else if (mid+1 <= end && arr[mid+1] == x)
            return mid+1;

        else if (x > arr[mid])
            start = mid+1;

        else
            end = mid -1;
    }
    return -1;

}

int main()
{
    int arr[] ={ 5, 10, 30, 20, 40 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter a number to search: ";
    cin>>x;

    int index = search(arr, n, x);
    cout<<"Element found at index "<<index<<endl;
    return 0;
}
