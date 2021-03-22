#include <bits/stdc++.h>

using namespace std;

int t,n;
double ans;

vector<double>diamonds;
vector<double>miners;

double dist(double x,double y){
    return sqrt(x*x+y*y);
}

bool cmp(double x, double y){
    return (x > 0 ? x : (-1.0)*x) > (y > 0 ? y : (-1.0)*y);
}

int main(){
    scanf("%d",&t);
    while(t--){
        ans = 0.0;
        scanf("%d",&n);
        double a,b;
        for(int i=0;i<n*2;i++){
            scanf("%lf %lf",&a,&b);
            if(a == 0){
                miners.push_back(b);
            }
            else if(b == 0){
                diamonds.push_back(a);
            }
        }
        sort(diamonds.begin(),diamonds.end(),cmp);
        sort(miners.begin(),miners.end(),cmp);
        for(int i=0;i<n;i++){
            ans += dist(diamonds[i],miners[i]);
        }
        printf("%.10lf\n",ans);
        diamonds.clear();
        miners.clear();
    }
    return 0;
}