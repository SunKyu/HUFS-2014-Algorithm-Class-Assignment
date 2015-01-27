// dfs.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue> 
using namespace std;

//enum colorType = {white, gray, black};
// const int MAX = 1000;
//int _tmain(int argc, _TCHAR* argv[])
/*
void dfs(bool **adjMatrix, int n, int v, bool *visited)
{
	visited[v] = true;
	cout << v << " ";

	for (int w = 1; w <= n; w++)
		if (adjMatrix[v][w] && !visited[w])
			dfs(adjMatrix, n, w, visited);
}
*/
struct NodeType
{
	int vertex;
	NodeType* link;
};

/*
void dfs(NodeType **adjList, int n, int v, bool *visited)
//void dfs(NodeType **adjList, int n, int v, colorType *color)
{
	visited[v] = true;
//	cout << v << " ";
//
//	for (int w = 1; w <= n; w++)
//		if (adjMatrix[v][w] && !visited[w])
//			dfs(adjMatrix, n, w, visited);
//
	NodeType* ptr = adjList[v];
	while (ptr)
	{	int w = ptr->vertex;
		if (!visited[w])
			dfs(adjList, n, w, visited);

//		cout << v << " ";

		ptr = ptr->link;
	}

//	cout << v << " ";
}
*/
/*
int main()
{
//	bool adjMatrix[MAX][MAX];

	bool **adjMatrix;
	int n, m; // n: the number of vertices, m: the number of edges

	cin >> n >> m;

	int i, j;
	adjMatrix = new bool*[n+1];
	
	for (i = 1; i <= n; i++)
	  adjMatrix[i] = new bool[n+1];

	bool *visited;

	visited = new bool[n+1];

	for (i = 1; i <= n; i++)
	{
		visited[i] = false;
		for (j = 1; j <= n; j++)
			adjMatrix[i][j] = false;
	}

	for (i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adjMatrix[u][v] = true;
		adjMatrix[v][u] = true;
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
           cout << adjMatrix[i][j] << " ";

		cout << "\n";  // 	cout << endl;
	}

	cout << endl;

	int compNum = 0;
	for (i = 1; i <= n; i++)
		if (!visited[i])
		{
 			 cout << endl;
			 compNum++;
			 cout << "Component " << compNum << " : " ;
	         dfs(adjMatrix, n, i, visited);
		}

	return 0;
}
*/
/*
int main()
{
//	bool adjMatrix[MAX][MAX];

	NodeType** adjList;
	int n, m; // n: the number of vertices, m: the number of edges

	ifstream IN;
	IN.open("input.txt");

//	cin >> n >> m;
	IN >> n >> m;
	int i, j;
	adjList = new NodeType*[n+1];
	
	bool *visited;

	visited = new bool[n+1];

	for (i = 1; i <= n; i++)
	{
		visited[i] = false;
		adjList[i] = NULL;

	}

	NodeType* ptr;
	for (i = 1; i <= m; i++)
	{
		int u, v;
//		cin >> u >> v;
		IN >> u >> v;
		ptr = new NodeType;
		ptr->vertex  = v;
		ptr->link = adjList[u];
		adjList[u] = ptr;
//
//		ptr = new NodeType;
//		ptr->vertex  = u;
//		ptr->link = adjList[v];
//		adjList[v] = ptr;
//
	}
  
	// 
	for (i = 1; i <= n; i++)
	{
		cout << "The vertices adjacent from vertex " << i 
			 << " :  ";
		ptr = adjList[i];
		while (ptr) // (ptr != NULL)
		{
			cout << ptr->vertex << " ";
			ptr = ptr->link;
		}
		cout << "\n";
	}

//	dfs(adjList, n, 7, visited);


	cout << endl;
//
//	int compNum = 0;
//	for (i = 1; i <= n; i++)
//		if (!visited[i])
//		{
// 			 cout << endl;
//			 compNum++;
//			 cout << "Component " << compNum << " : " ;
//	         dfs(adjList, n, i, visited);
//		}
//
	for (i = 1; i <= n; i++)
		if (!visited[i])
			dfs(adjList, n, i, visited);


	return 0;
}
*/

void bfs(bool **adjMatrix, int n, int s, bool visited[],
	int d[])
{
	queue<int> Q;

	for(int v = 1; v <= n; v++)
		visited[v] = false;

    visited[s] = true;

	Q.push(s);
	d[s] = 0;
	cout << s << " ";
	while(!Q.empty())
	{
	
		int v = Q.front();
		Q.pop();
		for (int w = 1; w <= n; w++)
		{
			if (adjMatrix[v][w] && !visited[w])
			{
				visited[w] = true;
				d[w] = d[v] + 1;
				cout << w << " ";
				Q.push(w);
			}
		}
	}


}


int main(int argc, char* argv[])
{
//	bool adjMatrix[MAX][MAX];

	bool **adjMatrix;
//	NodeType** adjList;
	int n, m; // n: the number of vertices, m: the number of edges

	ifstream IN;
	IN.open(argv[1]);
  cout<<argv[1]<<endl;
//	cin >> n >> m;
	IN >> n >> m;
	int i, j;
//	adjList = new NodeType*[n+1];
	
	bool *visited;

	adjMatrix = new bool*[n+1];
	
	for (i = 1; i <= n; i++)
	  adjMatrix[i] = new bool[n+1];


	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			adjMatrix[i][j] = false;


	for (i = 1; i <= m; i++)
	{
		int u, v;
		IN >> u >> v;
		adjMatrix[u][v] = true;
		adjMatrix[v][u] = true;
	}
	visited = new bool[n+1];

	int *d;
	d = new int[n+1];

	for (i = 1; i <= n; i++)
	{
		visited[i] = false;
		d[i] = -1;
	}


	bfs(adjMatrix, n, 1, visited, d);

	cout << endl;
	for (i = 1; i <= n; i++)
		cout << d[i] << " ";

	cout << endl;
}





