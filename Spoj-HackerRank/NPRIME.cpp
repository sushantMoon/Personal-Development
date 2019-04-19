#include <cstdio>
#define L 1299800
int p[L],a[L];
int main() {
	int n,j,k;a[0]=a[1]=1;
	for(j=2;j<L;j++){k=j+j;while(k<L){a[k]=1;k+=j;}}k=0;
	for(j=2;j<L;j++){(!a[j])?p[k++]=j:0;}
	while(scanf("%d",&n)!=EOF){printf("%d\n",p[n-1]);}
	return 0;
}
// http://www.spoj.com/problems/NPRIME/
