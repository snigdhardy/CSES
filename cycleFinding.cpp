#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<tuple<int,int,long long>> edges;
    for(int i=0;i<m;i++){
        int a,b;
        long long c;
        cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }
    vector<long long> dist(n+1,0);
    vector<int>parent(n+1,-1);
    dist[1]=0;
    int x=-1;
    for(int i=1;i<=n;i++){
        x=-1;
        for(auto [u,v,weight]:edges){
            if(dist[u]+weight<dist[v]){
                dist[v]=dist[u]+weight;
                parent[v]=u;
                x=v;
            }
        }
    }
    if(x==-1){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0; i<n; i++){
        x = parent[x];
    }

    vector<int> cycle;
    int curr = x;
    do {
        cycle.push_back(curr);
        curr = parent[curr];
    } while(curr != x);
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end());

    cout << "YES" << endl;
    for(int node : cycle){
        cout << node << " ";
    }
    cout << endl;

    return 0;

}