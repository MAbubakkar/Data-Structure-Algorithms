
#include "Graph.h"
#include<fstream>
#include<iostream>
#include"Queue.h"
#include "stdafx.h"

using namespace std;
using std::endl;
using std::cout;

Graph::Graph(std::ifstream &file) {

Initialize_Graph(GetCSVSize(file));
LoadCSV();

}
bool Graph::is_Adjacent(int v1,int v2)
{

    return A_Matrix[v1-1][v2-1];
}
void Graph::Initialize_Graph(int size)
{
nVertices=size;

Visited=new bool[size];
Visited1=new bool[size];
Visited2=new bool[size];
visited3=new bool[size];
distance=new int [size];
predecessor=new int[size];

A_Matrix=new int*[size];
for(int i=0;i<size;i++)
{
A_Matrix[i]=new int[size];
Visited[i]=false;
Visited1[i]=false;
Visited2[i]=false;
visited3[i]=false;
 predecessor[i] = -1;
	 distance[i] = 5000;
}

for(int i=0;i<nVertices;i++)
for(int j=0;j<nVertices;j++)
    A_Matrix[i][j]=0;

}
Graph::~Graph() {
	// TODO Auto-generated destructor stub
}
void Graph::LoadCSV()
{

std::ifstream file;
file.open("21");
for(int i=0;i<nVertices;i++)
{
 for(int j=0;j<nVertices;j++)
 {
  file>>A_Matrix[i][j];
 }
}

cout<<"  ::::Matrix::::"<<endl<<endl;
for(int i=0;i<nVertices;i++)
{for(int j=0;j<nVertices;j++)
{
 std::cout<<A_Matrix[i][j]<<" ";
}
std::cout<<std::endl;
}
cout<<endl<<endl<<endl;}
int Graph::GetCSVSize(std::ifstream &file1)
{
    int count=0;

std::string temp;
while(  file1 >> temp)
{

count++;

}
std::ifstream file("12");
 char a;
std:: ofstream file2("21");
 if(!file.is_open())
 {
  cout<<" Error!! Cannot Open File::";
 }
 else
 {
     while(!file.eof())
  {
      file>>a;
  if(a==',')
    continue;
  else
  {file2<<a;
  file2<<endl;
  }
  }
file2<<endl;
}
file.close();
file2.close();

return count;

}
void Graph::DFS(int v)
{
	Visited[v]=true;
	cout<<v+1<<" ";

	for(int i=0;i<nVertices;i++)
	{
	    if(A_Matrix[v][i]&&!Visited[i])
	    {
	        DFS(i);
	    }

	}
}
void Graph::BFS(int s)
{
Queue<int> Que;
Que.enqueue(s);

bool *Visited= new bool[nVertices+1];
int i;

for (i = 1; i <= nVertices; i++)
Visited[i] = false;

Visited[s] = true;

while (!Que.isEmpty())
    {
  int v = Que.dequeue();
cout << v << " ";
for (int i = 1; i <= nVertices; i++)

  if (is_Adjacent(v, i) && !Visited[i]) {
  Que.enqueue(i);
Visited[i] = true;
}

}
cout << endl;

}
void Graph::is_Connected(int s,int v2)
{
Queue<int> Que;
Que.enqueue(s);

bool *Visited= new bool[nVertices+1];
int i;

for (i = 1; i <= nVertices; i++)
Visited[i] = false;

Visited[s] = true;

while (!Que.isEmpty())
    {
  int v = Que.dequeue();
if(v==v2)
{
    cout<<"Connection Found";
    return ;
}
for (int i = 1; i <= nVertices; i++)

  if (is_Adjacent(v, i) && !Visited[i]) {
  Que.enqueue(i);
Visited[i] = true;
}

}
cout << endl;

}
void Graph::Sub_Graphs()
{
	int count=1;
	int i;
	for( i = 0; i < nVertices; i++)
		Visited1[i] = false;

	for ( i=0; i<nVertices; i++)
	{
		if (Visited[i] == false)
		{
			cout<<"Sub Graph :"<<count<<endl;
			DFS(i);
			cout << "\n";
count++;
		}
     }
Reset();
}
int Graph::Path_Length(int s) {
	Queue<int> Q;


int L;
int i;	bool *Visited= new bool[nVertices+1];
	for (int i=1;i<= nVertices;i++)
	Visited[i] = false;
	Q.enqueue(s);
	Visited[s] = true;
	L=0;
	while (!Q.isEmpty()) {
		int check=0;
		int v = Q.dequeue();

	for (i= 1; i <= nVertices; i++)

	{  if (is_Adjacent(v, i) && !Visited[i]) {
	 Q.enqueue(i);
     check++;
    Visited[i] = true;
	if(check==1)
{
	L++;
}
	}

	}

	}

return L;

}
int Graph::is_Bipartite(int s)
{
    int *color =new int[nVertices];
    for (int i = 0; i < nVertices ; i++)
        color[i] = -1;

    color[s] = 1;
   Queue <int> Que;
    Que.enqueue(s);

    while (!Que.isEmpty())
    {
        int u = Que.isEmpty();
        Que.dequeue();
       int i;
        for ( i = 0; i < nVertices; i++)
        {
            if (A_Matrix[u][i] && color[i] == -1)
            {
                color[i] = 1 - color[u];
                Que.enqueue(i);
            }

            else if (A_Matrix[u][i] && color[i] == color[u])
                return false;
        }
    }

    return true;
}
int Graph::getClosestUnmarkedNode(){
    int minDistance = 5000;
    int closestUnmarkedNode;
    for(int i=0;i<nVertices;i++) {
        if((!visited3[i]) && ( minDistance >= distance[i])) {
            minDistance = distance[i];
            closestUnmarkedNode = i;
        }
    }
    return closestUnmarkedNode;
}
void Graph::Reset()
{
    	for(int i=0;i<nVertices;i++)
    {
        	 predecessor[i] = -1;
        distance[i] = 5000;
visited3[i]=false;
    }

}

void Graph::shortpath_Kruskal(){
int i;
cout<<"enter to the source vertex:";
cin>>i;
i=i-1;
		for(int j=0;j<=n;j++){
			if (i==j){

			}
			else{
				calculateDistance(i,j);

		}
	}
}


void Graph::Calculate_Distance(int source,int destination){
 	Reset();

 	distance[source]= 0;
    int closestUnmarkedNode;
    int count = 0;
    while(count < nVertices) {
        closestUnmarkedNode = getClosestUnmarkedNode();
        visited3[closestUnmarkedNode] = true;
        for(int i=0;i<nVertices;i++) {
            if((!visited3[i]) && (A_Matrix[closestUnmarkedNode][i]>0) )
            {
                if(distance[i] > distance[closestUnmarkedNode]+A_Matrix[closestUnmarkedNode][i])
                {
                    distance[i] = distance[closestUnmarkedNode]+A_Matrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
    temp=source;
    for(int i=0;i<nVertices;i++) {
       if(i==destination-1)
         {

           printPath(i);
            cout<<"->"<<distance[i]<<endl;
        }
        }

}
void Graph::printPath(int node){
    if(node == temp)
        cout<<(node+1)<<"..";
    else if(predecessor[node] == -1)
        cout<<"No path from"<<temp<<"to "<<(int)(node+1)<<endl;
    else {
        printPath(predecessor[node]);
        cout<<(int) (node+1)<<"..";
    }
}
void Graph::Prim(int source)
{
    	distance[source]= 0;
   // int minDistance = infi;
    int closestUnmarkedNode;
    int count = 0;
    while(count < nVertices) {
        closestUnmarkedNode = getClosestUnmarkedNode();
        visited3[closestUnmarkedNode] = true;
        for(int i=0;i<nVertices;i++) {
            if((!visited3[i]) && (A_Matrix[closestUnmarkedNode][i]>0) )
            {
                if(distance[i] > distance[closestUnmarkedNode]+A_Matrix[closestUnmarkedNode][i])
                {
                    distance[i] = distance[closestUnmarkedNode]+A_Matrix[closestUnmarkedNode][i];
                    predecessor[i] = closestUnmarkedNode;
                }
            }
        }
        count++;
    }
    temp=source;
    //PRINTS THE PATH//
    for(int i=0;i<nVertices;i++) {
         {

           printPath(i);
            cout<<"->"<<distance[i]<<endl;
        }
        }

}

void Graph::All_pair(){
	cout<<"ALL PAIR SHORTEST PATH"<<endl;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++){
				if (i==j){

				}
				else{
					calculateDistance(i-1,j);

			}
		}
}

void Graph::shortpath(){
	cout<<"Dijkstra Algorithm"<<endl;
int i;
cout<<"enter to the source vertex:";
cin>>i;
i=i-1;
		for(int j=0;j<=n;j++){
			if (i==j){

			}
			else{
				calculateDistance(i,j);

		}
	}
}

