//
// Created by Maddie Woolley on 11/30/22.
//
// C++ program to print DFS traversal from
// a given vertex in a  given graph
#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
using namespace std;

// Graph class represents a directed graph
// using adjacency list representation
class Graph {
public:
    map<int, bool> visited;
    map<int, list<int> > adj;

    // function to add an edge to graph
    void addEdge(int v, int w);

    // DFS traversal of the vertices
    // reachable from v
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::DFS(int v)
{
    // Mark the current node as visited and
    // print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all the vertices adjacent
    // to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i);
}

// Driver's code
int main()
{
    std::string line;
    std::ifstream infile("graph.txt");
    std::vector<std::vector<char> > forest;
    int count = 0;
    while (std::getline(infile, line)) {
        std::vector<char> row;
        ++count;
        for (char &c : line) {
            if (c != ',') {
                row.push_back(c);
            }
        }
        forest.push_back(row);
    }
    //printing
    for (std::vector<char> &row : forest) {
        for (char &c : row) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
    // Create a graph given in the above diagram
    Graph g;
    for (int i=0; i<forest.size(); ++i){
        for (int j=1; j<forest[i].size(); ++j){
            g.addEdge(i,j);
        }
    }

    cout << "Following is Depth First Traversal"
            " (starting from vertex 1) \n";

    // Function call
    g.DFS(1);

    return 0;
}