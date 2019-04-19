// http://www.spoj.com/problems/NWERC11A/
// http://archive.algo.is/icpc/nwerc/2011/nwerc2011-solutions.pdf
// http://www.javashuo.com/content/p-351065.html
// http://www.voidcn.com/article/p-fkeahcau-bkh.html
// http://www.ohrt.com/odds/binomial.php
// https://vjudge.net/contest/19294
// https://github.com/Grevor/NWERC/blob/master/Solutions/src/NWERC2011/BinomialCoefficients.java
// https://math.stackexchange.com/questions/1535614/find-n-and-k-if-binomn-k-1-2002-binomn-k-3003


// Incomplete Problem

/*
Hints
C(500,7) > 1e15
C(60, 30) > 1e15 
*/

#include <iostream>
using namespace std;
#define N 501 /* so that using index number is not affected by 0 starting of the array */
#define M 30  /* so that using index number is not affected by 0 starting of the array */
#define inf 1e15
long long c[N][M];


// Generaing the BC using the formula identify formula C(n,k) = C(n-1,k-1) + C(n-1,k)
void populateC()
{
	for (int k = 0; k < M; k++) 
		c[0][k] = 0;
	for (int l = 0; l < N; l++)
		c[l][0] = 1;
	c[1][1] = 1;
	for (int i = 2; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			if (j > i)
			{
				c[i][j] = 0;
				break;
			}
			else
			{
				if (c[i-1][j] == -1 || c[i-1][j-1] == -1)
				{
					c[i][j] = -1;
					break;
				}
				else
				{	
					long long sum = c[i-1][j-1] + c[i-1][j];
					if (sum <= inf)
					{
						c[i][j] = sum;
					}
					else{
						c[i][j] = -1;
						break;
					}
				}
			}
		}
	}
}

void printC()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
			cout << c[i][j] << " ";
		cout << "\n";
	}
}


int NWERC11A(){
	long long int value;
	cin >> value;
	int x[100000], y[100000];
	int count = 0;
	bool exit = false;

	if (value<30){
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 30; ++j){
				if (c[i][j] == 0){
					break;
				}
				else{
					if (c[i][j] == value){
						x[count] = i;
						y[count] = j;
						count += 1;
					}
				}
			}
		}
	}
	// else if (30 <= value <= 500){
	else{
		for (int i = 0; i < N; ++i)
		{
			int ihalf = 0;
			if ((i+1)%2 == 0)
			{
				ihalf = min(30, (i+1)/2);
			}
			else{
				ihalf = min(30, (i+2)/2);		
			}
			for (int j = 0; j < ihalf; ++j){
				if (c[i][j] == -1 || c[i][j] == 0 )
				{
					break;
				}
				else {
					if (c[i][j] == value){
						x[count] = i;
						y[count] = j;
						count += 1;
						if ((i+1)%2 == 0){
							int positionFromMid = ((i+1)/2) - (j+1);
							x[count] = i;
							y[count] = ((i+1)/2) + positionFromMid;
							count += 1;
						}
						else{
							int positionFromMid = ((i+2)/2) - (j+1);
							x[count] = i;
							y[count] = ((i+1)/2) + positionFromMid;
							count += 1;
						}
					}
				}
			}
		}
		
	}
	// else{
	// 	for (int i = 0; i < N; ++i)
	// 	{
	// 		for (int j = 0; j < M; ++j)
	// 		{
				
	// 		}
	// 		if (exit){
	// 			break;
	// 		}
	// 	}
	// }
	if (count == 0){
		count = 2;
		x[0] = value;
		x[1] = value;
		y[0] = 1;
		y[1] = value - 1;
	}

	cout << count << endl;
	for (int i = 0; i < count; ++i)
	{
		if(i){
			cout << " ";
		}
		cout << "(" << x[i] << "," << y[i] << ")"; 
	}
	cout << "\n";
	return 0;
}

int main() {
	populateC();
	// printC();
	int cases;
	string ans;
	cin >> cases;
	while(cases--)
		ans = NWERC11A();
	return 0;
}