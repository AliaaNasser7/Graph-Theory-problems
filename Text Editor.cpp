#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
int dx[] = {0,0 , -1 , 1};
int dy[] = {-1,1 , 0 , 0};
ll arr[102];
ll dist[102][100000+1];
ll vis[102][100000+1];
ll num,st2,en2;
void bfs(ll n , ll m){
    dist[n][m]=0;
    queue<ll>q;
    q.push(n); q.push(m);
    while(!q.empty()){
        vis[n][m]=1;
        ll x= q.front();
        q.pop();
        ll y = q.front();
        q.pop();
        for(int i = 0 ;i  < 4 ; i++){
            ll ux = x+dx[i];
            ll uy = y+dy[i];
            if(uy > arr[ux]+1) uy = arr[ux]+1;
            if (ux >= 1 && ux <= num && uy >= 1 && uy <= arr[ux] + 1 && !vis[ux][uy]){
                vis[ux][uy] =1;
                dist[ux][uy] = dist[x][y]+1;
                q.push(ux);
                q.push(uy);
            }
        }
    }
}
int main() {
    fast
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
        cin>>num;
        memset(dist,1e9,sizeof dist);
        for(int i = 1; i <= num ; i++){
            cin>>arr[i];
        }
        ll st1, en1;
        cin>>st1>>en1;
        bfs(st1,en1);
        cin>>st2>>en2;
        cout<<dist[st2][en2];
    return 0;
}
