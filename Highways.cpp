#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll nodes,edges,start,endd;
ll vis[100000+1];
vector<ll>dist(100000+1,LLONG_MAX);
void dikstra(vector<vector<pair<ll,ll>>>&adj,ll n){
        dist[n]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
        q.push({0,n});
        while(!q.empty()){
            ll curr = q.top().second;
            q.pop();
            if(vis[curr]) continue;
            vis[curr] = true;
            for(auto i : adj[curr]){
                ll fir = i.first;
                ll cost = i.second;
                if(dist[fir] > dist[curr]+cost){
                    dist[fir] = dist[curr]+cost;
                    q.push({dist[fir],fir});
                }
            }
        }
    return ;
}
int main() {
    fast
    ll t=1; cin>>t;
    while(t--){
    memset(vis,0,sizeof vis);
    cin>>nodes>>edges>>start>>endd;
    vector<vector<pair<ll,ll>>> adj(nodes+1);
    for(int i =0 ; i < edges ;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dikstra(adj,start);
    if(dist[endd] == LLONG_MAX) cout<<"NONE"<<endl;
    else cout<<dist[endd]<<endl;

    for(int i = 0 ; i < 1e5 ; i++){
        dist[i] = LLONG_MAX;
    }
    }
    return 0;
}
