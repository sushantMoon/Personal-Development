// http://www.spoj.com/problems/PRIME1/
// https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// https://www.programiz.com/c-programming/examples/prime-number-intervals

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int loop_1 = 0; loop_1 < cases; loop_1++)
	{
		int low, high;
		cin >> low >> high;
		for (int loop_2 = low; loop_2 <= high; loop_2++)
		{
			bool flag;
			int end;
			flag = true;
			end = sqrt(loop_2);
			if (loop_2 > 1)
			{
				for (int loop_3 = 2; loop_3 <= end; loop_3++)
				{
					if (loop_2 % loop_3 == 0)
					{	
						flag = false;
						break;
					}
				}
				if (flag == true)
					cout<< loop_2 << "\n";
			}
		}

		cout << "\n";
	}
	return 0;
}