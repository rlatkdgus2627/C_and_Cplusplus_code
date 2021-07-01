#include <bits/stdc++.h>

using namespace std;

int id, visited[10001];
bool finished[10001];
vector<int> graph[10001];
vector<vector<int> >SCC;
stack<int> S;

int v, e;

int dfs(int cur){

    visited[cur] = ++id;  //고유의 id값 할당
    S.push(cur);

    int parent = visited[cur];

    //가장 높은 위치를 parent에 저장
    for(int next:graph[cur]){
        if(!visited[next]){   //탐색되지 않은 경우
            parent = min(parent, dfs(next));
        }
        else if(!finished[next]){   //탐색이 되었으나 SCC에 포함이 되지 않은 경우
            parent = min(parent, visited[next]);
        }
    }

    //자기 자신이 부모인 경우 (자기 자신이 SCC에서 가장 높은 위치인 경우)
    if(parent == visited[cur]){
        vector<int> group;
        while(1){   //자기 자신이 나올때까지 stack에서 pop하고 SCC에 저장
            int p = S.top();
            S.pop();
            group.push_back(p);
            finished[p] = true; //SCC에 포함되었음을 체크
            if(p == cur)    break;
        }
        sort(group.begin(),group.end());
        SCC.push_back(group);
    }

    return parent;
}

bool cmp(vector<int>& lhs, vector<int>& rhs){
    return lhs[0] < rhs[0];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> v >> e;
    int x, y;
    for(int i = 0; i < e; i++){
        cin >> x >> y;
        graph[x].push_back(y);
    }

    for(int i = 1; i <= v; i++){
        if(!visited[i])   dfs(i);
    }

    sort(SCC.begin(),SCC.end(),cmp);
    cout << SCC.size() << "\n";
    for(int i = 0 ; i < SCC.size(); i++){
        for(int data:SCC[i])    cout << data << " ";
        cout << "-1" << "\n";
    }
    return 0;
}