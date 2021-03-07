#include <bits/stdc++.h>

using namespace std;

bool visited[10000];

pair<int, char> trace[10000];

vector<char>ans;

int t,s,e;

void getTrace(int cur){
    if(cur == s) return;
    ans.push_back(trace[cur].second);
    getTrace(trace[cur].first);
}

void bfs(){
    int num[4],temp,temp1,temp2;
    queue<int>Q;
    Q.push(s);
    visited[s] = true;
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        if(cur == e){
            break;
        }
        num[0] = cur/1000;
        num[1] = (cur%1000)/100;
        num[2] = (cur%100)/10;
        num[3] = cur%10;
        temp = (cur-1<0 ? 9999:cur-1);
        temp1 = ((num[1]*10+num[2])*10+num[3])*10+num[0]; 
        temp2 = ((num[3]*10+num[0])*10+num[1])*10+num[2];
        if(visited[(cur*2)%10000] == false){
            Q.push((cur*2)%10000);
            visited[(cur*2)%10000] = true;
            trace[(cur*2)%10000].first = cur;
            trace[(cur*2)%10000].second = 'D';
        }
        if(visited[temp] == false){
            Q.push(temp);
            visited[temp] = true;
            trace[temp].first = cur;
            trace[temp].second = 'S';
        }
        if(visited[temp1] == false){
            Q.push(temp1);
            visited[temp1] = true;
            trace[temp1].first = cur;
            trace[temp1].second = 'L';
        }
        if(visited[temp2] == false){
            Q.push(temp2);
            visited[temp2] = true;
            trace[temp2].first = cur;
            trace[temp2].second = 'R';
        }
    }
    getTrace(e);
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        //init
        memset(visited,0,sizeof(visited));
        for(int i=0;i<10000;i++){
            trace[i].first = 0;
            trace[i].second = '\n';
        }
        ans.clear();

        cin >> s >> e;
        bfs();
        for(int i=ans.size()-1;i>=0;i--){
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}