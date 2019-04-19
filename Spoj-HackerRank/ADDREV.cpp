// http://www.spoj.com/problems/ADDREV/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;


#define MAX 6 					/*10000 has 5 digits*/
#define pd(n) printf("%d\n",n)
#define ps(n) printf("%s\n",n)
#define pc(n) printf("%c\n",n)

int revCArray2Int(char num[MAX]){
	int n=0, len=(int)strlen(num), power = 0;
	while(power < len){
		n += (num[power] - '0') * (int)pow(10,power);
		power++;
	}
	return n;
}

int revInt(int n){
	int result=0,power=(int)log10(n);
	while(power>=0){
		result += n%10 * (int)pow(10,power);
		n/=10;
		power--;
	}
	return result;
}

void ADDREV(){
	char n1[MAX],n2[MAX];
	scanf("%s %s",&n1[0],&n2[0]);
	int num2 = revCArray2Int(n2);
	int num1 = revCArray2Int(n1);
	// ps(n1);pd(num1);
	// ps(n2);pd(num2);
	int sum = num1+num2;
	pd(revInt(sum));
}


int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--){
		ADDREV();
		// break;
	}
	return 0;
}