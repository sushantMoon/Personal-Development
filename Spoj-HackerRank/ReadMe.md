# Using Windows Subsystem for Linux 
1.	Start Ubuntu Shell, run 
	```sh
	sudo service ssh start
	```
2. 

## Reference 

* https://blogs.msdn.microsoft.com/vcblog/2017/02/08/targeting-windows-subsystem-for-linux-from-visual-studio/


# Problems to Solve

http://www.spoj.com/problems/MATRMUL/
http://www.spoj.com/problems/ARITH/
http://www.spoj.com/problems/AMR12E/
http://www.spoj.com/problems/AMR12K/
http://www.spoj.com/problems/NSUBSTR/
http://www.spoj.com/problems/BULK/
https://vjudge.net/contest/19294
http://www.spoj.com/problems/RECEQU/
http://www.spoj.com/problems/PRINT/
http://www.spoj.com/problems/TWINP2/
https://www.quora.com/How-do-I-find-prime-numbers-up-to-10-9
http://www.spoj.com/problems/BSPRIME/
http://www.spoj.com/problems/PROPKEY/


# Template

```c++
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

/* Fast I/O */
#define gc getchar_unlocked
inline void scanint(int &x){
	x = 0;
	register int c = gc();
	int n = 0;
	while(c < '0' || c > '9'){
		(c=='-')?n=1:n=0;
		c=gc();
	}
	for (; c>='0'&&c<='9';c=gc())
		x = x*10 + c-48;   /* x*2  + x*8 = x*(2+8) = x*10   */
	(n)?x=-1*x:x;
}

/*10000 has 5 digits*/
#define MAX 6
/*printf for numbers*/
#define pd(n) printf("%d\n",n)
/*printf for char array and string*/
#define ps(n) printf("%s\n",n)
/*printf for chars*/
#define pc(n) printf("%c\n",n)


void function(){
	// function that solves the current problem
}


int main() {
	int cases;
	scanf("%d",&cases);
	while(cases--){
		// Function for the problem that that need to be solved
		function();
	}
	return 0;
}

```