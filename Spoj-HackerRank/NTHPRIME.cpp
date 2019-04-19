/*
https://www.hackerrank.com/contests/projecteuler/challenges/euler007/problem
https://www.careercup.com/question?id=184860
http://www.spoj.com/problems/NTHPRIME/
https://primes.utm.edu/nthprime/index.php#nth
*/


// The 1,000,000,000th prime is 22,801,763,489.
// incomplete / timing out 

#include <iostream>
#include <math.h>
using namespace std;
# define MAX 500000000
long long prime[MAX];

#define FirstPrime 2

int NTHPRIME(){
	int n;
	cin >> n;
	int flag,j;
	int counter = 0;
	prime[0] = FirstPrime;
	int value = prime[0];
	while (counter <= n-1){
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
	cout << prime[n-1] << "\n";
	
	return 0;
}

int primeApprox(int n){
	// int n;
	// cin >> n;
	double eq = log(n) + log(log(n));
	double lower = (eq - 1) * n;
	double upper = eq * n;
	cout << "lower : " << lower << " upper : " << upper << endl; 
	double p = n;
	p *= log(n) + log(log(n)) - 1 + ((log(log(n)) - 2)/log(n)) - ((pow((log(log(n))),2) - 6*(log(log(n))) + 11)/(2*pow((log(n)),2))) + (1/(pow(log(n),2)));
	cout << "approx prime : " << p << endl;
}

int main() {
	// for fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// primeApprox(1000000000);
	// primeApprox(1000000001);
	NTHPRIME();
	return 0;
}