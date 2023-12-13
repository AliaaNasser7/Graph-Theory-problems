#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
vector<ll>cost(1e5+1,LLONG_MAX);
vector<ll>vis(1e5+1,0);
void dijkstra(vector<vector<vector<int>>> &adj , int maxWisdom, int node = 1){
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>next;
    next.push({0,node});
    cost[node] = 0;
    while (!next.empty()){
        int cur = next.top().second;
        next.pop();
        if(vis[cur]) continue;
        vis[cur] = 1;
        for (auto neighbour : adj[cur]) {
            int n = neighbour[0];
            int c = neighbour[1];
            int w = neighbour[2];
            if(w > maxWisdom) continue;
            if(cost[n] > cost[cur] + c){
                cost[n] = cost[cur] + c;
                next.push({cost[n],n});
            }
        }
    }
}
int main() {
    fast
    ll t=1; cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<vector<vector<int>>>adj(n+1);
        while(m--) {
            int s1,s2,c,w;
            cin>>s1>>s2>>c>>w;
            adj[s1].pb({s2,c,w});
            adj[s2].pb({s1,c,w});
        }
        ll l = 1, r = 1e9;
        ll minWisdom =-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            fill(cost.begin(),cost.end(),LLONG_MAX);
            fill(vis.begin(),vis.end(),0);
            dijkstra(adj,mid);
            ll curCost = cost[n];
            if(curCost >= k){
                l = mid + 1;
            }
            else{
                minWisdom = mid;
                r  = mid -1;
            }
        }
         cout<<minWisdom<<endl;
    }
    return 0;
}
