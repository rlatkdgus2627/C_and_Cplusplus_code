#include <bits/stdc++.h>

using namespace std;

int t;
int n, m;
vector<int> graph[100001];
vector<vector<int> > SCC;
int visited[100001], conscc[100001], indegree[100001], id, ans;
bool finished[100001];
stack<int> S;

int dfs(int cur){
    visited[cur] = ++id;
    S.push(cur);

    int parent = visited[cur];

    for(int next : graph[cur]){
        if(!visited[next]){
            parent = min(parent, dfs(next));
        }
        else if(!finished[next]){
            parent = min(parent, visited[next]);
        }
    }

    if(parent == visited[cur]){
        vector<int> newSCC;
        while(1){
            int p = S.top();
            S.pop();
            finished[p] = true;
            newSCC.push_back(p);
            conscc[p] = SCC.size()+1;
            if(p == cur){
                break;
            }
        }
        SCC.push_back(newSCC);
    }
    return parent;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i <= n; i++){
            graph[i].clear();
            conscc[i] = visited[i] = indegree[i] = 0;
            finished[i] = false;
        }
        SCC.clear();
        id = 0;
        ans = 0;
        int x, y;
        for(int i = 0; i < m; i++){
            cin >> x >> y;
            graph[x].push_back(y);
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]) dfs(i);
        }

        for(int i = 1; i <= n; i++){
            for(int next : graph[i]){
                if(conscc[i] != conscc[next])   indegree[conscc[next]]++;
            }
        }

        for(int i = 1; i <= SCC.size(); i++){
            if(!indegree[i])    ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}