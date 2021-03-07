#include <bits/stdc++.h>

using namespace std;

long long n,m;
long long num[50002];
long long ans;
bool check;
long long temp,amount;
long long cnt[10000001];

vector<long long> factor(long long n){
    vector<long long> ret;
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            ret.push_back(i);
            n/=i;
        }
    }
    if(n>1) 
        ret.push_back(n);
    return ret;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> num[i];
        if(num[i] % 7 != 0 || num[i] % 49 == 0){
            check = true;
        }
        else{
            num[i]/=7;
        }
    }
    if(check){
        cout << "-1" << "\n";
        return 0;
    }
    for(int i=0;i<m;i++){
        if(num[i]==1) continue;
        vector<long long>primes = factor(num[i]);
        temp = primes[0];
        amount = 1;
        for(int j=1;j<primes.size();j++){
            if(temp != primes[j]){
                if(cnt[temp] < amount){
                    ans += (amount - cnt[temp]);
                    cnt[temp] = amount; 
                }
                temp = primes[j];
                amount = 1;
            }
            else{
                amount++;
            }
        }
        if(cnt[temp] < amount){
            ans += (amount - cnt[temp]);
            cnt[temp] = amount;        
        }
    }
    for(int i=m;i<n;i++){
        vector<long long>primes1 = factor(num[i-m]);
        for(auto j:primes1){
            cnt[j]--;
        }
        vector<long long>primes2 = factor(num[i]);
        if(num[i]==1) continue;
        temp = primes2[0];
        amount = 1;
        for(int j=1;j<primes2.size();j++){
            if(temp != primes2[j]){
                if(cnt[temp] < amount){
                    ans += (amount - cnt[temp]);
                    cnt[temp] = amount; 
                }
                temp = primes2[j];
                amount = 1;
            }
            else{
                amount++;
            }
        }
        if(cnt[temp] < amount){
            ans += (amount - cnt[temp]);
            cnt[temp] = amount; 
        }
    }
    cout << ans << "\n";
    
    return 0;
}