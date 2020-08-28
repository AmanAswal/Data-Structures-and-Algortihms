#include<iostream>
#include<algorithm>
using namespace std;

class Activity{
    public:
    int start;
    int finish;
};

// A utility function that is used for sorting activities according to finish time
bool activityCompare(Activity s1, Activity s2){
    return (s1.finish < s2.finish);    
}

void printMaxActivities(Activity arr[], int n){

    // step-1 : sort the array according to the finish time
    sort(arr, arr+n, activityCompare);

    // step-2 : Always select(print) the first activity
    int i = 0;
    cout<< "(" << arr[i].start << ", " << arr[i].finish << "), ";

    // step-3 : consider rest of the activities

    for(int j=1; j<n; j++){
        // if activity has start time >= finish time of previous activity then select it and print.
        if(arr[j].start >= arr[i].finish){
            cout<< "(" << arr[j].start << ", " << arr[j].finish << "), ";
            i = j;
        }
    }
}

// driver program
int main()
{
    Activity arr[] = { {5,9}, {1,2}, {3,4}, {0,6}, {5,7}, {8,9} };
    int n = sizeof(arr)/sizeof(arr[0]);
    printMaxActivities(arr, n);
    return 0;
}
