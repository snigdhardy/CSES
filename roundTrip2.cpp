#include <bits/stdc++.h>

using namespace std;

bool dfs(int node,vector<int>& vis,vector<int>& recStack,vector<int>& parent,vector<int> adj[],int& start,int& end){
    vis[node]=1;
    recStack[node]=1;
    for(int v:adj[node]){
        if(!vis[v]){
            parent[v]=node;
            if(dfs(v, vis, recStack,parent, adj,start,end)) return true;
        }else if(recStack[v]){
            start=v;
            end=node;
            return true;
        }
    }
    recStack[node]=0; // backtrack
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> vis(n+1,0);
    vector<int> parent(n+1,0);
    vector<int> recStack(n+1,0); // to keep track of the recursion stack
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    //find cycle in directed graph
    int start=-1,end=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i] && dfs(i,vis,recStack,parent,adj,start,end)) break;
    }
    if(start==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        vector<int> cycle;
        cycle.push_back(start);
        int current=end;
        while(current != start){
            cycle.push_back(current);
            current=parent[current];
        }
        cycle.push_back(start);
        reverse(cycle.begin(),cycle.end());
        cout<<cycle.size()<<endl;
        for(int node:cycle){
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}