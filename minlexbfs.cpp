#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <list>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream fin("minlexbfs.in");
	ofstream fout("minlexbfs.out");
	int N,M,X,Y;
	vector<int> adj[100001];
	fin>>N>>M;
	int node;
	int source;
	int vect;
	int arr[M];
	int arr2[M];
	queue<int> q;
	int retine[M];
	for (int i=0;i<M;i++) {
		fin>>X>>Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
		//arr[i]=X;
		//arr2[i]=Y;
		retine[i]=X;
	}
	//sort(arr,arr+M);
	//sort(arr2,arr2+M);
	//if(arr[0]<=arr2[0])
	//  source=arr[0];
	//else
	//  source=arr2[0];
	source=1;
	for (int i=1;i<=N;i++)
	{
		sort(adj[i].begin(),adj[i].end());
	}
	
	vector<int> visited(N + 1, 0);
	visited[source]=1;
	q.push(source);
	while(!q.empty()) {
		node=q.front();
		fout<<node<<" ";
		q.pop();
		for (int i = 0; i < adj[node].size(); i++) {
			vect=adj[node][i];
			if(visited[vect]==0)
				{ visited[vect]=1;
				  q.push(vect);
				  }
			}
		
		visited[node]=1;
	}
}
