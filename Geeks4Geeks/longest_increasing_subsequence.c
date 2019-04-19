/*
 * =====================================================================================
 *
 *       Filename:  longest_increasing_subsequence.c
 *
 *    Description:  Link : https://practice.geeksforgeeks.org/problems/increasing-sub-sequence/0
 *
 *        Version:  1.0
 *        Created:  03/15/2019 01:18:29 AM
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

int longest_increasing_subsequence(char *A, int length){
	int i,j;
	int *lis = (int *)calloc(sizeof(int),length);

	for(i=0;i<length;i++){
		for(j=0;j<i;j++){
			if( (lis[i] < lis[j] + 1) && (A[j] < A[i]) ){
				lis[i] = lis[j] + 1;
			}
		}
		if(lis[i] == 0){
			lis[i] = 1;
		}
	}

	int max = lis[0];
	for(i=0;i<length;i++){
		if (lis[i] > max){
			max = lis[i];
		}
	}
	
	free(lis);

	return max;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--){
	    char *a = (char *)calloc(sizeof(char), 1000);
	    scanf("%s", a);
	    
		int length = strlen(a);
	    
		printf("%d\n", longest_increasing_subsequence(a, length));

		free(a);
	}
	return 0;
}


