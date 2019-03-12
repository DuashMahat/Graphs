


#include <iostream>
#include <iostream>
#include <iostream> 
#include <list> 
#include <queue>
#include <iterator> 
using namespace std;
/*
Route Between Nodes: Given a directed/undirected graph, design an algorithm to find out whether there is a
route between two nodes.
*/

class Graph {
   private:
     list<int> *adjlist;
     int vertices;
   public:
    Graph (int vertices);
    void addEdge (int, int);
    void printGraph();
    bool isPath (int , int);
};


Graph::Graph (int vertices ) {
  this->vertices = vertices;
  adjlist = new list<int>[vertices];
}

void Graph::addEdge (int src , int dest ) {
  adjlist[src].push_back (dest);
  // adjlist[dest].push_back(src);
}

bool Graph::isPath ( int src , int dest )  {
  if (src == dest ) return true;
  vector<bool>visited (vertices , false);
  queue<int> q;
  visited[src] = true;
  q.push(src);
  while (!q.empty()) {
     src = q.front(); q.pop();
     for (auto i = adjlist[src].begin(); i != adjlist[src].end(); ++i ) {
        if (*i == dest) return true;
        if (!visited[*i]) {
           q.push(*i);
           visited[*i] = true;
        }
     }
  }
  return false;
}

void Graph::printGraph() {
  for (int i = 0; i < vertices; ++i ) {
    cout << "[" << i << "]" << "  ";
    for (auto iter = adjlist[i].begin(); iter != adjlist[i].end(); ++iter ){
      cout << *iter << " ";
    }
    cout << endl;
  }
}
int main() {
   cout << boolalpha << endl;
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    g.printGraph();
    cout << g.isPath (  0, 3) << endl;
}
