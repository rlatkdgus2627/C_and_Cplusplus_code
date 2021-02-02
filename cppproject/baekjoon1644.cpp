#include <bits/stdc++.h>

using namespace std;


bool number[4000001];

int n;
int ans;

vector<int>prime;

int main(){
    cin >> n;

    //get a prime
    number[1] = true;
    for(int i=2;i<=n;i++){
        if(number[i] == false){
            for(int j=i*2;j<=n;j+=i){
                number[j] = true;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(number[i] == false)  prime.push_back(i);
    }


    //solve (two pointer)
    int s = 0, e = 0, sum = 0;

    while(s <= e && s < prime.size()){
        if(sum < n && e < prime.size()){
            sum += prime[e++];
        }
        else if(sum == n){
            ans++;
            sum -= prime[s++];
        }
        else{
            sum -= prime[s++];
        }
    }
    
    cout << ans;
    return 0;
}