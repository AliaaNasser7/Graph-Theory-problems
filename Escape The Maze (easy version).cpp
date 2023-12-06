#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
ll rooms,freinds, flag=0;
ll vis[100000*2+1];
ll dist[100000*2+1];
void dfs(vector<vector<ll>>&adj,ll n = 1, ll curtime=0){
        vis[n]=1;
        if(curtime >= dist[n]) return;
        if(n!=1 && adj[n].size() == 1){
            flag = 1; return ;
        }
        for(auto i:adj[n]) {
            if(!vis[i])
                dfs(adj,i,curtime+1);
        }
    return ;
}
int main() {
    fast
    ll t=1; cin>>t;
    while(t--){
    memset(dist,-1,sizeof dist);
    memset(vis,0,sizeof vis);
    flag =0;
    cin>>rooms>>freinds;
    queue<ll>nodes;
    for(int i =0 ; i < freinds ;i++){
        ll x; cin>>x;
        nodes.push(x);
        dist[x] =0;
    }
    vector<vector<ll>> adj(rooms+1);
    for(int i =0 ; i < rooms-1 ; i++){
        ll u,v; cin>>u>>v;
        adj[v].pb(u);
        adj[u].pb(v);
    }
    while(!nodes.empty()){
        ll cur = nodes.front();
        nodes.pop();
        for(auto i: adj[cur]){
            if(dist[i] == -1)
            {
                nodes.push(i);
                dist[i] = dist[cur]+1;
            }
        }
    }
    dfs(adj);
    if(flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    }
    return 0;
}
