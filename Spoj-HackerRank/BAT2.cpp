// http://www.spoj.com/problems/BAT2/
// http://www.spoj.com/problems/BAT3/
/*incomplete*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define pd(n) printf("%d\n",n)		/*printf for numbers*/
#define ps(n) printf("%s\n",n)		/*printf for char array and string*/
#define pc(n) printf("%c\n",n)		/*printf for chars*/


void BAT3(){
	int n=0,i=0,j=0;
	scanf("%d",&n);
	int a[n], lds[n], lis[n];  /*lds = longest decreasing subsequence*/
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++)
	{
		lds[i] = 1;
		lis[i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if ((a[i] > a[j]) && lds[j] < lds[i]+1)
			{
				lds[j] = lds[i] + 1;
			}
			else if ((a[i] < a[j]) && lis[j] < lis[i]+1)
			{
				lis[j] = lis[i] + 1;
			}
		}
	}
	int maxlds = lds[0];
	int maxlis = lis[0];
	for (i = 1; i < n; i++)
	{
		if (lds[i] > maxlds)
		{
			maxlds = lds[i];
		}
		if (lis[i] > maxlis)
		{
			maxlis = lis[i];
		}
	}
	pd(maxlds);pd(maxlis);
}


int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--){
		BAT3();
	}
	return 0;
}