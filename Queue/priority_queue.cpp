#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void maxHeap(priority_queue<int> & pq){
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

void minHeap(priority_queue<int, vector<int>, greater<int> > & pq){
	while(!pq.empty()){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	cout<<endl;
}

int main()
{
	// max heap
	priority_queue<int> q;

	for(int elm: {1,8,5,6,3,4,0,9,7,2})
		q.push(elm);

	maxHeap(q);

	// min heap
	priority_queue<int, vector<int>, greater<int> > q2;
	for(int elm: {1,8,5,6,3,4,0,9,7,2})
		q2.push(elm);

	minHeap(q2);

	return 0;
}
