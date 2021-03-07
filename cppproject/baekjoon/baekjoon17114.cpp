#include <bits/stdc++.h>
#define FOR(i,n) for(int i = 0 ; i<(n); i++)

using namespace std;

int m,n,o,p,q,r,s,t,u,v,w,cnt,ans;

vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>> board;

struct vertex{
    int w,v,u,t,s,r,q,p,o,n,m;
};

int direction[22][11]{
    {1,0,0,0,0,0,0,0,0,0,0},
    {-1,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0,0},
    {0,-1,0,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,0,0,0,0,0,0},
    {0,0,-1,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,-1,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,-1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,-1,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0},
    {0,0,0,0,0,0,-1,0,0,0,0},
    {0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,-1,0,0,0},
    {0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,-1,0,0},
    {0,0,0,0,0,0,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,-1,0},
    {0,0,0,0,0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0,0,0,0,-1}
};

queue<struct vertex>Q;

bool safe(struct vertex point){
    return 0<=point.m&&point.m<m&&0<=point.n&&point.n<n&&0<=point.o&&point.o<o&&0<=point.p&&point.p<p&&0<=point.q&&point.q<q&&0<=point.r&&point.r<r&&0<=point.s&&point.s<s&&0<=point.t&&point.t<t&&0<=point.u&&point.u<u&&0<=point.v&&point.v<v&&0<=point.w&&point.w<w;
}

void bfs(){
    int a,b,c,d,e,f,g,h,i,j,k;
    while(!Q.empty()){
        struct vertex cur = Q.front();
        
        Q.pop();
        if(cnt == 0)    break;
        FOR(iter,22){
            a = direction[iter][0]; b = direction[iter][1]; c = direction[iter][2]; d = direction[iter][3]; e = direction[iter][4]; f = direction[iter][5]; g = direction[iter][6]; h= direction[iter][7];  i= direction[iter][8];  j= direction[iter][9];  k= direction[iter][10];
            if(safe({cur.w+a,cur.v+b,cur.u+c,cur.t+d,cur.s+e,cur.r+f,cur.q+g,cur.p+h,cur.o+i,cur.n+j,cur.m+k}) && board[cur.w+a][cur.v+b][cur.u+c][cur.t+d][cur.s+e][cur.r+f][cur.q+g][cur.p+h][cur.o+i][cur.n+j][cur.m+k] == 0){
                cnt--;
                ans = board[cur.w+a][cur.v+b][cur.u+c][cur.t+d][cur.s+e][cur.r+f][cur.q+g][cur.p+h][cur.o+i][cur.n+j][cur.m+k] = board[cur.w][cur.v][cur.u][cur.t][cur.s][cur.r][cur.q][cur.p][cur.o][cur.n][cur.m]+1;
                Q.push({cur.w+a,cur.v+b,cur.u+c,cur.t+d,cur.s+e,cur.r+f,cur.q+g,cur.p+h,cur.o+i,cur.n+j,cur.m+k});
            }
        }
                                                    
        
    }
    if(cnt == 0){
        cout << (ans ? ans-1 : 0);
    }
    else{
        cout << "-1";
    }
    
}

int main(){
    int value;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;

    FOR(a,w){
        board.push_back(vector<vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>>());
        FOR(b,v){
            board[a].push_back(vector<vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>>());
            FOR(c,u){
                board[a][b].push_back(vector<vector<vector<vector<vector<vector<vector<vector<int>>>>>>>>());
                FOR(d,t){
                    board[a][b][c].push_back(vector<vector<vector<vector<vector<vector<vector<int>>>>>>>());
                    FOR(e,s){
                        board[a][b][c][d].push_back(vector<vector<vector<vector<vector<vector<int>>>>>>());
                        FOR(f,r){
                            board[a][b][c][d][e].push_back(vector<vector<vector<vector<vector<int>>>>>());
                            FOR(g,q){
                                board[a][b][c][d][e][f].push_back(vector<vector<vector<vector<int>>>>());
                                FOR(h,p){
                                    board[a][b][c][d][e][f][g].push_back(vector<vector<vector<int>>>());
                                    FOR(i,o){
                                        board[a][b][c][d][e][f][g][h].push_back(vector<vector<int>>());
                                        FOR(j,n){
                                            board[a][b][c][d][e][f][g][h][i].push_back(vector<int>());
                                            FOR(k,m){
                                                cin >> value;
                                                board[a][b][c][d][e][f][g][h][i][j].push_back(value);
                                                if(value == 1){
                                                    Q.push({a,b,c,d,e,f,g,h,i,j,k});
                                                }
                                                else if(value == 0){
                                                    cnt++;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    bfs();
}