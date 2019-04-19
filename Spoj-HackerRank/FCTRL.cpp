// http://www.geeksforgeeks.org/given-p-and-n-find-the-largest-x-such-that-px-divides-n-2/
// http://www.spoj.com/problems/FCTRL/


#include <iostream>
using namespace std;


// We shall be calculating the power of 5 in the value of factorial of number, 
// and that many zeros shall be present in the final factorial value.
//  Formula used is Legendre's formula
int FCTRL(){
	int num;
	cin >> num;
	int value = 0;
	while(num){
		num /= 5;
		value += num;				
	}
	cout << value << endl;
}



int main() {
	int cases;
	cin >> cases;
	while(cases--)
		FCTRL();
	return 0;
}