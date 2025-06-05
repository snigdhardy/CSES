#include <bits/stdc++.h>

using namespace std;

void dfs(int node,int parent,vector<int> adj[],int dist[],int &farthest){
    for(auto child:adj[node]){
        if(child!=parent){
            dist[child]=dist[node]+1;
            if(dist[child]>dist[farthest]){
                farthest=child;
            }
            dfs(child,node,adj,dist,farthest);
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int dist[n+1]={0};
    int farthest=1;
    dfs(1,-1,adj,dist,farthest);
    memset(dist,0,sizeof(dist));
    int new_start=farthest;
    farthest=new_start;
    dfs(new_start,-1,adj,dist,farthest);
    cout<<dist[farthest]<<endl;
    return 0;
}