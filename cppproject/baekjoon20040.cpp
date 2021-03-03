#include <bits/stdc++.h>

using namespace std;

int n, m;
int Rank[500000], parent[500000], ans;
bool check;

int find(int u){
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

bool merge(int x, int y){
    int temp;
    x = find(x);
    y = find(y);
    if(x == y)  return true;
    if(Rank[x] == Rank[y])  Rank[x]++;
    else if(Rank[x] < Rank[y]){
        temp = x;
        x = y;
        y = temp;
    }
    parent[x] = y;

    return false;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int x,y;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    for(int i=1;i<=m;i++){
        cin >> x >> y;
        if(merge(x,y)&&!check){
            ans = i;
            check = true;
        }
    }
    cout << ans;
    return 0;
}