//
// Created by Maddie Woolley on 12/1/22.
//
//An attempt at reading in the adj matrix separate from the project file :)





#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    vector<list<int> > adj;
public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    void BFS(int s);
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
    // Mark all the vertices as not visited
    vector<bool> visited;
    visited.resize(V,false);

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout << s << " ";
        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If an adjacent has not been visited,
        // then mark it visited and enqueue it
        for (auto adjecent: adj[s])
        {
            if (!visited[adjecent])
            {
                visited[adjecent] = true;
                queue.push_back(adjecent);
            }
        }
    }
}

// Driver program to test methods of graph class


int main() {
    std::string line;
    std::ifstream infile("graph.txt");
    std::vector<std::vector<char> > forest;
    while (std::getline(infile, line)) {
        std::vector<char> row;
        for (char &c : line) {
            if (c != ',') {
                row.push_back(c);
            }
        }
        forest.push_back(row);
    }
    //printing
    Graph g(forest.size());
    cout<<"Adjacency Matrix: "<<endl;
    for (std::vector<char> &row : forest) {
        for (char &c : row) {
            std::cout << c << ' ';
        }
        std::cout << '\n';
    }
    //sending into the functions:
    for (int i=0; i<forest.size(); ++i){
        for (int j=1; j<forest[i].size(); ++j){
            g.addEdge(i,j);
        }
    }
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 1) \n";
    g.BFS(1);


    return 0;
}