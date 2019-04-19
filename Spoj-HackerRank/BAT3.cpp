// http://www.spoj.com/problems/BAT3/
// http://spoj-sus.blogspot.in/2015/09/bat3.html
// http://www.geeksforgeeks.org/longest-increasing-subsequence/


#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define pd(n) printf("%d\n",n)		/*printf for numbers*/
#define ps(n) printf("%s\n",n)		/*printf for char array and string*/
#define pc(n) printf("%c\n",n)		/*printf for chars*/


void BAT3(){
	int n=0,m=0,i=0,j=0;
	scanf("%d %d",&n,&m);
	int a[n], lds[n];  /*lds = longest decreasing subsequence*/
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		lds[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if ((a[i] > a[j] | i == m) && lds[j] < lds[i]+1)
			{
				lds[j] = lds[i] + 1;
			}
		}
	}
	int max = lds[0];
	for (i = 1; i < n; i++)
	{
		if (lds[i] > max)
		{
			max = lds[i];
		}
	}
	pd(max);
}


int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--){
		BAT3();
	}
	return 0;
}