//주의! : 스파게티 코드이기 때문에 다른 사람의 코드를 참고하시는 것을 추천합니다.
//문제 똑바로 읽을걸.....
#include <bits/stdc++.h>

using namespace std;

int n, k, l, dir, ans;
bool apple[101][101];
bool board[101][101];
bool gend;

bool safe(int r,int c){
    return (1<=r&&r<=n)&&(1<=c&&c<=n);
}

int main(){

    int x,y;
    int sec;
    char d;

    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for(int i=0;i<k;i++){
        cin >> x >> y;
        apple[x][y] = true;
    }
    deque<pair<int,int> >dq;
    dq.push_front(make_pair(1,1));
    board[1][1] = true;
    cin >> l;
    for(int i=0;i<l;i++){
        cin >> sec >> d;
        cin.clear();
        if(!gend){
            for(int j=ans;j<sec;j++){
                pair<int, int> cur = dq.front(), rear;
                //cout << cur.first << " " << cur.second << " " << dir << "\n";
                switch(dir){
                    case 0: //right
                        if(safe(cur.first,cur.second+1)&&!board[cur.first][cur.second+1]&&apple[cur.first][cur.second+1]){
                            apple[cur.first][cur.second+1] = false;
                            dq.push_front(make_pair(cur.first,cur.second+1));
                            board[cur.first][cur.second+1] = true;
                            ans++;
                        }
                        else if(safe(cur.first,cur.second+1)&&!board[cur.first][cur.second+1]&&!apple[cur.first][cur.second+1]){
                            rear = dq.back();
                            dq.pop_back();
                            board[rear.first][rear.second] = false;
                            dq.push_front(make_pair(cur.first,cur.second+1));
                            board[cur.first][cur.second+1] = true;
                            ans++;
                            
                        }
                        else gend = true;
                        break;
                    case 1: //down
                        if(safe(cur.first+1,cur.second)&&!board[cur.first+1][cur.second]&&apple[cur.first+1][cur.second]){
                            apple[cur.first+1][cur.second] = false;
                            dq.push_front(make_pair(cur.first+1,cur.second));
                            board[cur.first+1][cur.second] = true;
                            ans++;
                        }
                        else if(safe(cur.first+1,cur.second)&&!board[cur.first+1][cur.second]&&!apple[cur.first+1][cur.second]){
                            rear = dq.back();
                            dq.pop_back();
                            board[rear.first][rear.second] = false;
                            dq.push_front(make_pair(cur.first+1,cur.second));
                            board[cur.first+1][cur.second] = true;
                            ans++;           
                        }
                        else gend = true;
                        break;
                    case 2: //left
                        if(safe(cur.first,cur.second-1)&&!board[cur.first][cur.second-1]&&apple[cur.first][cur.second-1]){
                            apple[cur.first][cur.second-1] = false;
                            dq.push_front(make_pair(cur.first,cur.second-1));
                            board[cur.first][cur.second-1] = true;
                            ans++;
                        }
                        else if(safe(cur.first,cur.second-1)&&!board[cur.first][cur.second-1]&&!apple[cur.first][cur.second-1]){
                            rear = dq.back();
                            dq.pop_back();
                            board[rear.first][rear.second] = false;
                            dq.push_front(make_pair(cur.first,cur.second-1));
                            board[cur.first][cur.second-1] = true;
                            ans++;
                        }
                        else gend = true;
                        break;
                    case 3: //up
                        if(safe(cur.first-1,cur.second)&&!board[cur.first-1][cur.second]&&apple[cur.first-1][cur.second]){
                            apple[cur.first-1][cur.second] = false;
                            dq.push_front(make_pair(cur.first-1,cur.second));
                            board[cur.first-1][cur.second] = true;
                            ans++;
                        }
                        else if(safe(cur.first-1,cur.second)&&!board[cur.first-1][cur.second]&&!apple[cur.first-1][cur.second]){
                            rear = dq.back();
                            dq.pop_back();
                            board[rear.first][rear.second] = false;
                            dq.push_front(make_pair(cur.first-1,cur.second));
                            board[cur.first-1][cur.second] = true;
                            ans++;
                        }
                        else gend = true;
                        break;
                }
            }
        }
        if(d == 'L'){
            dir = (dir - 1) >= 0 ? (dir - 1) : 3;
        }
        else{
            dir = (dir + 1)%4;
        }
    }
    
    while(!gend){
        pair<int, int> cur = dq.front(), rear;
        //cout << cur.first << " " << cur.second << " " << dir << "\n";
        switch(dir){
            case 0: //right
                if(safe(cur.first,cur.second+1)&&!board[cur.first][cur.second+1]&&apple[cur.first][cur.second+1]){
                    apple[cur.first][cur.second+1] = false;
                    dq.push_front(make_pair(cur.first,cur.second+1));
                    board[cur.first][cur.second+1] = true;
                    ans++;
                }
                else if(safe(cur.first,cur.second+1)&&!board[cur.first][cur.second+1]&&!apple[cur.first][cur.second+1]){
                    rear = dq.back();
                    dq.pop_back();
                    board[rear.first][rear.second] = false;

                   
                    dq.push_front(make_pair(cur.first,cur.second+1));
                    board[cur.first][cur.second+1] = true;
                    ans++;
                    
                }
                else gend = true;
                break;
            case 1: //down
                if(safe(cur.first+1,cur.second)&&!board[cur.first+1][cur.second]&&apple[cur.first+1][cur.second]){
                    apple[cur.first+1][cur.second] = false;
                    dq.push_front(make_pair(cur.first+1,cur.second));
                    board[cur.first+1][cur.second] = true;
                    ans++;
                }
                else if(safe(cur.first+1,cur.second)&&!board[cur.first+1][cur.second]&&!apple[cur.first+1][cur.second]){
                    rear = dq.back();
                    dq.pop_back();
                    board[rear.first][rear.second] = false;

                    
                    dq.push_front(make_pair(cur.first+1,cur.second));
                    board[cur.first+1][cur.second] = true;
                    ans++;
                    
                }
                else gend = true;
                break;
            case 2: //left
                if(safe(cur.first,cur.second-1)&&!board[cur.first][cur.second-1]&&apple[cur.first][cur.second-1]){
                    apple[cur.first][cur.second-1] = false;
                    dq.push_front(make_pair(cur.first,cur.second-1));
                    board[cur.first][cur.second-1] = true;
                    ans++;
                }
                else if(safe(cur.first,cur.second-1)&&!board[cur.first][cur.second-1]&&!apple[cur.first][cur.second-1]){
                    rear = dq.back();
                    dq.pop_back();
                    board[rear.first][rear.second] = false;

                    dq.push_front(make_pair(cur.first,cur.second-1));
                    board[cur.first][cur.second-1] = true;
                    ans++;
                    
                }
                else gend = true;
                break;
            case 3: //up
                if(safe(cur.first-1,cur.second)&&!board[cur.first-1][cur.second]&&apple[cur.first-1][cur.second]){
                    apple[cur.first-1][cur.second] = false;
                    dq.push_front(make_pair(cur.first-1,cur.second));
                    board[cur.first-1][cur.second] = true;
                    ans++;
                }
                else if(safe(cur.first-1,cur.second)&&!board[cur.first-1][cur.second]&&!apple[cur.first-1][cur.second]){
                    rear = dq.back();
                    dq.pop_back();
                    board[rear.first][rear.second] = false;

                    
                    dq.push_front(make_pair(cur.first-1,cur.second));
                    board[cur.first-1][cur.second] = true;
                    ans++;
                }
                else gend = true;
            break;
        }
    }
    cout << ans+1 << "\n";

    return 0;
}