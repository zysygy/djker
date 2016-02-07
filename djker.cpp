#include <vector>

using namespace std;

struct edge {
	int dest;
	int wt;
};

int main (){

	//Graph is vector of edge lists (arrays)
	//Each member of vector is a node in the graph
	
	vector<neighbour*> graph = vector<neighbour*>();
	
	//Hard code the graph for now
	//a1 = node 1, b2 = node 2, etc
	
	edge a1[2];
	a1[0].dest = 4;
	a1[0].wt =  8;
	a1[1].dest = 6;
	a1[1].wt = 6;
	graph.push_back (a1);
	
	edge b2[2];
	b2[0].dest = 3;
	b2[0].wt =  10;
	b2[1].dest = 4;
	b2[1].wt = 4;
	graph.push_back (b2);
	
	edge c3[3];
	c3[0].dest = 2;
	c3[0].wt = 10;
	c3[1].dest = 4;
	c3[1].wt = 7;
	c3[2].dest = 5;
	c3[2].wt = 1;
	graph.push_back (c3);

	edge d4[3];
	d4[0].dest = 2;
	d4[0].wt = 10;
	d4[1].dest = 4;
	d4[1].wt = 7;
	d4[2].dest = 5;
	d4[2].wt = 1;
	graph.push_back (d4);
	
	edge e5[2];
	e5[0].dest = 3;
	e5[0].wt = 1;
	e5[1].dest = 6;
	e5[1].wt = 3;
	graph.push_back (e5);
	
	edge f6[2];
	f6[0].dest = 1;
	f6[0].wt =  6;
	f6[1].dest = 5;
	f6[1].wt = 3;
	graph.push_back (f6);

	//
	
	return 0;

}
