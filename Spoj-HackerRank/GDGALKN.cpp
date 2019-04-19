// https://brilliant.org/wiki/guarding-a-museum/
// http://www.spoj.com/problems/GDGALKN/
// https://en.wikipedia.org/wiki/Art_gallery_problem
// http://www.geeksforgeeks.org/fast-io-for-competitive-programming/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int GDGALKN(){
	int n;
	cin >> n;
	cout << (int)(n/3) << "\n";
}

int main() {
	// for fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;
	while(cases--)
		GDGALKN();
	return 0;
}