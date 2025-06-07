#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    vector<int> indegree(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(int neighbor : adj[node]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    vector<int> dp(n+1,0);
    dp[1]=1;
    for(int u:topo){
        for(int v:adj[u]){
            dp[v]=(dp[v]+dp[u])%MOD;
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}