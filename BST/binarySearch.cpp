#include<iostream>
 using namespace std;

int binarySearch(int *arr, int n, int key){
	int start=0, end=n-1, mid  =(start+end)/2;
	while(start<=end && arr[mid] != key){
		if(key < arr[mid])
			end = mid-1;
		else
			start= mid+1;
		
		mid=(start+end)/2;
	}
	if(start > end)
		return -1; // key not found
	return mid;
}

int main()
 {
 	int arr[10], key;
 	cout<<"Enter the elements of array: ";
 	for(int i=0; i<10; i++)
 	{
 		cin>>arr[i];
 	}
 	
 	cout<<"Enter the key: ";
 	cin>>key;

 	int result = binarySearch(arr, 10, key);

 	// output

 	if(result == -1){
 		cout<<"Key not found";
 	} 
 	else{
 		cout<<"Key found at index "<<result;
 	}

 	return 0;
 }