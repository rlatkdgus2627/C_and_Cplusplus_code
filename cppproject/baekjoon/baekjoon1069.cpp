#include <bits/stdc++.h>

using namespace std;

double x,y,d,t;
double dist, ans, jump;

int cnt;

int main(){
    scanf("%lf %lf %lf %lf",&x,&y,&d,&t); 
    dist = sqrt(x*x+y*y);
    cnt = dist/d;
    if(!cnt)    cnt++;
    jump = (double)cnt*d;
    ans = min((double)cnt*t+abs(dist-jump),(double)(cnt+1)*t);
    ans = min(dist, ans);
    printf("%.14lf",ans);
    return 0;
}