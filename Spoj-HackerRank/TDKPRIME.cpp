/*
http://www.spoj.com/problems/TDKPRIME/
https://ideone.com/zTd2Qz
http://abhisharlives.blogspot.in/2012/06/really-fast-io-methods-for-programming.html
The 5,000,000th prime is 86,028,121
*/
#include <cstdio>
#include <math.h>
#define MAX_VALUE_PRIME 86028121+100
#define MAX_NO_PRIMES 5000000+10
using namespace std;

int prime[MAX_NO_PRIMES];


#define gc getchar_unlocked
inline void scanint(int &x){
	x = 0;
	register int c = gc();
	int n = 0;
	while(c < '0' || c > '9'){
		(c=='-')?n=1:n=0;
		c=gc();
	}
	for (; c>='0'&&c<='9';c=gc())
		x = x*10 + c-48;   /* x*2  + x*8 = x*(2+8) = x*10   */
	(n)?x=-1*x:x;
}


// Slower Linear method
// #define LIMIT (MAX_VALUE_PRIME/2 +1)
// int flag[LIMIT]; /*this represents array of flags for odds integers; ignoring evens by default*/
// void sieve(){
// 	int i=0,j=0,k=0;
// 	prime[0]=2;flag[0]=1;
// 	for (j = 1; j < LIMIT; j++)
// 	{
// 		i = (j<<1) + 1;
// 		k = i*3;
// 		while(k<MAX_VALUE_PRIME){
// 			flag[(k>>1)] = 1;
// 			k += (i<<1);
// 		}
// 	}
// 	i = 1;
// 	for (j = 0; j < LIMIT; j++)
// 	{
// 		// if prime flag would be '0'
// 		if (!flag[j]){
// 			prime[i]= (j<<1) + 1;
// 			i++; 
// 			// printf("%d\n", prime[i]);
// 		}
// 	}
// }

// Faster Optimised method
char flag[MAX_VALUE_PRIME/2]; /*this represents array of flags for odds integers; ignoring evens by default*/
void sieve(){
	int LIMIT = sqrt(MAX_VALUE_PRIME) + 2;   /*9275*/
	int i=0,j=0,k=0; /*counters for iteration*/
	prime[0]=0;prime[1]=2;flag[0]=1;             /*flag[0]=1,flag[1]=3,flag[2]=5*/
	int c=2; /*counter for primes*/

	for (j = 3; j <= LIMIT; j+=2)   ///*incremented j by 2 cause we aare looking for only odd values starting from 3*/
	{
		if (flag[(j>>1)] == 0)
		{
			prime[c] = j;
			c++;
			for (i = j*j; i <= MAX_VALUE_PRIME; i += (2*j)) 
			{
				flag[(i>>1)] = 1;
			}
		}
	}
	// We have already stored the primes upto sqrt(MAX_VALUE_PRIME)
	// hence copying the remaining
	for (j = LIMIT+2; c <= MAX_NO_PRIMES; j+=2)
	{
		// if prime, flag would be 0
		if (flag[(j>>1)] == 0){
			prime[c]= j;
			// printf("%d\n",prime[c]);
			c++;
		}
	}
}

int TDKPRIME(){
	int n;
	// scanf("%d",&n);
	scanint(n);
	printf("%d\n", prime[n]);
}

int main() {
	sieve();
	int cases;
	// scanf("%d",&cases);
	scanint(cases);
	while(cases--)
		TDKPRIME();
	return 0;
}