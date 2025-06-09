#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,long long>> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b;
        long long x;
        cin>>a>>b>>x;
        adj[a].push_back({b,x});
    }
    //negative score also exists,if cycle print -1:
    vector<long long> dist(n+1,LLONG_MIN);
    dist[1]=0;
    for(int i=1;i<n;i++){
        for(int u=1;u<=n;u++){
            if(dist[u]==LLONG_MIN) continue;
            for(auto edge:adj[u]){
                int v=edge.first;
                long long weight=edge.second;
                if(dist[u]!=LLONG_MIN && dist[u]+weight>dist[v]){
                    dist[v]=dist[u]+weight;
                }
            }
        }
    }
    vector<bool> inPositiveCycle(n+1,false);
    for(int u=1;u<=n;u++){
        if(dist[u]==LLONG_MIN) continue;
        for(auto &edge:adj[u]){
            int v=edge.first;
            long long w=edge.second;
            if(dist[u]+w>dist[v]){
                inPositiveCycle[v]=true;
            }
        }
    }
    queue<int> q;
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;i++){
        if(inPositiveCycle[i]){
            q.push(i);
            visited[i]=true;
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &edge:adj[u]){
            int v=edge.first;
            if(!visited[v]){
                visited[v]=true;
                q.push(v);
            }
        }
    }
    if(visited[n]){
        cout<<"-1"<<endl;
        return 0;
    }
    if(dist[n]==LLONG_MIN){
        cout<<"-1"<<endl;
    }else{
        cout<<dist[n]<<endl;
    }
    return 0;
}