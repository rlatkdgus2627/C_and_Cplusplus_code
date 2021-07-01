#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll n;
vector<ll>ans;

ll tc[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};

ll power(ll a, ll k, ll input) {
	ll ret = 1LL;
    a %= input;
    while(k){
        if(k%2) ret = ((__int128)ret*a) % input;
        k /= 2;
        a = ((__int128)a*a) % input;
    }
    return ret;
}

bool checkprime(ll input, ll a) {
	if (a % input == 0) return true;
	ll k = input - 1;
	while (1) {
		ll temp = power(a, k, input);
		if (temp == input - 1) return true;
		if (k % 2) return (temp == 1 || temp == input - 1);
		k /= 2;
	}
}

ll gcd(ll a, ll b){
    if(b == 0)  return a;
    else return gcd(b, a%b);
}

ll polynominal(ll x, ll k, ll mod){
    return ((__int128)x*x%mod + k)%mod;
}

ll pollard_rho(ll num){
    if(num == 1)  return 1LL;
    if (num % 2 == 0) {
		return 2LL;
	}
    if (num % 3 == 0) {
		return 3LL;
	}
    bool check = true;
    for(int i = 0; i < 13; i++){
        check = checkprime(num,tc[i]);
        if(!check)  break;
    }
    if(check){
        return num;
    }
    ll x, y, r, factor = num;
    do{
        if(factor == num){
            x = y = rand()%num + 1;
            r = rand()%100 + 1;
            factor = 1;
        }
        x = polynominal(x,r,num);
        y = polynominal(y,r,num);
        y = polynominal(y,r,num);
        factor = gcd(abs(x-y),num);
    }while(factor == 1);
    check = true;
    for(int i = 0; i < 13; i++){
        check = checkprime(factor,tc[i]);
        if(!check)  break;
    }
    if(check)   return factor;
    else return pollard_rho(factor);
}

int main(){
    ll temp;
    cin >> n;
    srand(time(NULL));
    while(n > 1){
        temp = pollard_rho(n);
        ans.push_back(temp);
        n /= temp;
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans) cout << x << "\n";
    return 0;
}