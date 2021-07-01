#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> >graph[100001];

int n,m;
int depth[100001];
int table[100001][21];
int mintable[100001][21];
int maxtable[100001][21];
bool visited[100001];

void dfs(int cur, int d){
    visited[cur] = true;
    depth[cur] = d;
    for(auto next:graph[cur]){
        if(!visited[next.first]){
            table[next.first][0] = cur;
            mintable[next.first][0] = next.second;
            maxtable[next.first][0] = next.second;
            dfs(next.first,d+1);
        }
    }
}

void getTable(){
    for(int j = 1; j <= 20; j++){
        for(int i = 1; i <= n; i++){
            table[i][j] = table[table[i][j-1]][j-1];
            mintable[i][j] = min(mintable[i][j-1], mintable[table[i][j-1]][j-1]);
            maxtable[i][j] = max(maxtable[i][j-1], maxtable[table[i][j-1]][j-1]);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int x, y, dist,temp, minans, maxans;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 20; j++){
            mintable[i][j] = 1e9;
        }
    }

    for(int i = 0; i < n-1; i++){
        cin >> x >> y >> dist;
        graph[x].push_back(make_pair(y,dist));
        graph[y].push_back(make_pair(x,dist));
    }

    dfs(1,0);
    getTable();

    cin >> m;

    for(int i = 0; i < m; i++){
        minans = 1e9;
        maxans = 0;
        cin >> x >> y;
        if(depth[x] < depth[y]){
            temp = x;
            x = y;
            y = temp;
        }
        for(int j = 20; j>= 0; j--){
            if(depth[x] - depth[y] >= (1<<j)){
                minans = min(minans, mintable[x][j]);
                maxans = max(maxans, maxtable[x][j]);
                x = table[x][j];
            }

        }
        if(x != y){
            for(int j = 20; j>= 0; j--){
                if(table[x][j] != table[y][j]){
                    if(table[x][j] != table[y][j]){
                        minans = min(minans, min(mintable[x][j], mintable[y][j]));
                        maxans = max(maxans, max(maxtable[x][j], maxtable[y][j]));
                        x = table[x][j];
                        y = table[y][j];
                    }
                }
            }
            minans = min(minans, min(mintable[x][0], mintable[y][0]));
            maxans = max(maxans, max(maxtable[x][0], maxtable[y][0]));
        }
        cout << minans << " " << maxans << "\n";
    }
}