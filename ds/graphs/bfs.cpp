#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
    public:
    Graph(int V);
    void addEdge(int u,int v);
    void bfs(int s); // s : source
};

Graph::Graph(int V){
    this->V=V;
    this->adj=new list<int>[V];
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::bfs(int s){
    vector<int> visited(V,false);
    visited[s]=true;
    queue<int> q;
    q.push(s);
    list<int>::iterator it;
    while(!q.empty()){
        int temp = q.front();
        cout<<temp<<" ";
        q.pop();
        for(it=adj[temp].begin();it!=adj[temp].end();++it){
            if(!visited[*it]){
                visited[*it]=true;
                q.push(*it);
            }
        }
    }
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.bfs(2);
 
    return 0;
}