#include<bits/stdc++.h>
using namespace std;

class Graph{
  int N;
  list<int> *adj;
  public:
  Graph(int n){
    N=n;
    adj=new list<int>[n];
  }
  void addEdge(int x,int y){
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  void BFS(int source){

    queue<pair<int,int> > q;
    q.push(make_pair(source,0));

    vector<int> visited(N,0);
    visited[source]=1;

    while(!q.empty()){
      int node=q.front().first;
      int level=q.front().second;
      if(node!=source){
        cout<<"Distance of node "<<node<<" from source node "<<source<<" is equal to :"<<level<<"\n";
      }
      q.pop();
      //explore all neighbours
      list<int> :: iterator it;
      for(it=adj[node].begin();it!=adj[node].end();it++){
        if(visited[*it]==0){
          visited[*it]=1;
          q.push(make_pair(*it,level+1));
        }
      }
    }
  }
};
int main(){

  cout<<"Enter number of nodes in graph\n";
  int nodes;cin>>nodes;
  Graph g(nodes);

  cout<<"Enter the edges\n";
  int edges;cin>>edges;

  for(int i=0;i<edges;i++){
    int u,v;cin>>u>>v;
    g.addEdge(u-1,v-1);
  }

  cout<<"Enter the source\n";
  int source;cin>>source;

  g.BFS(source-1);
  return 0;
}
