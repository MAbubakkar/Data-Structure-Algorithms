
#include "stdafx.h"


class Graph
{

public:

	Graph(std::ifstream &file);


	bool is_Adjacent(int v1,int v2);
	void Initialize_Graph(int size);
	void LoadCSV();
	int GetCSVSize(std::ifstream &file1);
	void DFS(int v);
	void BFS(int s);
	void is_Connected(int s,int v2);
	void Sub_Graphs();
	int Path_Length(int s);
	int is_Bipartite(int s);
	int getClosestUnmarkedNode();
	void Reset();
	void Calculate_Distance(int source,int destination);
	void printPath(int node);
	void Prim(int source);
	void All_pair();
	void shortpath();
	void shortpath_Kruskal();
	
	
	~Graph();

private:

	int **A_Matrix;
	int nVertices;
	bool *Visited;
	bool *Visited1;
	bool *Visited2;
	bool *visited3;
	int *distance;
	int *predecessor;
	int temp;

};

//----------------------
//
//class Graph {
//
// private:
// int n; /// n is the number of vertices in the graph
// int **A; /// A stores the edges between two vertices
// bool *visited2;
// bool *visited3;
// int *predecessor,*distance;
// int temp;
// public:
//	 Graph(std::fstream &file);
// ~Graph();
// void function();
// bool isConnected(int, int);
// void addEdge(int u, int v);
// void BFS(int );
// void DFS (int);
// bool isBipartite(int src);
// void isreachable(int s,int v2);
// void subgraphs();
// void calculateDistance(int ,int);
// int getClosestUnmarkedNode();
// void printPath(int node);
// void printPath2(int,int node);
// void shortpath();
// void All_pair();
// bool is_Adjacent(int v1,int v2);
//void Initialize_Graph(int size);
//void LoadCSV();
//int GetCSVSize(std::fstream &file1);
//void Prim(int source);
//
//};
//
