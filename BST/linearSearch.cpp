#include<iostream>
 using namespace std;

int linearSearch(int *arr, int n, int key){
	for(int i=0; i<n; i++){
		if(arr[i]==key){
			return i;
		}
	}
	return -1;
}


 int main()
 {
 	int arr[5], key;
 	cout<<"Enter the elements of array: ";
 	for(int i=0; i<5; i++)
 	{
 		cin>>arr[i];
 	}
 	
 	cout<<"Enter the key: ";
 	cin>>key;

 	int result = linearSearch(arr, 5, key);

 	// output

 	if(result == -1){
 		cout<<"Key not found";
 	} 
 	else{
 		cout<<"Key found at index "<<result;
 	}

 	return 0;
 }