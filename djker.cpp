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
	int endNode = 2;
	
	//Graph is vector of edge lists (arrays)
	//Vector and Lists each have their own +/-
	//Each member of vector is a node in the graph
	
	vector<vector<edge> > graph; //cannot do vector<vector<edge>> graph;
	
	//not vector<vector<edge> > graph(); 
    //http://stackoverflow.com/questions/877523/error-request-for-member-in-which-is-of-non-class-type
	
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
	d4[0] = {1, 8};
	d4[1] = {2, 4};
	d4[2] = {3, 7};
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
	
	int gSize = graph.size();
	
	//Shortest Path Array
	//Store shortest paths to each node so far
	//Initialize to 0 for starting point and "infinity" for the rest
	int dist [gSize];
	for (int i = 0; i<gSize; i++){
		dist [i] = -1; //let -1 to be considered +inf
	}
	dist [startNode] = 0; //Beginning node has dist 0
	
	//Previous node in shortest path from start node
	int prev [gSize];
	for (int i = 0; i<gSize; i++){
		prev[i] = -1; //let -1 be considered undefined
	}
	
	//Visited Array
	
	bool visited[gSize];
	for (int i = 0; i < gSize; i++){
		visited[i] = false;
	}
	
	//Misc other variables for algo
	int curNode = 0;
	int testWt = 0;
	vector<edge> curEdList;
	
	/*Debug
	
	while (!graph.empty()){
		curEdList = graph[0];
		cout<< curEdList[0].dest << " " << curEdList[0].wt << endl;
		graph.erase(graph.begin());
	}*/
	
	int visitCount = 0;
	while (visitCount < gSize){
		//Find node closest to source
		for (int i = 0; i < gSize; i++){
			//First node is special case
			if (dist[i] == 0 && !visited[i]) {
				curNode = i;
				break;
			}
			//Problem is here
			//Nodes never move from dist[0] since it's always smaller
			//Need to somehow remove the node at each pass
			//Maybe change the curnode after for loop at line 157
			else if ((dist[i] < dist[curNode]) && !visited[i] && (dist[i] > 0)) {
				curNode = i;
			}
		}

		curEdList = graph[curNode];

		visited[curNode] = true;
		visitCount++;
		for (int i = 0; i < curEdList.size(); i++){
			testWt = dist[curNode] + curEdList[i].wt;
			if (testWt < dist[curEdList[i].dest-1] || dist[curEdList[i].dest-1] == -1){
				dist[curEdList[i].dest-1] = testWt;
				cout << "Weight is: " << testWt << endl;
				prev[curEdList[i].dest-1] = curNode;
			}
		}
	}
	
	//Reverse through the optimal path from the end node and store on stack
	
	for (int i = 0; i < gSize; i++){
		cout<< "Prev is: " << prev[i] << endl;
	}
	
	/*
	stack<int> sp;
	curNode = endNode;
	while (prev[curNode] != -1){
		sp.push(curNode);
		curNode = prev[curNode];
	}
	sp.push(curNode);
	
	//To get path, now pop all elements of the stack
	//Add weights later, need extra tracking elsewhere above
	while (!sp.empty()){
		cout << "Path is: " << sp.top() << " ";
		sp.pop();
	}
	
	//cout << "test" << endl;
	
	*/
	
	
	return 0;

}
