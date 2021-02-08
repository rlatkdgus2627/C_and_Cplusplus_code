#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll num[1001];

bool cmp(ll a, ll b){
    
    string temp1 = to_string(a);
    string temp2 = to_string(b);

    int len1 = temp1.length();
    int len2 = temp2.length();

    int i=0, j=0;

    while(i < len1 - 1 && j < len2 - 1){
        if(temp1[i] > temp2[j]) return true;
        else if(temp1[i] < temp2[j])  return false;
        else{
            if(i<len1-1) i++;
            if(j<len2-1) j++; 
        }
    }

    if(temp1[len1-1] > temp2[len2-1]) return true;
    else return false;

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num[i];
    }
    
    sort(num,num+n,cmp);
    
    for(int i=0;i<n;i++){
        cout << num[i];
    }
    return 0;
}