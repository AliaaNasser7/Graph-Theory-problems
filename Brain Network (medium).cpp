#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll nodes,edges;
ll vis[100000];
ll dist[100000];
vector<ll>adj[100000];
int bfs(ll n){
    vis[n]=1;
    queue<ll>q;
    q.push(n);
    ll crr;
    while(!q.empty()){
        crr=q.front();
        vis[crr]=1;
        q.pop();
        for(auto i:adj[crr]){
            if(!vis[i]){
                q.push(i);
                dist[i]=dist[crr]+1;
            }
        }
    }
    return crr;
}
int main() {
    fast
    cin>>nodes>>edges;
    for(int i =0 ; i < edges ;i++){
        ll u,v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll res = bfs(1);
    for(int i =0 ; i < nodes ; i++){
        vis[i]=0;
        dist[i]=0;
    }
    cout<<dist[bfs(res)]<<endl;
    return 0;
}
