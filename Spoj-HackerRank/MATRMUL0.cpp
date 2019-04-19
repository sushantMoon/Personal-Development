// http://www.spoj.com/problems/MATRMUL0/
// http://penguin.ewu.edu/~trolfe/MatMult/MatOpt.html
// https://stackoverflow.com/questions/13312625/cache-friendly-method-to-multiply-two-matrices
// http://discuss.spoj.com/t/needed-some-help-with-matrmul0-problem/24667

#include <iostream>
#include <stdint.h>
using namespace std;


int main() {
	uint32_t n, d1, p1, r1, m1, d2, p2, r2, m2;
	
	// Reading the Inputs
	cin >> n >> p1 >> d1 >> r1 >> m1 >> p2 >> d2 >> r2 >> m2;
	uint32_t A[n][n], B[n][n];
	uint64_t C[n][n], V[n];
	for (uint32_t i=0; i<n; ++i)
	{
		for (uint32_t j=0; j<n; ++j)
		{
				d1 = d1 * p1 + r1;
				d2 = d2 * p2 + r2;
				A[i][j] = d1 >> (32 - m1);
				B[i][j] = d2 >> (32 - m2);
				C[i][j] = 0;
		}
	}
	
	// For method 5
	// uint32_t A[(n*n)], B[(n*n)];
	// uint64_t C[(n*n)], V[n];
	
	// for (uint32_t i=0; i<n; ++i)
	// {
	// 	for (uint32_t j=0; j<n; ++j)
	// 	{
	// 			d1 = d1 * p1 + r1;
	// 			d2 = d2 * p2 + r2;
	// 			uint32_t index = (i*n) + j;
	// 			A[index] = d1 >> (32 - m1);
	// 			B[index] = d2 >> (32 - m2);
	// 	}
	// }

	// // Matrix Multiplication C = A * B
	// // (Not better than 1st, 2nd fastest) 5rd Method - Method 1 in singe dimensional array
	// for (uint32_t j = 0; j < n; ++j)
	// {
	// 	uint32_t Bj[n];					/*copying Jth column of B in an array for cache friendly calculations*/
	// 	for (uint32_t k=0; k<n; ++k)
	// 	{
	// 		uint32_t index = (k*n) + j;
	// 		Bj[k] = B[index];
	// 	}
	// 	for (uint32_t i = 0; i < n; ++i)
	// 	{
	// 		uint64_t s = uint64_t(0);
	// 		uint32_t index_2 = (i*n) + j;
	// 		for (uint32_t k=0; k<n; ++k)
	// 		{
	// 			uint32_t index_1 = (i*n) + k;
	// 			s += uint64_t(uint64_t(A[index_1]) * uint64_t(Bj[k]));
	// 		}
	// 		C[index_2] = s;
	// 	}
	// }

	// (Slower than 3rd, works best only with blocksize of 64 )4rd Method - Blocked Matix Multiplication 
	// uint32_t bsize = 64;
	// for (uint32_t jj = 0; jj < n; jj += bsize)
	//  {
	//  	for (uint32_t i = 0; i < n; i++)
	//  		for (uint32_t j = jj; j < min(jj+bsize,n); j++)
	//  			C[i][j] = 0;
	//  	for (uint32_t kk = 0; kk < n; kk += bsize)
	//  	{
	//  		for (uint32_t i = 0; i < n; i++)
	//  		{
	//  			for (uint32_t j = jj; j < min(jj+bsize,n); j++)
	//  			{
	//  				uint64_t sum = 0;
	//  				for (uint32_t k = kk; k < min(kk+bsize,n); k++)
	//  				{
	//  					sum += uint64_t(uint64_t(A[i][k]) * uint64_t(B[k][j]));
	//  				}
	//  				C[i][j] += sum;
	//  			}
	//  		}
	//  	}
	//  } 


	// // (Takes more time than the 1st and 2nd Method) 3rd Method - Reduction in Miss Rate and Improving memory access 
	// for (uint32_t k = 0; k < n; ++k)
	// {
	// 	for (uint32_t i = 0; i < n; ++i)
	// 	{
	// 		uint64_t s = A[i][k];
	// 		for (uint32_t j=0; j<n; ++j)
	// 			C[i][j] += uint64_t(uint64_t(s) * uint64_t(B[k][j]));
	// 	}
	// }

	// (Takes more time than the 1st Method) 2nd Method - Localisation of Columns of matrix B to increase cache using Transpose on the matrix, saving time on copying during multiplication
	// uint32_t Bt[n][n];
	// for (uint32_t i = 0; i < n; ++i)
	// 	for (uint32_t j = 0; j < n; ++j)
	// 		Bt[j][i] = B[i][j];
	// for (uint32_t j = 0; j < n; ++j)
	// {
	// 	for (uint32_t i = 0; i < n; ++i)
	// 	{
	// 		uint64_t s = uint64_t(0);
	// 		for (uint32_t k=0; k<n; ++k)
	// 			s += uint64_t(uint64_t(A[i][k]) * uint64_t(Bt[j][k]));
	// 		C[i][j] = s;
	// 	}
	// }
	
	// 1st Method - Localisation of Columns of matrix B to increase cache
	for (uint32_t j = 0; j < n; ++j)
	{
		uint32_t Bj[n];					/*copying Jth column of B in an array for cache friendly calculations*/
		for (uint32_t k=0; k<n; ++k)
			Bj[k] = B[k][j];
		for (uint32_t i = 0; i < n; ++i)
		{
			uint64_t s = uint64_t(0);
			for (uint32_t k=0; k<n; ++k)
				s += uint64_t(uint64_t(A[i][k]) * uint64_t(Bj[k]));
			C[i][j] = s;
		}
	}

	// Brute Force
	// for (uint32_t i = 0; i < n; ++i)
	// {
	// 	for (uint32_t j = 0; j < n; ++j)
	// 	{
	// 		C[i][j] = uint64_t(0);
	// 		for (uint32_t k = 0; k < n; ++k)
	// 		{
	// 			C[i][j] = uint64_t(C[i][j]) + (uint64_t(A[i][k]) * uint64_t(B[k][j]));
	// 		}
	// 	}
	// }

	for (uint32_t i=0; i<n; ++i) {
		V[i] = uint64_t(0);
		for (uint32_t j=0; j<n; ++j)
		{
			V[i] ^= uint64_t(C[i][j]);
		}
	}
	
	// For method 5
	// for (uint32_t i=0; i<n; ++i) {
	// 	V[i] = uint64_t(0);
	// 	for (uint32_t j=0; j<n; ++j)
	// 	{
	// 		uint32_t index = (i*n) + j;
	// 		V[i] ^= uint64_t(C[index]);
	// 	}
	// }

	//Output V[0], V[1], ..., V[n-1], separated by spaces.
	for (uint32_t i=0; i<n; ++i) {
		cout << V[i] << " ";
	}
	cout << "\n";
	return 0;
}