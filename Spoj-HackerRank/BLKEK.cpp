// http://www.spoj.com/problems/BLKEK/
// http://www.geeksforgeeks.org/find-number-times-string-occurs-given-string/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 2000
#define pd(n) printf("%d\n",n)		/*printf for numbers*/
#define ps(n) printf("%s\n",n)		/*printf for char array and string*/
#define pc(n) printf("%c\n",n)		/*printf for chars*/

void BLKEK() {
	char k[4] = "KEK";
	int lengthSubstring = 3;
	char a[MAX];
	scanf("%s",&a[0]);

	int lengthMain = strlen(a);
	int lookup[lengthMain+1][lengthSubstring+1];
	int i=0,j=0;

	for (i = 0; i <= lengthSubstring; ++i)
	{
		lookup[0][i] = 0;
	}
	for (i = 0; i <= lengthMain; ++i)
	{
		lookup[i][0] = 1;
	}

	for (i = 1; i <= lengthMain; i++)
	{
		for (j = 1; j <= lengthSubstring; j++)
		{
			// If last characters are same, we have two 
            // options -
            // 1. consider last characters of both strings
            //    in solution
            // 2. ignore last character of main larger string
			if (a[i-1] == k[j-1])
			{
				lookup[i][j] = lookup[i-1][j-1] + lookup[i-1][j];
			}
			else{
				// If last character are different, ignore
                // last character of first string(main/larger)
				lookup[i][j] = lookup[i-1][j];
			}
		}
	}
	pd(lookup[lengthMain][lengthSubstring]);
}



int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--){
		BLKEK();
	}
	return 0;
}