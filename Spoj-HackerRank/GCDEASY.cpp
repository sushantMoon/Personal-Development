// http://www.spoj.com/problems/GCDEASY/
// https://en.wikipedia.org/wiki/Greatest_common_divisor
// http://www.geeksforgeeks.org/gcd-two-array-numbers/



// Incomplete Problem


#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
	if (b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}


int GCDEASY(){
	long long N, k;
	cin >> N >> k;
	long long a[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> a[i];
	}
	long long result = a[0];
	for (int i = 1; i < N; ++i)
	{
		result = gcd(result, a[i]);
	}
	cout << result*(long long)(k/result) << endl;
}

int main() {
	int cases;
	cin >> cases;
	while(cases--)
		GCDEASY();
	return 0;
}