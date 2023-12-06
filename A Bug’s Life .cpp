#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll vis[2002];
ll bug[2002];
ll nodes, edges,cnt, flag=0;
vector<ll>adj[2002];
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
    ll t=1; cin>>t;
    while(t--){
    cnt++;
    cin >> nodes>>edges;
    for(int i =0 ; i < edges ;i++){
        ll u,v; cin>>u>>v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i =0 ; i < nodes ;i++){
            if(!vis[i]) dfs(i);
    }
    if(flag==0) cout<<"Scenario #"<<cnt<<":"<<endl<<"No suspicious bugs found!"<<endl;
    else cout<<"Scenario #"<<cnt<<":"<<endl<<"Suspicious bugs found!"<<endl;
    flag=0;
    for(int i = 0; i < nodes ; i++){
        adj[i].clear();
        vis[i]=0;
        bug[i]=0;
    }
    }
    return 0;
}
