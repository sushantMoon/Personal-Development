// http://www.spoj.com/problems/JULKA/
// very large number addition substraction division

#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAX 111
#define pd(n) printf("%d\n",n)
#define ps(n) printf("%s\n",n)
#define pc(n) printf("%c\n",n)

// returns a reverse string is returned which isthe addition of the two conventional/straight strings 
// reverse here means MSB is in right and LSB is in left
// conventionally/straight here means usually MSB is in left and LSB in right
char* addition(char a[MAX], char b[MAX]){
	char* result = new char[MAX];
	int sum = 0,carry = 0,index = 0;
	int alen = (int)strlen(a)-1;
	int blen = (int)strlen(b)-1;
	
	while(blen>=0){
		sum = (a[alen] - '0') + (b[blen] - '0') + carry;
		result[index] = sum%10 + '0';
		carry = sum/10;
		index++;
		alen--;
		blen--;
	}
	while(alen>=0){
		sum = (a[alen] - '0') + carry;
		result[index] = sum%10 + '0';
		carry = sum/10;
		index++;
		alen--;
	}
	while (carry>0)
	{
		result[index] = carry + '0';
		carry = carry/10;
		index++;
	}
	return result;
}

/*
Takes in reverse of the number which is to be divided
Reverse here means MSB is in right and LSB is in left
It returns a straight/conventional number divided by 2
*/
char* divideBy2(char a[MAX]){
	char* result = new char[MAX];
	int divisor=2,dividend=0,remainder=0,alen=(int)strlen(a)-1,index=0;
	while(alen>=0){
		dividend = (remainder*10) + a[alen] - '0';
		result[index] = dividend/divisor + '0';
		remainder = dividend%divisor;
		index++;
		alen--;
	}
	return result;
}

char* substraction(char a[MAX], char b[MAX]){
	char* result = new char[MAX];
	int alen = (int)strlen(a)-1;
	int blen = (int)strlen(b)-1;
	int index=0,carry=0,difference=0;
	while(blen>=0){
		difference = (a[alen] - '0') - (b[blen] - '0') - carry;
		if (difference<0){
			carry = 1;
			difference += 10;
		}
		else{
			carry=0;
		}
		result[index] = difference + '0';
		index++;
		alen--;
		blen--;
	}
	while(alen>=0){
		difference = (a[alen] - '0') - carry;
		if (difference<0){
			carry = 1;
			difference += 10;
		}
		else{
			carry=0;
		}
		result[index] = difference + '0';
		index++;
		alen--;
	}
	return result;
}

/*
removes trailing zeros after the MSB
*/
char* removeTrailingZeros(char a[MAX]){
	char* result = new char[MAX];
	int alen = (int)strlen(a),index=0,i=0;
	bool flag = ((a[index]-'0')!=0)?true:false;
	while(!flag){
		index++;
		if ((a[index]-'0')!=0)
		{
			flag = true;
		}
	}
	while(index<alen){
		result[i] = a[index];
		index++;
		i++;
	}
	return result;	
}

int JULKA(){
	char a[MAX],b[MAX];

	scanf("%s",&a[0]);
	scanf("%s",&b[0]);

	char* k = new char[MAX];
	char* n = new char[MAX];
	/*
	logic :
	k = (a+b)/2
	n = a-k
	*/
	k = removeTrailingZeros(divideBy2(addition(a,b)));
	n = substraction(a,k);
	reverse(n,n+strlen(n));
	ps(k);
	ps(removeTrailingZeros(n));
}

int main() {
	int cases=10;
	while(cases--){
		JULKA();
		// break;
	}
	return 0;
}