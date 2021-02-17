#include <bits/stdc++.h>

using namespace std;

char str[100001];
int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    while(1){
        cin >> str;
        if(str[0] == '0')   break;
        int len = strlen(str);
        bool answer = true;
        for(int i=0;i<len;i++){
            if(str[i]!=str[len-1-i]){
                answer = false;
                break;
            }
        }
        if(answer){
            cout << "yes" << "\n";
        }
        else cout << "no" << "\n";
    }
    
    return 0;
}