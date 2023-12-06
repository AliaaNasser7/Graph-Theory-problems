#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll vis[202];
ll bug[202];
ll nodes, edges, flag=0;
vector<ll>adj[202];
void dfs(ll node){
    vis[node]=1;
    for(auto i:adj[node]){
        if(!vis[i]) {
            bug[i]= bug[node]^1;
            dfs(i);
        }
        else {
            if(bug[i] == bug[node])
                flag=1;
        }
    }
}
int main() {
    fast
    while(cin>>nodes&&nodes){
    cin >>edges;
    for(int i =0 ; i < edges ;i++){
        ll u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i =0 ; i < nodes ;i++){
            if(!vis[i]) dfs(i);
    }
    if(flag==0) cout<<"BICOLORABLE."<<endl;
    else cout<<"NOT BICOLORABLE."<<endl;
    flag=0;
    for(int i = 0; i < nodes ; i++){
        adj[i].clear();
        vis[i]=0;
        bug[i]=0;
    }
    }
    return 0;
}
