#include <bits/stdc++.h>

using namespace std;

void dfs(int node,vector<int> &subordinates,vector<int> adj[]){
    for(auto child:adj[node]){
        dfs(child,subordinates,adj);
        subordinates[node]+=subordinates[child]+1;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> bosses(n-1,0);
    for(int i=0;i<n-1;i++){
        cin>>bosses[i];
    }
    vector<int> adj[n+1];
    for(int i=0;i<n-1;i++){
        adj[bosses[i]].push_back(i+2);
    }
    vector<int> subordinates(n+1,0);
    dfs(1,subordinates,adj);
    for(int i=1;i<=n;i++){
        cout<<subordinates[i]<<" ";
    }
    return 0;
}