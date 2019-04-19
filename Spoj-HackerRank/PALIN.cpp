// http://www.spoj.com/problems/PALIN/
// http://www.geeksforgeeks.org/given-a-number-find-next-smallest-palindrome-larger-than-this-number/
/*
Three Cases 
1. All the numbers are 9
2. A non palindrome number (may contain a partial palindrome in middle)
	2.a With left side values greater than right
	2.b With left side values lower than right
3. Palindrome 
*/
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

// handles Case 1 : where all values are 9
bool checkIfAll9(int n[], int len){
	bool flag = true;
	for (int i = 0; i < len; ++i){
		if (n[i] != 9){
			flag = false;
			break;
		}
	}
	if (flag){
		cout << 1;
		for (int i = 0; i < (len-1); ++i){
			cout << 0;
		}
		cout << 1 << endl;
	}
	return flag;
}

int findNextPalindrome(int n[],int l){
	int i; /*left side*/
	int j; /*right side*/
	int type = l%2; /*0 for even 1 for odd*/

	// Case when single digit number is present which is less than 9
	if (l == 1)
	{
			n[0] += 1;
			cout << n[0] << endl;
			return 0;
	}
	if (type == 0){
		i = (l/2) -1;
		j = l/2;
	}
	else{
		i = (l/2) - 1;
		j = (l/2) + 1;
	}

	int change = 0;					/*checking for mid-palindrome/complete palindrome*/
	while(i - change >= 0){		/*breaks due to while loop if complete palindrome*/
		if (n[i - change] == n[j + change])
		{
			change += 1;
		}
		else
			break;		/*breaks here if mid palidrome, change will have the value where equality is not met*/
	}
	// Handles case 3 : where the number given is palindrome
	if (i - change < 0){
		// cout << "Input is a Palindrome : ";
		// for (int ite = 0; ite < l; ++ite)
		// 	cout << n[ite];
		int delta = 0;
		if (type == 0){			/*even no.of digits*/
			if (n[i-delta] != 9)		/*Checking middle terms for 9; note : there are two middle terms in case of even*/
			{
				n[i-delta] += 1;
				n[j+delta] += 1;
			}
			else
			{
				// loop for the case when the inner numbers of the palindrome are 9
				while ((n[i-delta] == 9) && (i - delta > 0)){
						n[i-delta] = 0;
						n[j+delta] = 0;
						delta += 1;
					}
				n[i-delta] += 1;
				n[j+delta] += 1;
			}
		}
		else{
			if (n[i+1] != 9)		/*Checking middle term for 9; note : just one middle term*/
			{
				n[i+1] += 1;
			}
			else{
				n[i+1] = 0;
				// loop for the case when the inner numbers of the palindrome are 9
				while ((n[i-delta] == 9) && (i - delta > 0)){
						n[i-delta] = 0;
						n[j+delta] = 0;
						delta += 1;
					}
				n[i-delta] += 1;
				n[j+delta] += 1;
			}
		}
		for (int ite = 0; ite < l; ++ite) /*printing results of case 3*/
			cout << n[ite];
		cout << "\n";
		return 0;
	}
	else{
		// Handles Case 2 , Also we shall be copying some part of Case 3 when we are handling palindrome in middle of non palindorm-ic number 
		int flag = 1;  /*for detecting if all the values on left side are greater than right side*/
		if (n[j+change] > n[i-change])
		{
			flag = 0;
		}
		if (flag == 1){
			for (int itr = change; itr < (l/2); ++itr)			/*Adjusting values when values in  left side are greater than right side*/ /*copying them from left to right side*/
			{
				n[j+itr] = n[i-itr];
			}
		}
		else
		{							/*Adjusting values when values in  left side are smaller than right side*/
			int k; /*left*/
			int m; /*right*/
			if (type == 0){
				k = (l/2) -1;
				m = l/2;
			}
			else{
				k = (l/2) - 1;
				m = (l/2) + 1;
			}
			int delta = 0;
			if (type == 0){
				if (n[k-delta] != 9)
				{	
					n[k-delta] += 1;
					n[m+delta] += 1;
				}
				else
				{
					// loop for the case when the inner numbers of the palindrome are 9
					while ((n[k-delta] == 9) && (k-delta > 0)){
						n[k-delta] = 0;
						n[m+delta] = 0;
						delta += 1;
					}
					n[k-delta] += 1;
					n[m+delta] += 1;
				}
			}
			else
			{
				if (n[k+1] != 9)
				{
					n[k+1] += 1;
				}
				else{
					n[k+1] = 0;
					// loop for the case when the inner numbers of the palindrome are 9
					while ((n[k-delta] == 9) && (k-delta > 0)){
						n[k-delta] = 0;
						n[m+delta] = 0;
						delta += 1;
					}
					n[k-delta] += 1;
					n[m+delta] += 1;
				}
			}
			for (int itr = change; itr < (l/2); ++itr)
			{
				n[j+itr] = n[i-itr];
			}
		}
		for (int ite = 0; ite < l; ++ite)			/*Printing outputs for Case 2 where there is a partial palindorme in middle of the given number */
			cout << n[ite];
		cout << "\n";
		return 0;
	}
	return 0;
}

int palin(){
	string num;
	cin >> num;
	int l = num.length();
	int n[l];
	char c[l];
	strcpy(c,num.c_str());
	for (int i = 0; i < l; ++i)
		n[i] = int(c[i]) - 48;
	// cout << "Number is : ";
	// for (int ite = 0; ite < l; ++ite)
	// 	cout << n[ite];
	// cout << "  Next Palindome is :";
	if (checkIfAll9(n,l))
		return 0;
	else
		findNextPalindrome(n,l);
	return 0;
}

int main() {
	int cases;
	cin >> cases;
	while(cases--)
		palin();
	return 0;
}