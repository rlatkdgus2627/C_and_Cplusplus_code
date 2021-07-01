#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int> >graph[100001];

int n,m;
int depth[100001];
int table[100001][21];
long long dist[100001];

bool visited[100001];

void dfs(int cur, int d,long long l){
    visited[cur] = true;
    depth[cur] = d;
    dist[cur] = l;
    for(auto next:graph[cur]){
        if(!visited[next.first]){
            table[next.first][0] = cur;
            dfs(next.first, d+1, l+next.second);
        }
    }
}

void getTable(){
    for(int j = 1; j <= 20; j++){
        for(int i = 1; i <= n; i++){
            table[i][j] = table[table[i][j-1]][j-1];
        }
    }
}

int getLCA(int x, int y){
    int temp;
    if(depth[x] < depth[y]){
        temp = x;
        x = y;
        y = temp;
    }
    for(int j = 20 ; j >= 0; j--){
        if(depth[x] - depth[y] >= (1 << j)){
            x = table[x][j];
        }
    }
    if(x == y)  return x;
    
    for(int j = 20; j >= 0; j--){
        if(table[x][j] != table[y][j]){
            x = table[x][j];
            y = table[y][j];
        }
    }
    return table[x][0];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int x, y, k, query, d, lca;
    long long ans;

    for(int i = 0; i < n-1; i++){
        cin >> x >> y >> d;
        graph[x].push_back(make_pair(y,d));
        graph[y].push_back(make_pair(x,d));
    }

    dfs(1,0,0);
    getTable();

    cin >> m;

    for(int i = 0; i < m; i++){
        cin >> query;
        if(query == 1){
            cin >> x >> y;
            lca = getLCA(x,y);
            cout << dist[x] + dist[y] - 2LL*dist[lca] << "\n";
        }
        else{
            cin >> x >> y >> k;
            lca = getLCA(x,y);
            if(depth[x] - depth[lca] >= k - 1){
                k--;
                for(int j = 20; j >= 0; j--){
                    if(k >= (1 << j)){
                        x = table[x][j];
                        k -= (1 << j);
                    }
                }
                cout << x << "\n";
            }
            else{
                k = depth[x] + depth[y] - 2*depth[lca] + 1 - k;
                for(int j = 20; j >= 0; j--){
                    if(k >= (1 << j)){
                        y = table[y][j];
                        k -= (1 << j);
                    }
                }
                cout << y << "\n";
            }
        }
    }
}