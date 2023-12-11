#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll nodes,edges, flag=0;
ll vis[100000*2+1];
vector<ll>dist(100000*2+1,LLONG_MAX);
vector<ll>pre(100000*2+1,0);

void print(vector<ll>&pre, ll n){
    if(pre[n] == n){
        cout<<n<<" ";
        return;
    }
    print(pre,pre[n]);
    cout<<n<< " ";
}
void dikstra(vector<vector<pair<ll,ll>>>&adj,ll n = 1){
        dist[n]=0;
        pre[n] = n;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
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
                    pre[fir] = curr;
                    q.push({dist[fir],fir});
                }
            }
        }

    return ;
}
int main() {
    fast
    cin>>nodes>>edges;
    vector<vector<pair<ll,ll>>> adj(nodes+1);
    for(int i =0 ; i < edges ;i++){
        ll u,v,w; cin>>u>>v>>w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }
    dikstra(adj,1);
    if(pre[nodes] == 0) cout<<-1;
    else print(pre,nodes);
    return 0;
}
