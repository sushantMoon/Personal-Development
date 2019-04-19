// http://www.spoj.com/problems/LABYR1/

// Incomplete Problem

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 1001
#define pd(n) printf("%d\n",n)
#define ps(n) printf("%s\n",n)

char graph[MAX][MAX];
int visited[MAX][MAX];
int R,C;

int recursiveDFS(int startR,int startC){
	int highest = 0;
	if(graph[startR][startC] = '.' && visited[startR][startC] == 0){
		/* handling the already visited cases or wall is present as well as handling the border cases is done in the if statement */
		int up = 	((startR-1 >= 0 && startR-1 < R && startC >= 0 && startC < C && graph[startR-1][startC] == '.' && visited[startR-1][startC] == 0)?recursiveDFS(startR-1,startC):0);

		int down = 	((startR+1 >= 0 && startR+1 < R && startC >= 0 && startC < C && graph[startR+1][startC] == '.' && visited[startR+1][startC] == 0)?recursiveDFS(startR+1,startC):0);
		
		int left = 	((startR >= 0 && startR < R && startC-1 >= 0 && startC-1 < C && graph[startR][startC-1] == '.' && visited[startR][startC-1] == 0)?recursiveDFS(startR,startC-1):0);
		
		int right = ((startR >= 0 && startR < R && startC+1 >= 0 && startC+1 < C && graph[startR][startC+1] == '.' && visited[startR][startC+1] == 0)?recursiveDFS(startR,startC+1):0);
		if (up > highest)
			{highest = up;}
		if (down > highest)
			{highest = down;}
		if (left > highest)
			{highest = left;}
		if (right > highest)
			{highest = right;}
		visited[startR][startC] = highest;
	}
	
	return 1 + highest;
}

void LABYR1(){
	cin >> C >> R;
	
 	for (int i=0;i<R;i++)
	{
		cin >> graph[i];
		for(int j=0;j<C;j++){
			if (graph[i][j] == '#')
			{
				visited[i][j] = -1;
			}
			else if (graph[i][j] == '.')
			{
				visited[i][j] = 0;
			}
		}
	}


	// for (int i=0;i<R;i++)
	// {
	// 	for(int j=0;j<C;j++){
	// 			printf("%c",graph[i][j]);
	// 		}
	// 	printf("\n");
	// }
	// for (int i=0;i<R;i++)
	// {
	// 	for(int j=0;j<C;j++){
	// 			printf("%d",visited[i][j]);
	// 		}
	// 	printf("\n");
	// }

	for (int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++){
				if (graph[i][j] == '.' && visited[i][j] == 0)
				{
					int tempLength = recursiveDFS(i,j); 
				}
			}
	}

	int length = 0;
	for (int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++){
			if (visited[i][j] > length){
				length = visited[i][j];
			} 
		}
	}
	printf("Maximum rope length is %d.\n", length);
}

int main() {
	int cases;
	cin >> cases;
	while(cases--)
		LABYR1();
	return 0;
}