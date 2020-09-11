#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
    // no. of vertices
    int V;

    // pointer to an array containing adjacency list
    list<int> *l;

public:
    // constructor
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    // function to add edge 
    void addEdge(int x, int y){
        l[x].push_back(y);  // directed acylic graph
    }

    // A utility function used by topological sort
    void topologicalSortUtil(int node, bool visited[], stack<int> &Stack){
        // mark it as visited
        visited[node] = true;

        for(auto nbr: l[node]){
            if(!visited[nbr]){
                topologicalSortUtil(nbr, visited, Stack);    
            }
        }

        Stack.push(node);   
    }

    void topologicalSort(){
        // we push our nodes in stack and then print the stack as our answer
        stack<int> Stack;

        // boolean array to mark nodes visited/not visited
        bool visited[V];

        // Mark all the vertices as not visited
        for(int i=0; i<V; i++){
            visited[i] = false;
        }

        for(int i=0; i<V; i++){
            if(visited[i] == false){
                topologicalSortUtil(i, visited, Stack);
            }
        }

        // print the topological sort
        while(!Stack.empty()){
            cout<<Stack.top()<<" ";
            Stack.pop();    
        }
    }

};

int main()
{
    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
    cout << "Following is a Topological Sort of the given graph \n"; 
    g.topologicalSort(); 

    return 0;
}
