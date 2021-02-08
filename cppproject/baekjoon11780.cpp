#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

int n, m, dist[101][101], path[101][101];

vector<int>findPath(int s,int e){
    vector<int>ret;
    if(!path[s][e]){
        return ret;
    }
    ret.push_back(s);
    while(s != e){
        s = path[s][e];
        ret.push_back(s);
    }
    return ret;
}

int main(){
    int x,y,distance;

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    cin >> m;
    for(int i=0.;i<=n;i++){
        for(int j=0;j<=n;j++){
            dist[i][j] = (i == j ? 0 : INF);
        }
    }
    for(int i=0;i<m;i++){
        cin >> x >> y >> distance;
        dist[x][y] = min(dist[x][y], distance);
        path[x][y] = y;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << (dist[i][j] == INF ? 0 : dist[i][j]) << " ";   
        }
        cout << "\n";
    }

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vector<int>ans(findPath(i,j));
            if(ans.empty()) cout << "0";
            else{
                cout << ans.size() << " ";
                for(int x:ans){
                    cout << x << " ";
                }
            }
            cout << "\n";
        }
        
    }
    return 0;
}