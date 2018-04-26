// project1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	
    cout << "===================================================================================================================" << endl;
	cout << "===================================================================================================================" << endl;
	cout<< "||												WELCOME TO OUR PROJECT												||";
	cout << "===================================================================================================================" << endl;
	cout << "===================================================================================================================" << endl;
	
	
	int option;
	ifstream file("FGRAPH");
    Graph g(file);
	
	do 
	{
		 //Displaying Options for the menu
		 cout << "1) To Display Breadth First Traversal" << endl;
		 cout << "2) To Display Depth First Traversal " << endl;
		 cout << "3) To Determine Connection between Two Vertices " << endl;
		 cout << "4) To Display Connected Components (Sub Graphs) " << endl;
		 cout << "5) To Determine Distance (Path Length) " << endl;
		 cout << "6) To Determine BiPartite Graph " << endl;
		 cout << "7) To Apply Minimum Spanning Tree (Prim's Algorithm) " << endl;
		 cout << "8) To Apply Minimum Spanning Tree (Kruskal's Algorithm) " << endl;
		 cout << "9) To Apply Single Source Shortest Path (Dijkstra's Algorithm) " << endl;
		 cout << "10) To Display All Pair Shortest Paths " << endl;
		 cout << "11) To Exit Program " << endl;
		 
		 cout << "Please select an option : ";
		 cin >> option;  // taking option value as input and saving in variable "option"
		 
		 switch(option)
		 {
			case 1:
					g.BFS(1);
			break;
			case 2:
					cout<<"ENTER The vertex from where you want to start DFS:";
					int b=0;
					cin>>b;
					b=b-1;
					g.DFS(b);
			break;
			case 3:
					g.is_Connected(1,4);
			break;
			case 4:
					g.Sub_Graphs();
			break;
			case 5:
				   cout<<"ENTER The vertex from where you want to start path:";
				   int s=0;
				   cin>>s;
				   int d;
				   cout<<"ENTER The Destination vertex :";
				   cin>>d;

				   g.Calculate_Distance(s-1,d);
			break;
			case 6:
					g.is_Bipartite(1)?cout<<endl<<"YES":cout<<endl<<"NO";
			break;
			case 7:
					g.Prim(1);
			break;
			case 8:
					g.shortpath_Kruskal();
			break;
			case 9:
					g.shortpath();
			break;
			case 10:
					g.All_pair();
			break;
			
		 }
		 
	}while(option != 11);  //condition of do-while loop	
		
	return 0;

}

