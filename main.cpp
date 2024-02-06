#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define fast       ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl               "\n"
#define pb                 push_back
int dx[] = {0,0 , -1 , 1};
int dy[] = {-1,1 , 0 , 0};
int n , m , cnt = 0;
char cont[22][22] , c;
int vis[22][22];

int fix(int y){
    if(y < 0) return m-1;
    if(y >= m) return 0;
    return y;
}

bool valid(int x) {
    return x >= 0 && x < n;
}

void flood(int x  ,int y){
    vis[x][y] = 1;
    cnt++;
    for(int i =0 ;i < 4 ; i++){
        int tox = dx[i] + x;
        int toy = fix(dy[i] + y);
        if(valid(tox) && !vis[tox][toy] && cont[tox][toy] == c)
            flood(tox , toy);
    }
}
int main() {
    fast
        while(cin >> n >> m){

            memset(vis,0,sizeof vis);

            for(int i = 0 ;i < n ;i++){
                for(int j = 0 ;j < m ;j++){
                    cin >> cont[i][j];
                }
            }

            int x , y;
            cin >> x >> y;
            c = cont[x][y];
            flood(x , y);
            int res = 0;

            for(int i = 0 ;i < n ;i++){
                for(int j = 0 ;j < m ;j++){
                    if(!vis[i][j] && cont[i][j] == c){
                        cnt = 0;
                        flood(i , j);
                        res = max(res, cnt);
                    }
                }
            }

            cout<< res <<endl;

        }
    return 0;
}
