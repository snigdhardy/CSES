#include <bits/stdc++.h>

using namespace std;

void dfs(int node,int col,vector<int> adj[],vector<int>& color,bool &possible){
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==0){
            dfs(it,3-col,adj,color,possible);
        }  
        else if(color[it]==col){
            possible=false;
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
    vector<int> color(n+1,0);
    bool possible=true;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            dfs(i,1,adj,color,possible);
        }
    }
    if(possible){
        for(int i=1;i<=n;i++){
            cout<<color[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}