// https://www.hackerrank.com/contests/projecteuler/challenges/euler010/problem
// similar to TDKPRIME problem of SPOJ
#include <cstdio>
#include <math.h>

using namespace std;


#define gc getchar_unlocked
inline void scanint(int &x){
	x=0;
	register int c=gc();
	int n=0;
	while(c<'0'||c>'9'){
		if (c=='-')
			n=1;
		c=gc();
	}
	for (; c>='0' && c<='9'; c=gc())
		x = (x<<1) + (x<<3) + (c-'0');
	if (n)
		x = -1 * x;
}

#define MAX_VALUE_PRIME 15485863+100
#define MAX_NO_PRIMES 1000000+10
int prime[MAX_NO_PRIMES];
char flag[(MAX_VALUE_PRIME/2) + 10];					/*considering only odd values*/
void seive(){
	int limit = sqrt(MAX_VALUE_PRIME) + 2;				/*3935*/
	flag[0]=1;prime[0]=2;
	int counter = 1;
	for (int i = 3; i <= limit; i += 2){	   /*skipping the even numbers with i+=2*/
		if (flag[i>>1] == 0)
		{
			prime[counter++] = i;
			for (int j = i*i ; j < MAX_VALUE_PRIME; j += (2*i))	/*skipping the even number with j = 2*i */
			{
				flag[j>>1] = 1;
			}
		}
	}
	for (int i = limit+2; counter < MAX_NO_PRIMES; i += 2)
	{
		if (flag[i>>1] == 0)
		{
			prime[counter++] = i;
		}
	}
}


void Prime(){
	int n;
	long long sum = 0;
	scanint(n);
	int i;
	for (i = 0; i < MAX_NO_PRIMES; i++)
	{
		if (prime[i] > n)
			break;
		sum+=prime[i];
	}
	printf("%lld\n", sum);
}

int main()
{
	seive();
	// for (int i = 0; i < MAX_NO_PRIMES; i++)
	// 	printf("%d\n",prime[i]);
	int cases;
	scanint(cases);
	while(cases--)
		Prime();
	return 0;
}