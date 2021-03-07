#include <bits/stdc++.h>

using namespace std;

vector<int>edges[32001];

int n, m;
int indegree[32001];

priority_queue<int,vector<int>,greater<int> >pq;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int x,y;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y;
        edges[x].push_back(y);
        indegree[y]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i] == 0)    pq.push(i);
    }

    while(!pq.empty()){
        int cur = pq.top();
        cout << cur << " ";
        pq.pop();
        for(int next:edges[cur]){
            indegree[next]--;
            if(!indegree[next]){
                pq.push(next);
            }
        }
    }
    
    
    return 0;
}