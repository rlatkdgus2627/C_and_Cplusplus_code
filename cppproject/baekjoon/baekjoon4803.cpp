#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int>edge[501];
bool visited[501];
bool isTree;
int cnt;

void dfs(int cur, int prev){
    visited[cur] = true;
    for(int next : edge[cur]){
        if(visited[next] && next != prev)    isTree = false;
        if(!visited[next])  dfs(next,cur);
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int x, y, t = 1;
    while(1){
        cnt = 0;
        cin >> n >> m;
        if(!n&&!m)  break;
        for(int i=1;i<=n;i++){
            edge[i].clear();
            visited[i] = false;
        }
        for(int i=0;i<m;i++){
            cin >> x >> y;
            edge[x].push_back(y);
            edge[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            isTree = true;
            if(visited[i] == false){
                dfs(i,i);
                cnt += isTree;
            }
        }
        if(cnt > 1){
            cout << "Case " << t << ": " << "A forest of " << cnt << " trees.\n";
        }
        else if(cnt == 1){
            cout << "Case " << t << ": " << "There is one tree.\n";
        }
        else{
            cout << "Case " << t << ": " << "No trees.\n";
        }

        t++;
    }
    return 0;
}