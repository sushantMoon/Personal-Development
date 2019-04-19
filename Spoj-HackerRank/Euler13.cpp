// https://www.hackerrank.com/contests/projecteuler/challenges/euler013
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

vector<int> summation;
vector<string> list;
void FuncSummation(int size){
	int sum = 0;
	int carry = 0;
	for (int j = 49; j >= 0; j--)
	{
		for (int i = 0; i < size; ++i)
		{
			// printf("%d , ",list[i][j] - '0');
			sum += (list[i][j] - '0');
		}
		// printf("total : %d, carry : %d,sum : %d\n",sum ,sum/10, sum%10);
		// cout << "\n";
		summation.push_back(sum%10);
		sum = sum/10;
	}
	while(sum != 0)
	{
		summation.push_back(sum%10);
		sum = sum/10;	
	}
}

int main() {
	int size;
	scanf("%d", &size);
	for (int i = 0; i < size; ++i)
	{
		char l[50];
		scanf("%50s", l);
		list.push_back(l);		
	}
	// for (int i = 0; i < size; ++i)
	// {
	// 	// cout << list[i] << endl;
	// 	printf("%50s\n", list[i].c_str());
	// }
	FuncSummation(size);
	for (int i = summation.size()-1; i > summation.size()-11; i--)
	{
		printf("%d", summation[i]);
	}
	printf("\n");
	return 0;
}