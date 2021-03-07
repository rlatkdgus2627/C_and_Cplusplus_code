#include <bits/stdc++.h>

using namespace std;

int t,n,m;

int Rank[501], cnt;
bool relation[501][501];
int indegree[501];
int ans[501];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    int x,y;
    while(t--){
        queue<int>Q;
        cnt = 0;
        memset(indegree,0,sizeof(indegree));
        memset(relation,0,sizeof(relation));
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> Rank[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                relation[Rank[i]][Rank[j]] = true; 
            }  
        }
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            if(relation[x][y]){
                relation[x][y] = false;
                relation[y][x] = true;
            }
            else{
                relation[x][y] = true;
                relation[y][x] = false;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(relation[i][j])  indegree[j]++;  
            }  
        }

        for(int i=1;i<=n;i++){
            if(!indegree[i])    Q.push(i);
        }

        while(!Q.empty()){

            int cur = Q.front();
            Q.pop();
            ans[++cnt] = cur;
            for(int i=1;i<=n;i++){
                if(relation[cur][i]){
                    indegree[i]--;
                    if(!indegree[i])    Q.push(i);
                }
            }
        }

        if(cnt != n){
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for(int i=1;i<=n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}