#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    // array of list
    list<int> *l; // pointer to list
public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V]; // we assign the new list to the pointer l
    }
    void addEdge(int x, int y){ // assuming all are bi-directional
        l[x].push_back(y);  // push both vertices into each other's list
        l[y].push_back(x);
    }

    void printAdjList(){
        // iterate over all the vertices
        for(int i=0; i<V; i++){
            cout<<"Vertex "<<i<<"-> ";
            for(auto x: l[i]){  // x store the element of list 
                cout<<x<<" ";   // and print x.
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,1); // all are bidirectional edges
    g.addEdge(0,2);   
    g.addEdge(2,3);   
    g.addEdge(1,2);
    g.printAdjList();   
    return 0;
}