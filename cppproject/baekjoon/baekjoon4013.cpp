#include <bits/stdc++.h>

using namespace std;

int n, m, s, p;
vector<int> graph[500001];
vector<int> newgraph[500001];
vector<vector<int> > SCC;
int visited[500001], conscc[500001], cost[500001], costsum[500001], dp[500001],  id, ans;
bool finished[500001];

queue<int> Q;

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
            costsum[SCC.size()+1] += cost[p];
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
    
    cin >> n >> m;

    vector<int> restaurant;
    
    int x, y;
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for(int i = 1; i <= n; i++){
        cin >> cost[i];
    }

    cin >> s >> p;
    for(int i = 0; i < p; i++){
        cin >> x;
        restaurant.push_back(x);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]) dfs(i);
    }

    for(int i = 1; i <= n; i++){
        for(int next : graph[i]){
            if(conscc[i] != conscc[next]){
                newgraph[conscc[i]].push_back(conscc[next]);
            }
        }
    }

    Q.push(conscc[s]);
    dp[conscc[s]] = costsum[conscc[s]];

    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        for(int next : newgraph[cur]){
            if(dp[next]< dp[cur] + costsum[next]){
                dp[next] = dp[cur] + costsum[next];
                Q.push(next);
            }
        }
    }


    for(int location : restaurant){
        if(ans < dp[conscc[location]]){
            ans = dp[conscc[location]];
        }
    }
    cout << ans;
    return 0;
}