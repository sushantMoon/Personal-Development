// http://www.spoj.com/problems/ONP/
// http://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/

#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

int operatorOrder(char symbol)
{
	// +, -, *, /, ^  // Order of priority -> lowest to highest 
	if (symbol == '+')
		return 1;
	if (symbol == '-')
		return 2;
	if (symbol == '*')
		return 3;
	if (symbol == '/')
		return 4;
	if (symbol == '^')
		return 5;
	else
		return 0;
}

string postfix(string expression)
{
	std::stack<char> symbols;
	string postfix;
	int len = expression.length();
	for (int i = 0; i < len; i++)
	{
		char exp = char(expression[i]);
		if (exp >= 'a' && exp <= 'z')
			postfix += exp;
		else if (exp == '(')
			symbols.push('(');
		else if (exp == ')')
		{
			while ( symbols.empty() == false && symbols.top() != '(' )
			{
				postfix += symbols.top();
				symbols.pop();
			}
			if (symbols.top() == '(')
				symbols.pop();
		}
		else
		{
			// enters here only if the current char is symbol
			while ( symbols.empty() == false && operatorOrder(symbols.top()) > operatorOrder(exp) )
			{
				postfix += symbols.top();
				symbols.pop();
			}
			symbols.push(exp);
		}
	}

	while (!symbols.empty())
	{
		postfix += symbols.top();
		symbols.pop();
	}
	return postfix;
}


int main() {
	int cases;
	cin >> cases;
	for (int loop_1 = 0; loop_1 < cases; loop_1++)
	{
		string exp;
		cin >> exp;
		cout << postfix(exp) << "\n";
	}
	return 0;
}


// Save the input in a file seperate file, eg. inputs and then compile g++ ONP.cpp && ./a.out < inputs
// Input:
// 3
// (a+(b*c))
// ((a+b)*(z+x))
// ((a+t)*((b+(a+c))^(c+d)))



//  Expected outputs
// Output:
// abc*+
// ab+zx+*
// at+bac++cd+^*