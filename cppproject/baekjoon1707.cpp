#include <bits/stdc++.h>

using namespace std;

vector<int>graph[20001];
int visited[20001];

int t,v,e;

bool ans;

void dfs(int x,int color){
    visited[x] = color;
    for(int next : graph[x]){
        if(visited[next] == color){
            ans = false;
        }
        else if(!visited[next] && color == 1){
            dfs(next, 2);
        }
        else if(!visited[next] && color == 2){
            dfs(next, 1);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> t;
    while(t--){
        cin >> v >> e;
        ans = true;
        for(int i=1;i<=v;i++){
            graph[i].clear();
            visited[i]=0;
        }
        for(int i=0;i<e;i++){
            int x,y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        for(int i=1;i<=v;i++){
            if(!visited[i]) dfs(i,1);
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}