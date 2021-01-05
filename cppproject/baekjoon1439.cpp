#include <iostream>
#include <algorithm>

using namespace std;

char str[1000001];
int cnt1,cnt2;
bool check;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> str;
    check = false;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='0'&&!check){
            cnt1++;
            check = true;
        }
        else if(str[i]=='1') check = false;
    }
    
    check = false;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='1'&&!check){
            cnt2++;
            check = true;
        }
        else if(str[i]=='0') check = false;
    }
    cout << min(cnt1,cnt2) << endl;
    return 0;
}