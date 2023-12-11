#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
ll n,m,flag=0;
vector<ll>dist(2e4+2,-1);
int bfs(int n , int m){
    queue<ll>q;
    q.push(n);
    dist[n] = 0;
    while(!q.empty()){
        ll cur = q.front();
        q.pop();
        if(cur== m){return dist[cur];}
        ll node1 = cur*2, node2 = cur-1;
        if(node1<=2e4+1&&dist[node1] == -1){
            q.push(node1);
            dist[node1] = dist[cur]+1;
        }
        if(node2>0&&dist[node2] == -1){
            q.push(node2);
            dist[node2] = dist[cur]+1;
        }
    }
}
int main() {
    fast
    cin>>n>>m;
    cout<<bfs(n,m);
    return 0;
}
