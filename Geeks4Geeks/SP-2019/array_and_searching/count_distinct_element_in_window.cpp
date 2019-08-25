// https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/?track=sp-arrays-and-searching&batchId=152

#include <bits/stdc++.h>
using namespace std;
void countDistinct(int [], int , int );
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		countDistinct(a,k,n);cout<<endl;
	}
	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete below method */
void countDistinct(int A[], int k, int n)
{
    int *H = new(nothrow) int[101]{0};
    int unique_numbers = 0;
    for (int i = 0; i < k; i++){
        H[A[i]] += 1;
    }
    for (int i = 0; i < 101; i++){
        if (H[i] > 0)
            unique_numbers++;
    }
    cout << unique_numbers << " ";
    int outgoing_index = 0;
    int incoming_index = k;
    while (incoming_index < n){
        if (H[A[outgoing_index]] == 1){
            unique_numbers--;
        }
        H[A[outgoing_index]]--;
        outgoing_index++;

        if (H[A[incoming_index]] == 0){
            unique_numbers++;
        }
        H[A[incoming_index]]++;
        cout << unique_numbers << " ";
        incoming_index++;
    }
}