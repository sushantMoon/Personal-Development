#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <iostream>
#include <string>

using namespace std;

/*10000 has 5 digits*/
#define MAX 6
/*printf for numbers*/
#define pd(n) printf("%d\n",n)
/*printf for char array and string*/
#define ps(n) printf("%s\n",n)
/*printf for chars*/
#define pc(n) printf("%c\n",n)


void SBANK(){
    int n;
    scanf("%d",&n);
    map <string,int> accounts;
    map <string, int> :: iterator itr;
    for (int i=0;i<n;i++)
    {
        string number, a,b,c,d,e,f;
        cin >> a >> b >> c >> d >> e >> f;
        number = a + " " + b + " " + c + " " + d + " " + e + " " + f;
        /*cout << number << endl;*/
        int value = 0;
        try{
            value = accounts[number];
            accounts[number] = value + 1;
        }catch(const out_of_range &e){
            accounts.insert(pair <string,int> (number,value+1));
        }
    }

    for (itr = accounts.begin(); itr != accounts.end(); ++itr)
    {
        cout  << itr->first <<  ' ' << itr->second << '\n';
    }
    cout << "\n";
   getchar();
}


int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--){
		SBANK();
	}
	return 0;
}