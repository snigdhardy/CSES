#include <bits/stdc++.h>

using namespace std;
using ll=long long;

ll solve(vector<ll>& a,ll x,ll n){
    map<ll,ll> prefSums;
    prefSums[0]=1;
    ll pref=0;
    ll cnt=0;
    for(ll i=0;i<n;i++){
        pref+=a[i];
        cnt+=prefSums[pref-x];
        prefSums[pref]++;
    }
    return cnt;
}
int main(){
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,x,n)<<endl;


    
    
    
    return 0;
}