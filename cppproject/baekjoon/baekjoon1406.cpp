#include <bits/stdc++.h>

using namespace std;

char str[100001];

stack<char>S1,S2;
int m;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> str;
    for(int i=0;str[i]!='\0';i++){
        S1.push(str[i]);
    }
    cin >> m;
    char query, chr;
    for(int i=0;i<m;i++){
        cin >> query;
        switch(query){
            case 'L':
                if(!S1.empty()){
                    S2.push(S1.top());
                    S1.pop();
                }
                break;
            case 'D':
                if(!S2.empty()){
                    S1.push(S2.top());
                    S2.pop();
                }
                break;
            case 'B':
                if(!S1.empty()){
                    S1.pop();
                }
                break;
            case 'P':
                cin >> chr;
                S1.push(chr);
                break;
        }
    }
    while(!S1.empty()){
        S2.push(S1.top());
        S1.pop();
    }
    while(!S2.empty()){
        cout << S2.top();
        S2.pop();
    }
    return 0;
}