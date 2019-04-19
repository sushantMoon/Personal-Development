// http://www.spoj.com/problems/BALLSUM/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

/*10000 has 5 digits*/
#define MAX 6
/*printf for numbers*/
#define pd(n) printf("%d\n",n)
/*printf for char array and string*/
#define ps(n) printf("%s\n",n)
/*printf for chars*/
#define pc(n) printf("%c\n",n)

int gcd(int a, int b){
    if (a%b==0){
        return b;
    }
    return gcd(b,a%b);
}
void ballsum(int n, int k){
    int num = 0;
    if (k == -1){
        return ;
    }
    if (k<=2){
        printf("0\n");
        return;
    }
    if (k%2 == 0){
        num = (k*(k-2))/4;
    }
    else{
        num = ((k-1)*(k-1))/4;
    }
    int den = (n*(n-1))/2;
    while(true){
        int divisor = gcd(num, den);
        if (divisor==1){
            break;
        }
        num /= divisor;
        den /= divisor;
        if(num==1||den==1){
            break;
        }
    }
    if (num==1&&den==1){
        printf("%d\n",num);
    }
    else{
        printf("%d/%d\n",num,den);
    }
    
}


int main() {
	int n=0,k=0;
    
    while((n!=-1)&&(k!=-1)){
	    cin >> n >> k;
        ballsum(n,k);
    };
	return 0;
}