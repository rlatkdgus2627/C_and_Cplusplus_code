#include <bits/stdc++.h>

using namespace std;

int parent[4000001];
int num[4000001];

int find(int u){
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a != b)  parent[a] = b;
}

int main(){
    int n,m,k,x;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    
    cin >> n >> m >> k;

    for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    
    for(int i=0;i<m;i++){
        cin >> num[i];
    }
    sort(num,num+m);
    for(int i=0;i<k;i++){
        cin >> x;
        auto t = upper_bound(num,num+m,find(x));
        cout << *t << "\n";
        merge(x,*t);
    }
    return 0;
}