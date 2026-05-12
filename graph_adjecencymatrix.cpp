#include<iostream>
using namespace std;

class Graph {
    int V;
    int adj[10][10];
public:
    Graph(int V) {
        this->V=V;
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                adj[i][j]=0;
    }
    void addEdge(int u,int v) {
        adj[u][v]=1;
        adj[v][u]=1;
    }
    void display() {
        for(int i=0;i<V;i++) {
            for(int j=0;j<V;j++)
                cout<<adj[i][j]<<" ";
            cout<<"\n";
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(3,4);
    cout<<"Adjacency Matrix:\n";
    g.display();
}

