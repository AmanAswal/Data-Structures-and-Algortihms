#include<iostream>
using namespace std;

int occurance(int *arr, int x, int n, bool searchFirst) {
    int start = 0, end = n-1, result = -1;
    while (start <= end) {
        int mid = start + (end-start)/2;
        if (arr[mid] == x) {
            result = mid;
            if (searchFirst)
                end = mid - 1; // first occurance
            else
                start = mid + 1; // last occurance
        }
        else if (x < arr[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    return result;
}


int main()
{
    int arr[10] ={ 1, 2, 3, 3, 3, 3, 7, 7, 7, 10 };
    int x, size;
    cout<<"Enter the element: ";
    cin>>x;
    size = sizeof(arr)/sizeof(arr[0]);
    int first = occurance(arr, x, size, true);
    if (first == -1) {
        cout<<-1<<endl;
    }
    else {
        int last = occurance(arr, x, size, false);
        cout<<"First Occurance: "<<first<<endl<<"Last Occurance: "<<last<<endl;
    }

    return 0;
}
