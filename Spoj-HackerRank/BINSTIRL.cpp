// https://en.wikipedia.org/wiki/Stirling_numbers_of_the_second_kind
// https://en.wikipedia.org/wiki/Sierpinski_triangle
// https://en.wikipedia.org/wiki/Iverson_bracket
// http://www.spoj.com/problems/BINSTIRL/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int BINSTIRL(){
	int n,m;
	cin >> n >> m;
	if (((n-m) & (int)((m-1)/2)) == 0)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}

int main() {
	// for fast I/O
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int cases;
	cin >> cases;
	while(cases--)
		BINSTIRL();
	return 0;
}