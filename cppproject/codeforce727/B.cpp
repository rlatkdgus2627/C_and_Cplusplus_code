#include <bits/stdc++.h>

using namespace std;

int n, q;
int psum[27][100002];
long long ans;

int main(){
    int l, r;
    scanf("%d %d",&n, &q);
    getchar();
    for(int i = 1; i <= n; i++){
        char input;
        scanf("%c", &input);
        psum[input - 'a' + 1][i] = psum[input - 'a' + 1][i-1] + 1;
        for(int j = 'a'; j <= 'z' ; j++){
            if(j == input)    continue;
            psum[j - 'a' + 1][i] = psum[j - 'a' + 1][i-1];
        }
    }
    for(int i = 0; i < q; i++){
        scanf("%d %d", &l, &r);
        ans = 0;
        for(int j = 1; j <= 26; j++){
            ans += (psum[j][r] - psum[j][l-1]) * j;
        }
        printf("%lld\n",ans);
    }
    return 0;
}