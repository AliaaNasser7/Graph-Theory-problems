#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
int dx[] = {0,0 , -1 , 1};
int dy[] = {-1,1 , 0 , 0};
ll arr[1000+1][1000+1];
ll dist[1000+1][1000+1];
ll vis[1000+1][1000+1];
ll col, row;
void bfs(ll n , ll m){
    vis[n][m]=1;
    dist[n][m]=0;
    queue<ll>q;
    q.push(n); q.push(m);
    while(!q.empty()){
        ll x= q.front();
        q.pop();
        ll y = q.front();
        q.pop();
        for(int i = 0 ;i  < 4 ; i++){
            ll ux = x+dx[i];
            ll uy = y+dy[i];
            if(ux>=0 && ux < row && uy >= 0 && uy < col && arr[ux][uy] == 0 && vis[ux][uy] == 0){
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
    while(cin>>row>>col&&col&&row){
        ll n; cin>>n;
        while(n--){
            ll x,y,z;
            cin>>x>>y;
            while(y--){
                cin>>z;
                arr[x][z]=1;
            }
        }
        ll st1, en1,st2,en2;
        cin>>st1>>en1;
        bfs(st1,en1);
        cin>>st2>>en2;
        cout<<dist[st2][en2]<<endl;
        memset(vis,0,sizeof vis);
        memset(dist,0,sizeof dist);
        memset(arr,0,sizeof arr);
    }
    return 0;
}
