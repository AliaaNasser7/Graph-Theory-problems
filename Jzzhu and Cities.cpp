#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
vector<ll>dist(2e5+1,LLONG_MAX);
vector<ll>vis(2e5+1,0);
void dijkstra(vector<vector<pair<int,int>>> &roads , vector<vector<pair<int,int>>> &routes, ll node = 1){
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>next;
    next.push({0,node});
    dist[node] = 0;
    while (!next.empty()){
        int cur = next.top().second;
        next.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for (auto neighbour : roads[cur]) {
            ll n = neighbour.first;
            ll c = neighbour.second;
            if(dist[n] > dist[cur] + c){
                dist[n] = dist[cur] + c;
                next.push({dist[n],n});
            }
        }

        for (auto neighbour : routes[cur]) {
            ll n = neighbour.first;
            ll c = neighbour.second;
            if(dist[n] > dist[cur] + c){
                dist[n] = dist[cur] + c;
                next.push({dist[n],n});
            }
        }
    }
}
int main() {
    fast
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<pair<int,int>>>roads(n+1), routes(n+1);
        while(m--) {
            ll u,v,x;
            cin>>u>>v>>x;
            roads[u].pb({v,x});
            roads[v].pb({u,x});
        }
        for(int i =0 ; i < k ;i++) {
            ll v,x;
            cin>>v>>x;
            routes[1].pb({v,x});
            routes[v].pb({1,x});
        }
        dijkstra(roads,routes);
        vector<bool>reachedByRoad(n+1),reachedByRoute(n+1);
        for(int i = 1 ; i <= n ; i++){ //cities
            for(auto edge : roads[i]){
                int node = edge.first;
                int cost = edge.second;
                if(dist[node]+cost == dist[i])
                    reachedByRoad[i] = true;
            }
        }

        for(int i = 1 ; i <= n ; i++){ //cities
            for(auto edge : routes[i]){
                int node = edge.first;
                int cost = edge.second;
                if(dist[node]+cost == dist[i])
                    reachedByRoute[i] = true;
            }
        }
        int trains = 0;
        for(int i = 1 ; i <= n ; i++){ //citties
            if(reachedByRoute[i] && !reachedByRoad[i])
                trains++;
        }
         cout<<k - trains<<endl;
    return 0;
}
