#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll num[101];
bool check[101];

map<ll, ll> graph;
vector<ll> ans;

void solve(ll cur){
    ans.push_back(cur);
    if(graph.find(cur) != graph.end())  solve(graph[cur]);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            if(num[i] * 2 == num[j] || (num[i] % 3 == 0 && num[i] / 3 == num[j])){
                graph[num[i]] = num[j];
                check[j] = true;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(check[i] == false){
            solve(num[i]);
            break;
        }
    }

    for(ll x : ans){
        cout << x << " ";
    }

    return 0;
}