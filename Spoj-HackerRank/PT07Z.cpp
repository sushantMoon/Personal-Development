// http://www.spoj.com/problems/PT07Z/
// https://cptalks.quora.com/Diameter-of-a-Tree
// http://codeforces.com/blog/entry/5787

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

#define MAX 10001
#define pd(n) printf("%d\n",n)
#define ps(n) printf("%s\n",n)


vector<vector<int>> graph(MAX);
int distanceArray[MAX];
bool visited[MAX];

int dfs(int root){
	
	// ps("root");	pd(root);

	visited[root] = true;
	int firstMaxDistance = 0,secondMaxDistance = 0;
	int numChildern = graph[root].size();
	
	// ps("NumChild");pd(numChildern);
	
	for(int i=0; i<numChildern; i++){
		int child = graph[root][i];
	
		// ps("child");pd(child);
	
		if (!visited[child])
		{
			int distance = dfs(child);
			if (distance > firstMaxDistance){
				secondMaxDistance = firstMaxDistance;
				firstMaxDistance = distance;
			}
			else if(distance > secondMaxDistance){
				secondMaxDistance = distance;
			}
		}
	}
	distanceArray[root] = firstMaxDistance + secondMaxDistance;
	
	// ps("maxdistance");pd(distanceArray[root]);

	return firstMaxDistance + 1;
}

void PT07Z(int vertices){
	// N vertices have N-1 edges
	for (int i = 0; i < vertices-1; i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	// as graph always starts from 1, vertices are 1 to N-1;
	int temp = dfs(1);
	int diameter = 0;
	for (int i = 1; i <= vertices; i++)
	{
		// ps("child");pd(i);pd(distanceArray[i]);
		if (distanceArray[i] > diameter){
			diameter = distanceArray[i];
		}
	}
	printf("%d\n", diameter);
}

int main() {
	int vertices;
	scanf("%d",&vertices);
	PT07Z(vertices);
	return 0;
}