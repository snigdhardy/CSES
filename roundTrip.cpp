#include <bits/stdc++.h>

using namespace std;

bool cycleFound = false;
int startNode = -1, endNode = -1;
void dfs(int node,vector<int>& parent,vector<int> adj[],vector<int>& vis){
    vis[node]=1;
    for(auto it:adj[node]){
        if(vis[it]==0){
            parent[it]=node;
            dfs(it,parent,adj,vis);
            if(cycleFound) return; // Stop if cycle is found
        }else if(it!=parent[node]){
            //found a cycle
            startNode=node;
            endNode=it;
            cycleFound=true;
            return;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //we need to find a cycle in the graph
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,-1);
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,parent,adj,vis);
            if(cycleFound) break; // Stop if cycle is found
        }
    }
    if(!cycleFound){
        cout<<"IMPOSSIBLE";
    }else{
        vector<int> cycle;
        cycle.push_back(endNode);
        for(int v=startNode;v!=endNode;v=parent[v]){
            cycle.push_back(v);
        }
        cycle.push_back(endNode);
        reverse(cycle.begin(), cycle.end());
        cout<<cycle.size()<<"\n";
        for(int i=0;i<cycle.size();i++){
            cout<<cycle[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}