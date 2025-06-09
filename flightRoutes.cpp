#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,long long>> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        long long w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
    }
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;
    priority_queue<long long> best[n+1];
    pq.push({0,1});
    best[1].push(0);
    while(!pq.empty()){
        auto a=pq.top();
        pq.pop();
        if(a.first > best[a.second].top()) continue;
        for(auto &i:adj[a.second]){
            long long tmp=a.first+i.second;
            if(best[i.first].size()<k){
                best[i.first].push(tmp);
                pq.push({tmp,i.first});
            }else if(tmp<best[i.first].top()){
                best[i.first].pop();
                best[i.first].push(tmp);
                pq.push({tmp,i.first});
            }
        }
    }
    vector<long long> ans;
    while(!best[n].empty()){
        ans.push_back(best[n].top());
        best[n].pop();
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}