#include <bits/stdc++.h>

using namespace std;

bool prime[10000], visited[10000];
int t,s,e;

int pows(int x, int y){
    while(y--){
        x*=10;
    }
    return x;
}

void bfs(){
    bool check = false;
    int num[4], temp;
    queue<pair<int, int> > Q;
    Q.push(make_pair(s,0));
    visited[s] = true;
    while(!Q.empty()){
        pair<int, int> cur = Q.front();
        Q.pop();
        if(cur.first == e){
            cout << cur.second << endl;
            check = true;
            break;
        }
        num[3] = cur.first/1000;
        num[2] = (cur.first%1000)/100;
        num[1] = (cur.first%100)/10;
        num[0] = (cur.first%10);
        for(int i=0;i<4;i++){
            for(int j=0;j<10;j++){
                if(i==3&&j==0) continue;
                temp = cur.first-pows(num[i],i)+pows(j,i);
                if(prime[temp] && !visited[temp]){
                    Q.push(make_pair(temp,cur.second+1));
                    visited[temp] = true;
                }
            }
        }
    }
    if(!check) cout << "Impossible" << endl;
}

int main(){
    cin >> t;
    //get primes
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i=2;i<10000;i++){
        if(prime[i]){
            for(int j=i*2;j<10000;j+=i){
                prime[j] = false;
            }
        }
    }
    while(t--){
        cin >> s >> e;
        memset(visited,false,sizeof(visited));
        bfs();
    }
    return 0;
}