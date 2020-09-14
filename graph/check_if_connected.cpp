#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<int> *l;
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs(int node, bool visited[]){
        // mark it as visited
        visited[node] = true;
        // cout<<node<<" ";

        for(auto nbr: l[node]){
            if(!visited[nbr]){
                dfs(nbr, visited);
            }
        }
    }

    bool isConnected(){
        bool visited[V];

        for(int i=0; i<V; i++){
            visited[i] = false;
        }
        int count=0;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                count++; // stores the count of the number of times dfs is called. ( if called only once that means graph is fully connected else not fully connected)
                dfs(i, visited);
            }
        }

        if(count==1){
            return true;
        }
        return false;
    }
    
};


int main()
{
    // Graph g(7); // 5 vertices numbered from 0 to 4 
    // g.addEdge(0, 1); 
    // g.addEdge(2, 3); 
    // g.addEdge(4, 5); 
    // g.addEdge(5, 6); 
    // g.addEdge(4, 6);

    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3);  
  
    if(g.isConnected()){
        cout<<"Connected";
    }
    else{
        cout<<"Not Connected";
    }
     

    return 0;
}
