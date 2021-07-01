#include <bits/stdc++.h>

using namespace std;

int t;
int n;

bool visited[20001];

string solve(){
    string ans = "BRAK";
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>>Q;
    
    Q.push(make_pair(1, "1"));
    visited[1] = true;

    while(!Q.empty()){
        pair<int, string> cur = Q.front();
        Q.pop();
        if(cur.first == 0) {
            ans = cur.second;
            break;
        }
        
        if(visited[(cur.first * 10 + 1)%n] == false){
            visited[(cur.first * 10 + 1)%n] = true;
            Q.push(make_pair((cur.first * 10 + 1)%n, cur.second + "1"));
        }
        if(visited[(cur.first * 10)%n] == false){
            visited[(cur.first * 10)%n] = true;
            Q.push(make_pair((cur.first * 10)%n, cur.second + "0"));
        }
    }
    return ans;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve() << "\n";
    }

    return 0;
}