#include<iostream>
using namespace std;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
  
void insertionSort(int arr[], int n) 
{  
   int hole, value;
   for(int i=1; i<n; i++){
      value = arr[i];
      hole=i;
      while(hole>0 && arr[hole-1]>value){
         arr[hole] = arr[hole-1];
         hole=hole-1;
      }
      arr[hole] = value;
   } 
} 

int main(){
	int A[6] = {6, 25, 12, 22, 11, 1};

	insertionSort(A,6);

	for(int i=0; i<6; i++){
		cout<<A[i]<<" ";
	}
	return 0;
}