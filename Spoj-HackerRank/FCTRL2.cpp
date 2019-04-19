// http://www.spoj.com/problems/FCTRL2/

// #include <bits/stdc++.h>
// #include <ios>
#include <iostream>
using namespace std;

#define MaxLength 500


int multiply(int x, int R[], int length){
	int carry = 0;
	
	for (int i = 0; i < length; i++){
		int product = (R[i] * x) + carry;
		R[i] = (int)product % 10;
		carry = (int)product/10;
	}

	while(carry){
		R[length] = carry%10;
		carry = carry/10;
		length++;
	}

	return length;
}

void FCTRL2(){
	int n;
	cin >> n;
	int R[MaxLength];
	R[0] = 1;
	int length = 1;

	for (int i = 2; i <= n; i++)
	{
		length = multiply(i,R,length);
	}

	for (int i = (length-1); i >= 0; i--)
	{
		cout << R[i];
	}

	cout << "\n";
}

int main() {
	// for fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;
	while(cases--)
		FCTRL2();
	return 0;
}