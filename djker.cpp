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

typedef struct {
	int id = 0;
	vector<edge> *edList = {};
} vertex;

int main (){

	//Set the endpoints of the algorithm
	int startNode = 0;
	int endNode = 2;
	
	vector<vertex> graph;
	
	//not vector<vector<edge> > graph(); 
    //http://stackoverflow.com/questions/877523/error-request-for-member-in-which-is-of-non-class-type
	
	////////////////////////////////
	//Hard code the graph for now
	//a1 = node 1, b2 = node 2, etc
	
	vertex a;
	a.id = 1;
	vector<edge> a1(2);
	a1[0] = {4, 8}; // same as a1[0].dest = 4; a1[0].wt = 8;
	a1[1] = {6, 6};
	a.edList = &a1;
	graph.push_back (a);
	
	vertex b;
	b.id = 2;
	vector<edge> b2(2);
	b2[0] = {3, 10};
	b2[1] = {4, 4};
	b.edList = &b2;
	graph.push_back (b);
	
	vertex c;
	b.id = 3;
	vector<edge> c3(3);
	c3[0] = {2, 10};
	c3[1] = {4, 7};
	c3[2] = {5, 1};
	c.edList = &c3;
	graph.push_back (c);

	vertex d;
	d.id = 4;
	vector<edge> d4(3);
	d4[0] = {1, 8};
	d4[1] = {2, 4};
	d4[2] = {3, 7};
	d.edList = &d4;
	graph.push_back (d);
	
	vertex e;
	e.id = 5;
	vector<edge> e5(2);
	e5[0] = {3, 1};
	e5[1] = {6, 3};
	e.edList = &e5;
	graph.push_back (e);
	
	vertex f;
	f.id = 6;
	vector<edge> f6(2);
	f6[0] = {1, 6};
	f6[1] = {5, 3};
	f.edList = &f6;
	graph.push_back (f);
	
	/*
	Direct initialization approach
	vector < vector<edge>> graph
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
	
	//Misc other variables for algo
	int curNode = 0;
	int testWt = 0;
	int curID = 0;
	vertex tempVertex;
	vector<edge>* tempEdList;
	int tempWt = 0;
	int tempDest = 0;
	
	while (!graph.empty()){
		//Find node closest to source
		curNode = 0;
		for (int i = 0; i < graph.size(); i++){
			//First node is special case
			if (dist[i] == 0) {
				curNode = i;
				break;
			}
			else if (((dist[i] < dist[curNode]) && dist[i] >= 0) || (dist[curNode] < 0)) {
				curNode = i;
			}
		}
		
		tempVertex = graph[curNode];
		tempEdList = tempVertex.edList;
		curID = tempVertex.id-1; 
		graph.erase(graph.begin()+curNode);

		//Update distance values for all neighbours
		for (int i = 0; i < tempEdList->size(); i++){
			tempWt = tempEdList->at(i).wt;
			tempDest = tempEdList->at(i).dest-1;
			testWt = dist[curID] + tempWt;
			if (testWt < dist[tempDest] || dist[tempDest] < 0){
				dist[tempDest] = testWt;
				prev[tempDest] = curID+1;
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
