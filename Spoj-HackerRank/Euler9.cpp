// https://www.hackerrank.com/contests/projecteuler/challenges/euler009/problem

#include <cstdio>
#include <math.h>
using namespace std;


void Product(){
	int n;
	scanf("%d",&n);
	int a,b,c;
	int prod = -1;
	for (a = 1; a <= n/3; a++)
	{
		b = (pow(n,2)-(2*a*n))/(2*(n-a));
		c = n - a - b;
		if (pow(c,2) == pow(a,2) + pow(b,2)){
			int temp = a*b*c;
			if (temp > prod)
				prod = temp;
		}
	}
	printf("%d\n",prod);
}

int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--)
		Product();
	return 0;
}