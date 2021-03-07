#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int,int> P;

int n,ans[1000001];

vector<P>number;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        number.push_back(make_pair(x,i));
    }

    memset(ans,-1,sizeof(ans));

    stack<P>S;

    for(int i=0;i<n;i++){
        while(!S.empty()){
            if(number[i].first > S.top().first){
                ans[S.top().second] = number[i].first;
                S.pop();
            }
            else break;
        }
        S.push(number[i]);
    }

    for(int i=0;i<n-1;i++){
        cout << ans[i] << " "; 
    }
    cout << "-1";

    return 0;
}