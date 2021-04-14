#include <bits/stdc++.h>

using namespace std;

int t;
string str;
bool check, check2;
int len;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        check = check2 = true;
        cin >> str;
        len = str.length();
        for(int i=0;i<len;i++){
            if(str[i] != str[len-1-i]){
                check = false;
                break;
            }
            if(str[i] != 'a'){
                check2 = false;
            }
        }
        if(check == true){
            if(check2){
                cout << "NO" << "\n";
            }
            else{
                cout << "YES" << "\n";
                cout << str << "a" << "\n";
            }
        }
        else{
            cout << "YES" << "\n";
            string temp = str + "a";
            string temp2 = temp;
            reverse(temp.begin(),temp.end());
            if(temp2.compare(temp) == 0){
                cout << "a" << str << "\n";
            }
            else    cout << str << "a" << "\n";
        }
    }
    return 0;
}