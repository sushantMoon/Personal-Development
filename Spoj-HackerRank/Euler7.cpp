/*
https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem
https://www.careercup.com/question?id=184860
http://www.spoj.com/problems/NPRIME/
*/

#include <iostream>
using namespace std;

// works good with Hacker rank
#define MAX 100000
#define FirstPrime 2

int prime[MAX];
int counter;

int NTHPRIME(){
	int n;
	cin >> n;
	int flag,j,value;
	if (counter >= n-1)
	{	
		cout << prime[(n-1)] << "\n";
		return 0;
	}
	else{
		value = prime[counter] + 1; 
		while (counter < n){
			flag = 0;
			for (j = 0; j <= counter; j++){
				if (value % prime[j] == 0){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				counter++;
				prime[counter] = value;
			}
			value++;

		}
		cout << prime[(n-1)] << "\n";
	}
	return 0;
}

int main() {
	// for fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// for precomputation, and saving computations from other test cases
	prime[0] = FirstPrime;
	counter = 0;

	int cases;
	cin >> cases;
	while(cases--)
		NTHPRIME();
	return 0;
}