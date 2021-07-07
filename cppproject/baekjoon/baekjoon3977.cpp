#include <bits/stdc++.h>

using namespace std;

int t, n, m;
vector<int>graph[100001];
vector<int>rgraph[100001];
vector<vector<int> >SCC;

stack<int> S;

int indegree[100001];
int converted[100001];
bool visited[100001];

void dfs(int cur){
    visited[cur] = true;
    for(int next:graph[cur]){
        if(!visited[next])  dfs(next);
    }
    S.push(cur);
}

void solve(int cur, vector<int>& scc){
    visited[cur] = true;
    for(int next:rgraph[cur]){
        if(!visited[next])  solve(next, scc);
    }
    scc.push_back(cur);
    converted[cur] = SCC.size();
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int A, B;
        vector<int> ans;
        bool check = false, confused = false;

        cin >> n >> m;

        SCC.clear();
        for(int i = 0; i < n; i++){
            graph[i].clear();
            rgraph[i].clear();
            indegree[i] = 0;
            converted[i] = 0;
            visited[i] = false;
        }

        for(int i = 0; i < m; i++){
            cin >> A >> B;
            graph[A].push_back(B);
            rgraph[B].push_back(A);
        }

        for(int i = 0; i < n; i++){
            if(visited[i] == false) dfs(i);
        }

        for(int i = 0; i < n; i++){
            visited[i] = false;
        }

        while(!S.empty()){
            vector<int> scc;
            int cur = S.top();
            S.pop();
            if(!visited[cur]){
                solve(cur, scc);
                SCC.push_back(scc);
                scc.clear();
            }
        }

        /*
        for(int i = 0 ; i < SCC.size(); i++){
            for(int data:SCC[i])    cout << data << " ";
            cout << "-1" << "\n";
        }
        */

        for(int i = 0; i < n; i++){
            for(int next : graph[i]){
                if(converted[next] != converted[i]) indegree[converted[next]]++;
            }
        }

        for(int i = 0; i < SCC.size(); i++){
            if(indegree[i] == 0 && check){
                confused = true;
                break;
            }
            if(indegree[i] == 0){
                check = true;
                for(int element : SCC[i]){
                    ans.push_back(element);
                }
            }
        }
        

        if(confused){
            cout << "Confused" << "\n\n";
        }
        else{
            sort(ans.begin(), ans.end());
            for(int element : ans){
                cout << element << "\n";
            }
            cout << "\n";
        }
    }
    return 0;
}