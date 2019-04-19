/*
 * =====================================================================================
 *
 *       Filename:  coin-change.cpp
 *
 *    Description: https://practice.geeksforgeeks.org/problems/coin-change/0/ 
 *
 *        Version:  1.0
 *        Created:  03/22/2019 03:26:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sushant Moon (), sushant.moon@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int main(){
	int t,m,n;
	cin >> t;
	while(t--){
		cin >> m;
		int V[m];
		for(int i=0;i<m;i++){
			cin >> V[i];
		}
		cin >> n;
		int S[m][n+1];
		for(int i=0;i<m;i++){
			for(int j=0;j<n+1;j++){
				int with_m,without_m;
				if (j==0){
					S[i][j] = 1;
				}
				else{
					if(i>0){
						without_m = S[i-1][j];
					}
					else{
						without_m=0;
					}
	
					if(j-V[i] >= 0){
						with_m = S[i][j-V[i]];
					}
					else{
						with_m=0;			
					}
	
					S[i][j] = with_m + without_m;
				}
			}
		}
		cout << S[m-1][n] << endl;
	}
}
