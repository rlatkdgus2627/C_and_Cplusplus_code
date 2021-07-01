#include <bits/stdc++.h>

using namespace std;

vector<int>graph[100001];

int n, m;

int depth[100001];
int table[100001][21];
bool visited[100001];

void dfs(int cur, int d){
    visited[cur] = true;
    depth[cur] = d;
    for(int next : graph[cur]){
        if(!visited[next]){
            table[next][0] = cur;
            //cout << "table[" << next << "][0]: " << table[next][0] << endl;
            dfs(next,d+1);
        }
    }
}

void getTable(){
    for(int j = 1; j <= 20 ; j++){
        for(int i = 1; i <= n; i++){
            table[i][j] = table[table[i][j-1]][j-1];
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    int x, y, temp, diff, p;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    dfs(1,0);
    getTable();
    /*
    for(int j = 0; j <= 20 ; j++){
        for(int i = 1; i <= n; i++){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    */
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        if(depth[x] < depth[y]){
            temp = x;
            x = y;
            y = temp;
        }
        for (int j = 20; j >= 0; j--) {
            if (depth[x] - depth[y] >= (1 << j)) 
                x = table[x][j];
        }

        if(x == y){
            cout << x << "\n";
            continue;
        }
        else{
            for(int j = 20 ; j >= 0 ; j--){
                if(table[x][j] != table[y][j]){
                    x = table[x][j];
                    y = table[y][j];
                }
            }

            cout << table[x][0] << "\n";
        }
    }
}