/*a37chen

Visual Implementation of Dijkstra's Algo for shortest path between nodes in a weighted graph

Mostly doing this because I am poop at coding and I was assigned to do this by the Big K

Things practiced/learned:
Includes
Namespaces
Templates(?)
Pointers(?)

*/

#include <vector>
#include <string>
#include <iostream>
#include <array>
#include <stack>

using namespace std;

//This could (and should?) probably be a class with access functions, but let's worry about that later
typedef struct {
	int dest;
	int wt;
} edge;

int main (){

	//Set the endpoints of the algorithm
	int startNode = 0;
	int endNode = 0;
	
	//Graph is vector of edge lists (arrays)
	//Vector and Lists each have their own +/-
	//Each member of vector is a node in the graph
	
	vector<vector<edge>> graph();
	
	////////////////////////////////
	//Hard code the graph for now
	//a1 = node 1, b2 = node 2, etc
	
	vector<edge> a1(2);
	a1[0] = {4, 8}; // same as a1[0].dest = 4; a1[0].wt = 8;
	a1[1] = {6, 6};
	graph.push_back (a1);
	
	vector<edge> b2(2);
	b2[0] = {3, 10};
	b2[1] = {4, 4};
	graph.push_back (b2);
	
	vector<edge> c3(3);
	c3[0] = {2, 10};
	c3[1] = {4, 7};
	c3[2] = {5, 1};
	graph.push_back (c3);

	vector<edge> d4(3);
	d4[0] = {2, 10};
	d4[1] = {4, 7};
	d4[2] = {5, 1};
	graph.push_back (d4);
	
	vector<edge> e5(2);
	e5[0] = {3, 1};
	e5[1] = {6, 3};
	graph.push_back (e5);
	
	vector<edge> f6(2);
	f6[0] = {1, 6};
	f6[1] = {5, 3};
	graph.push_back (f6);
	/*
	Direct initialization approach
	vector <vector<edge>> graph
	{ {{4,8}, {6,6}}
	  {{4,8}, {6,6}}
	 .
	 .
	 .
	};
	*/
	////////////////////////////////
	
	//Shortest Path Array
	//Store shortest paths to each node so far
	//Need to overload operators for manipulations with infinity
	//Initialize to 0 for starting point and infinity for the rest
	int dist [graph.size()];
	
	/*Initialize here*/
	
	//Previous node in shortest path from start node
	int prev [graph.size()];
	
	for (int i = 0; i<graph.size(); i++){
		prev[i] = -1; //let -1 be consdiered undefined
	}
	
	
	//Misc other variables for algo
	
	//Need change for infinity
	int curNode = 0;
	int testWt = 0;
	vector<edge> curEdList;
	
	while (!graph.empty()){
		//Find node closest to source
		for (int i = 0; i < graph.size(); i++){
			if (dist[i] < dist[curNode]) curNode = i;
		}
		curEdList = graph[curNode];
		//Remove from vector to mark as visited
		graph.erase (graph.begin()+curNode);
		
		//Check if path is better than existing stored path
		for (int i = 1; i<curVertex.size(); i++){
			testWt = dist[curNode] + curEdList[i].wt;
			if (testWt < dist[curEdlist[i].dest]){
				dist[curEdList[i].dest] = testWt;
				prev[curEdList[i].dest] = curNode;
			}
		}
	}
	
	//Reverse through the optimal path from the end node and store on stack
	deque<int> sp;
	curNode = end;
	while (prev[curNode] != -1){
		sp.push(curNode);
		curNode = prev[curNode];
	}
	sp.push(curNode);
	
	//To get path, now pop all elements of the stack
	//We could also add the weights, but too lazy for now, needs extra code above
	while (!sp.empty()){
		cout << "Path is: " << sp.top() << " ";
		sp.pop();
	}
	
	//cout << "test" << endl;
	
	return 0;

}
