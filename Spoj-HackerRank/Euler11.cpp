// https://www.hackerrank.com/contests/projecteuler/challenges/euler011/problem

#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;
void maxProdMatrix(){
	int i,j,k;
	int matrix[26][26];
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			if (i<3 || j<3){
					matrix[i][j]=1;
				}
			else if (3<=i && i<23 && 3<=j && j<23){
				int t;
				scanf("%d ",&t);
				matrix[i][j] = t;
			}
			else{
				matrix[i][j]=1;
			}	
		}
	}
	// for(i=0;i<26;i++){
		// for(j=0;j<26;j++){
			// printf("%d ",matrix[i][j]);
		// }
		// printf("\n");
	// }
	int maxProd = 0;
	for(i=3;i<23;i++){
	for(j=3;j<23;j++){
		int pH=1,pV=1,pR=1,pL=1;
		for(k=0;k<4;k++){
			pH *= matrix[i][j+k];
			pV *= matrix[i+k][j];
			pR *= matrix[i+k][j-k];
			pL *= matrix[i+k][j+k];
		}
		int maximum = max(max(pV,pH),max(pR,pL)); 
		if(maxProd < maximum)
			maxProd = maximum;
	}}
	printf("%d\n",maxProd);
	
}

int main() {
	int cases = 1;
	while(cases--)
		maxProdMatrix();
	return 0;
}