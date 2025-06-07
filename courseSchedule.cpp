#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int>indegree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    vector<int> topo;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0)
            q.push(i);
    }
    if(q.empty()){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(int neighbour:adj[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0)
                q.push(neighbour);
        }
    }
    if(topo.size() != n){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    for(int i=0;i<topo.size();i++){
        cout<<topo[i]<<" ";
    }
    
    return 0;
}