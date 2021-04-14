#include <bits/stdc++.h>

using namespace std;

int t, n;

vector<int>v[10001];

int depth1[10001];
int depth2[10001];

void dfs1(int cur, int d){
    depth1[cur] = d;
    for(auto next : v[cur]){
        if(!depth1[next])   dfs1(next,d+1);
    }
}
void dfs2(int cur, int d){
    depth2[cur] = d;
    for(auto next : v[cur]){
        if(!depth2[next])   dfs2(next,d+1);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> t;
    while(t--){
        int x, y, index, Min;
        cin >> n;
        for(int i=1;i<=n;i++){
            v[i].clear();
            depth1[i] = 0;
            depth2[i] = 0;
        }
        for(int i=0;i<n-1;i++){
            cin >> x >> y;
            v[y].push_back(x);
        }
        cin >> x >> y;
        dfs1(x,1);
        dfs2(y,1);
        index = 0;
        Min = 1e9;
        for(int i=1;i<=n;i++){
            //cout << depth1[i] << " . " << depth2[i] << '\n';
            if(Min > depth1[i] + depth2[i] && depth1[i] > 0 && depth2[i] > 0){
                Min = depth1[i] + depth2[i];
                index = i;
            }
        }
        cout << index << '\n';
    }
    return 0;
}