#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<pair<int,int>> adj[n+1];
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,LLONG_MAX));
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(auto it:adj[i]){
            dist[i][it.first]=min(dist[i][it.first],1LL*it.second);
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][k]!=LLONG_MAX && dist[k][j]!=LLONG_MAX){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    while(q--){
        int a,b;
        cin>>a>>b;
        if(dist[a][b]==LLONG_MAX){
            cout<<"-1\n";
        }else{
            cout<<dist[a][b]<<"\n";
        }
    }
    return 0;
}

