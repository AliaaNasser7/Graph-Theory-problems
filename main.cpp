#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
#define po                 pop_back
int dx[] = {-1,0 , 1 , 0};
int dy[] = {0,1 , 0 , -1};
char arr[501][501];
ll n,m,k;
ll vis[501][501];
bool valid(ll x, ll y){
    return (x>=0&&x<n&&y>=0&&y<m&&arr[x][y] != '#');
}
void dfs(ll s1, ll s2){
    vis[s1][s2]=1;
    for(int i = 0; i < 4 ; i++){
        int l = s1+dx[i];
        int r = s2+dy[i];
        if(valid(l,r) &&!vis[l][r]) {
            dfs(l,r);
        }
    }
    if(k){
        arr[s1][s2]= 'X';
        k--;
    }
}
int main() {
    fast
    cin>>n>>m>>k;
    ll start1=-1,start2=-1;
    for(int i =0 ; i < n ;i++){
        for(int j =0 ; j < m ;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='.' && start1==-1 && start2==-1){
                    start1=i;
                    start2=j;
                }
        }
    }
    dfs(start1,start2);
    for(int i =0 ; i < n ;i++){
        for(int j =0 ; j < m ;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}
