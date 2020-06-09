#include<iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
// An optimized version of Bubble Sort 
void bubbleSort(int arr[], int n) 
{ 
   bool swapped; 
   for (int i = 0; i < n-1; i++) 
   { 
     swapped = false; 
     for (int j = 0; j < n-i-1; j++) 
     { 
        if (arr[j] > arr[j+1]) 
        { 
           swap(&arr[j], &arr[j+1]); 
           swapped = true; 
        } 
     } 
  
     // IF no two elements were swapped by inner loop, then break 
     if (swapped == false) 
        break; 
   } 
} 

int main(){
	int A[6] = {64, 25, 12, 22, 11, 1};

	bubbleSort(A,6);

	for(int i=0; i<6; i++){
		cout<<A[i]<<" ";
	}
	return 0;
}