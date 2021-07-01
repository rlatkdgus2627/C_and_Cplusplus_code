#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<int>graph[10001];
vector<int>rgraph[10001];

vector<vector<int> >SCC;
stack<int>S;

bool visited[10001];

void dfs(int cur){
    visited[cur] = true;
    for(int next : graph[cur]){
        if(!visited[next])  dfs(next);
    }
    S.push(cur);
}

void find(int cur, vector<int>& sub){
    visited[cur] = true;
    for(int next : rgraph[cur]){
       if(!visited[next])   find(next, sub);
    }
    sub.push_back(cur);
}


bool cmp(vector<int>& lhs, vector<int>& rhs){
    return lhs[0] < rhs[0];
}


int main(){
    int x, y;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> v >> e;
    for(int i = 0; i < e; i++){
        cin >> x >> y;
        graph[x].push_back(y);
        rgraph[y].push_back(x);
    }

    memset(visited,false,sizeof(visited));
    for(int i = 1; i <= v; i++){
        if(!visited[i]) dfs(i);
    }
    memset(visited,false,sizeof(visited));
    while(!S.empty()){
        vector<int> temp;
        int p = S.top();
        S.pop();
        if(!visited[p]){
            find(p,temp);
            sort(temp.begin(),temp.end());
            SCC.push_back(temp);
            temp.clear();
        }
    }
    sort(SCC.begin(),SCC.end(),cmp);
    cout << SCC.size() << "\n";
    for(int i = 0 ; i < SCC.size(); i++){
        for(int data:SCC[i])    cout << data << " ";
        cout << "-1" << "\n";
    }

    return 0;
}