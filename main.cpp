#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll vis[10000*2];
ll nodes, edges, cnt=0;
vector<ll>adj[10000*2];
void dfs(ll node){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]) dfs(i);
    }
}
int main() {
    fast
    cin >> nodes>>edges;
    if(nodes-1!=edges){
        cout<<"NO";
        return 0;
    }
    for(int i =0 ; i < edges ;i++){
        ll u,v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i =0 ; i < nodes ;i++){
            if(!vis[i]){
                dfs(i); cnt++;
            }
    }
    if(cnt==1) cout<<"YES";
    else cout<<"NO";
    return 0;
}
