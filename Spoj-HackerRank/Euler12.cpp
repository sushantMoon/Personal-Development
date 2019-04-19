// https://www.hackerrank.com/contests/projecteuler/challenges/euler012/problem
// http://webcache.googleusercontent.com/search?q=cache:n3BfWAlLF1IJ:primes.utm.edu/glossary/xpage/tau.html+&cd=12&hl=en&ct=clnk&gl=in
// http://xoptutorials.com/index.php/2017/01/01/hackerrank86-2/


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

/*This Prime Number calculating Seive is the best*/
#define P 1000000	 			/*number of primes calculated in precumputation*/
#define MaxPrimeValue 15485863 	/*1000000th prime*/
int prime[P];
int flag[MaxPrimeValue/2];
void primeSeive(){
	int limit = sqrt(MaxPrimeValue);		/*limit is about 3935*/
	prime[0] = 2;
	flag[0] = 1;
	int index = 1;
	for (int i = 3; i <= limit; i+=2)
	{
		if (flag[i/2] == 0)
		{
			prime[index] = i;
			index++;
			for (int j = i*i; j <= MaxPrimeValue ; j +=  (2*i))
			{
				flag[j/2] = 1;
			}
		}
	}
	for (int i = limit+2; index <= P; i+=2)
	{
		if (flag[i/2] == 0)
		{
			prime[index] = i;
			index++;
		}
	}
}

#define DivisorIndex 1000+5		/*index for the first number which satisfies the Triangular number Property and that many divisors as governed by this index*/
int TriangularIndex[DivisorIndex];

/*
here logic used for finding the number of divisoe is mentioned in 
http://webcache.googleusercontent.com/search?q=cache:n3BfWAlLF1IJ:primes.utm.edu/glossary/xpage/tau.html+&cd=12&hl=en&ct=clnk&gl=in
google search for number of divisors for a number will give u the formula
*/
void TriangularNumberGen(){
	TriangularIndex[0] = 0;
	TriangularIndex[1] = 3;
	// TriangularIndex[2] = 6;
	// TriangularIndex[3] = 6;

	int i = 2;
	int index = 3;
	while(i<DivisorIndex){
		int value = (index*(index+1))/2;
		int limit = value/2;
		int divisors = 1;
		for (int j = 0; prime[j] <= limit; j++)
		{
				int y = 0;
				while(value%prime[j] == 0){
					value /= prime[j];
					y++;
					if (value == 1)
						break;
				}
				if(y!=0){
					divisors *= (y+1);
				}
				if (value == 1)
					break;
		}
		while(divisors > i){
			// printf("%d : %d : %d\n", i, divisors, (index*(index+1))/2 );
			TriangularIndex[i] = (index*(index+1))/2;
			i++;
		}
		index++;
	}
}

void TriangularDeindex(){
	int number;
	scanint(number);
	printf("%d\n", TriangularIndex[number]);
}

int main() {
	primeSeive();
	TriangularNumberGen();
	// for (int i = 0; i < P; ++i)
	// {
	// 	printf("%d\n",TriangularIndex[i] );
	// }
	int cases;
	scanint(cases);
	while(cases--)
		TriangularDeindex();
	return 0;
}