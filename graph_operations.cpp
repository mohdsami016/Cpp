#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int> > adj;
public:
    Graph(int V) {
        this->V=V;
        adj.resize(V);
    }
    void addEdge(int u,int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void removeEdge(int u,int v) {
        for(int i=0;i<adj[u].size();i++) {
            if(adj[u][i]==v) { adj[u].erase(adj[u].begin()+i); break; }
        }
        for(int i=0;i<adj[v].size();i++) {
            if(adj[v][i]==u) { adj[v].erase(adj[v].begin()+i); break; }
        }
    }
    void display() {
        for(int i=0;i<V;i++) {
            cout<<i<<" -> ";
            for(int j=0;j<adj[i].size();j++) {
                cout<<adj[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    void BFS(int start) {
        vector<int> visited(V,0);
        queue<int> q;
        visited[start]=1; q.push(start);
        cout<<"BFS: ";
        while(!q.empty()) {
            int u=q.front(); q.pop();
            cout<<u<<" ";
            for(int j=0;j<adj[u].size();j++) {
                int v=adj[u][j];
                if(!visited[v]) {
                    visited[v]=1;
                    q.push(v);
                }
            }
        }
        cout<<"\n";
    }
    void DFSUtil(int u,vector<int>& visited) {
        visited[u]=1;
        cout<<u<<" ";
        for(int j=0;j<adj[u].size();j++) {
            int v=adj[u][j];
            if(!visited[v]) DFSUtil(v,visited);
        }
    }
    void DFS(int start) {
        vector<int> visited(V,0);
        cout<<"DFS: ";
        DFSUtil(start,visited);
        cout<<"\n";
    }
};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);

    cout<<"Adjacency List:\n";
    g.display();

    g.BFS(0);
    g.DFS(0);

    g.removeEdge(1,3);
    cout<<"\nAfter removing edge (1,3):\n";
    g.display();
}

