/*
* =====================================================================================
*
*       Filename:  longest_common_subsequence.c
*
*    Description:  https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
*
*        Version:  1.0
*        Created:  03/15/2019 03:31:44 AM
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  Sushant Moon (), sushant.moon@gmail.com
*   Organization:  
*
* =====================================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(a,b) (a>b)?a:b


int longest_common_subsequence(char *A, char *B, int len_A, int len_B){
	int i, j;

	// defining M
	int **M = (int **)malloc(sizeof(int *)*(len_A+1));
	for(i = 0; i<=len_A; i++){
		M[i] = (int *)malloc(sizeof(int)*(len_B+1));
	}

	// filling up usgin recurrence
	for(i=0; i<=len_A; i++){
		for(j=0; j<=len_B; j++){
			if(i == 0 || j == 0){
				M[i][j] = 0;
			}
			else if(A[i-1] == B[j-1]){
				M[i][j] = M[i-1][j-1] + 1;
			}
			else{
				M[i][j] = max(M[i-1][j], M[i][j-1]);
			}
		}
	}

	int value = M[len_A][len_B];
	// free memory
	for(i = 0; i<=len_A; i++){
		free(M[i]);
	}
	free(M);
	return value;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
		int len_a, len_b;
		scanf("%d %d", &len_a, &len_b);

		char *a = (char *)calloc(sizeof(char), len_a);
		scanf("%s", a);

		char *b = (char *)calloc(sizeof(char), len_b);
		scanf("%s", b);

		printf("%d\n", longest_common_subsequence(a, b, len_a, len_b));

		free(a);
		free(b);
	}
	return 0;
}
