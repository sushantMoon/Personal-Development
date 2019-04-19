/*
http://www.spoj.com/problems/ANARC09A/
*/
#include <cstdio>

#define MAX 2001 
#define pd(n) printf("%d\n",n)		/*printf for numbers*/
#define ps(n) printf("%s\n",n)		/*printf for char array and string*/
#define pc(n) printf("%c\n",n)		/*printf for chars*/

int main() {
	int index=0;
	while(1){
		char s[MAX];
		int left = 0,i = 0,ans = 0;
		scanf("%s",&s[0]);
		if (s[0] == '-'){
			break;
		}
		index++;
		while(s[i]){
			if (s[i] == '{'){
				left++;
			}
			else{
				if (s[i] == '}' && left == 0)
				{
					left++;
					ans++;
				}
				else{
					left--;
				}
			}
			i++;
		}
		ans += left/2;
		printf("%d. %d\n",index,ans);
	}
	return 0;
}