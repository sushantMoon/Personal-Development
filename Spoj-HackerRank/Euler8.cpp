// https://www.hackerrank.com/contests/projecteuler/challenges/euler008/problem

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void MaxProduct(){
	int n,k,i;
	int currentProd, maxProd;
	scanf("%d %d",&n,&k);
	// printf("%d %d\n", n,k);
	int num[n],buffer[k];
	char c[n];
	scanf("%s",c);
	for (i = 0; i < n; i++)
	{
		num[i] = ((int)c[i]) - '0';
		if(i<k)
		{
			buffer[i] = num[i];
			if (i==0)
			{
				currentProd = buffer[0];
			}
			else{
				currentProd *= buffer[i];
			}
		}
	}
	maxProd = currentProd;
	int bufferend = k-1;
	while(bufferend < n-1){
		int pointer = bufferend + 1;
		int pointerValue = num[pointer];
		if (buffer[(pointer%k)] != 0){
			currentProd = (currentProd/buffer[(pointer%k)])*pointerValue;
			buffer[(pointer%k)] = pointerValue;
		}
		else{
			buffer[(pointer%k)] = pointerValue;
			currentProd = buffer[0];
			for (i = 1; i < k; i++)
			{
				currentProd *= buffer[i];
			}
		}
		if (currentProd > maxProd){
			maxProd = currentProd;
		}
		bufferend+=1;
	}
	printf("%d\n", maxProd);
}



int main() {
	int cases;
	scanf("%d",&cases);
	// printf("%d\n", cases);
	while(cases--)
		MaxProduct();
	return 0;
}