#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Graph
{
public:
	int V;	// number of vertices
	vector<int> *adj;  //adjacency list 

	Graph(int V);
	void addEdge(int x, int y);
	bool isRoute(int x, int y);
};

// Constructor
Graph::Graph(int V)
{
	this->V=V;
	this->adj = new vector<int>[V];
}

// add a directed edge from x to y
void Graph::addEdge(int x, int y){
	adj[x].push_back(y);
}

bool Graph::isRoute(int x, int y){
	queue<int> q;
	vector<bool> visited(v,false);

	q.push(x);

	while(!q.empty()){
		int front = q.front();
		if (front == y){
			return true;
		}
		q.pop();
		visited[front] = true;
		for(int i = 0; i < adj[front].size(); i++){
			if (!visited[adj[front][i]]){
				q.push(adj[front][i]);
			}
		}
	}
	return false;

}
int main(){
	
    Graph g(6);	
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

/*	
	Test graph :
	0 <---4---->1
	^ 			^
	|			|
	|			|
    5---->2---->3 
*/
    cout<<g.isRoute(5,4)<<endl; // false
    cout<<g.isRoute(5,1)<<endl; // true

    return 0;
}