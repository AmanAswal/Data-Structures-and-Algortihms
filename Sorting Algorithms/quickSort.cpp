#include<iostream>
using namespace std;

int Partition(int *arr, int start, int end){
    int pivot = arr[end];
    int partitionIndex = start;

    for(int i=start; i<end; i++){
        if(arr[i] <= pivot){
            swap(arr[i], arr[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(arr[pivot], arr[partitionIndex]);

    return partitionIndex;
}

void mergeSort(int *arr, int start, int end){
    if(start < end)
    {
        int partitionIndex = Partition(arr, start, end); // calling partition
        mergeSort(arr, 0, partitionIndex-1);
        mergeSort(arr, partitionIndex+1, end);
    }
}

int main()
{
    int arr[] = {7,6,5,4,3,2,1,0};
    mergeSort(arr, 0, 7);

    for(int i=0; i<8; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
