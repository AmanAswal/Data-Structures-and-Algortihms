#include<iostream>
using namespace std;

int search(int *arr, int n, int x)
{
    int result=-1;
    int start = 0, end = n-1;
    while (start <= end)
    {
        int mid = start + (end-start)/2;

        if (x == arr[mid])
            return arr[mid];

        else if (x < arr[mid]) {
            end = mid-1;
        }
        else {
            result = arr[mid];
            start = mid+1;
        }
    }
    return result;

}

int main()
{
    int arr[] ={ 1, 2, 3, 4, 8, 9, 10 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int x;
    cout<<"Enter a number whose floor value you want: ";
    cin>>x;

    int index = search(arr, n, x);
    cout<<"Floor element is: "<<index<<endl;
    return 0;
}
