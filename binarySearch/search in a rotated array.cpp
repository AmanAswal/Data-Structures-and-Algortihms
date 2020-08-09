#include<iostream>
using namespace std;

int binarySearch(int *arr, int start, int end, int size, int x) {

	while (start <= end)
	{
		int mid = start + (end-start);

		if (x == arr[mid])
			return mid;

		else if (x<arr[mid])
			end = mid-1;

		else
			start = mid+1;
	}
	return -1;
}

int findRotateCount(int *arr, int size) {
	int start=0, end=size-1;

	while (start <= end)
	{
		int mid = start + (end-start)/2;

		//case 1: 
		if (arr[start] <= arr[end]) {
			return start;
		}

		// calculate next and prev
		int next = (mid+1)%size;
		int prev = (mid-1+size)%size;

		//case 2:
		if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
			return mid;

		//case 3:
		if (arr[mid] <= arr[end])
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main()
{
	int arr[] ={ 11, 12, 15, 18, 2, 5, 6, 8 };
	int size = sizeof(arr)/sizeof(arr[0]);

	int index = findRotateCount(arr, size);

	int x;
	cout<<"Enter the number to search: ";
	cin>>x;

	int left = binarySearch(arr, 0, index-1, size, x);
	int right = binarySearch(arr, index, size-1, size, x);

	cout<<"Element found at index: ";
	if (left < 0)
		cout<<right;
	else
		cout<<left;
	cout<<endl;
	return 0;
}
