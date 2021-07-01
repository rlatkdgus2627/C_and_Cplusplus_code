#include <bits/stdc++.h>

using namespace std;

bool check[1000];

long long n;

int depth;

void solve(long long int a) {
	if (a == 1) {
		check[++depth] = true;
		return;
	}

	if (a % 2 == 0) {
		check[++depth] = false;
		solve(a / 2);
	}
	else {
		check[++depth] = true;
		solve(a / 2);
	}
}

int main(){
    cin >> n;
    solve(n);
    for(int i = depth-1; i>=0 ;i--){
        cout << check[i];
    }
    cout << "\n";
    
    
}