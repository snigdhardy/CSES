#include <bits/stdc++.h>

using namespace std;

class DSU{
     vector<int> parent,size;

public:
    int components;
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        components=n;
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
  
    }
    int find(int u){
        if(parent[u]!=u)
            parent[u]=find(parent[u]);
        return parent[u];
    }
    void unite(int a,int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(size[a]<size[b]) swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
        components--;
    }
    int getSize(int u){
        return size[find(u)];
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    priority_queue<int> pq;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        dsu.unite(u,v);
        pq.push(dsu.getSize(u));
        cout<<dsu.components<<" "<<pq.top()<<endl;
    }
    return 0;
}