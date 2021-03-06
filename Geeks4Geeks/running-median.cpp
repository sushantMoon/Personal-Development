/*
 * =====================================================================================
 *
 *       Filename:  running-median.cpp
 *
 *    Description:  https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
 *
 *        Version:  1.0
 *        Created:  03/21/2019 02:58:11 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sushant Moon (), sushant.moon@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct comparatorMinHeap{
	bool operator()(int i, int j){
		return i > j;
	}
};

struct comparatorMaxHeap{
	bool operator()(int i, int j){
		return i<j;
	}
};

int main(){
	priority_queue<int, vector<int>, comparatorMinHeap> minHeap; // after median
	priority_queue<int, vector<int>, comparatorMaxHeap>  maxHeap; // before median
	
	int t, data,median=0;
	cin >> t;
	while(t--){
		cin >> data;
		if (minHeap.size() == 0 || data > minHeap.top()){
			minHeap.push(data);
		}
		else{
			maxHeap.push(data);
		}
		
		if(maxHeap.size() > minHeap.size()+1){
			minHeap.push(maxHeap.top());
			maxHeap.pop();
		}
		else if (minHeap.size() > maxHeap.size()+1){
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}

		if(maxHeap.size() == minHeap.size()){
			cout << (maxHeap.top() + minHeap.top())/2 << endl;
		}
		else if(maxHeap.size() > minHeap.size()){
			cout << maxHeap.top() << endl;
		}
		else{
			cout << minHeap.top() << endl;
		}
	}
	// cout << "\nmax heap\n";
	// while(maxHeap.size()> 0){
	// 	cout << maxHeap.top() << " ";
	// 	maxHeap.pop();
	// }
	// cout << "\nmin heap\n";
	// while(minHeap.size()> 0){
	// 	cout << minHeap.top() << " ";
	// 	minHeap.pop();
	// }
	return 0;
}


