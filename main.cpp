#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
int dx[] = {0,0 , -1 , 1};
int dy[] = {-1,1 , 0 , 0};
char arr[51][51];
int vis[51][51];
int n,m;
void dfs(int x , int y){
    vis[x][y]=1;
    for(int i = 0; i < 4 ; i++){
        int b1 = x + dx[i];
        int b2 = y + dy[i];
        if(b1>= 0 && b2 >= 0 && b1 < n && b2 < m && !vis[b1][b2] && arr[b1][b2] != '#'){
            dfs(b1,b2);
        }
    }
}
int main() {
    fast
    ll t=1; cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++)
                cin>>arr[i][j];
            }
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
            	vis[i][j] = 0;
                if(arr[i][j] == 'B'){
                    for(int k = 0; k < 4 ; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x >= 0 && y >= 0 && x < n && y < m && arr[x][y] =='.') arr[x][y] = '#';
                    }
                }
            }
        }
        if(arr[n-1][m-1] != '#') dfs(n-1,m-1);
        int flag = 0;
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m ; j++){
                if((vis[i][j] && arr[i][j] == 'B') || (!vis[i][j] && arr[i][j] == 'G')) flag = 1;
            }
        }
        if(flag) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}
