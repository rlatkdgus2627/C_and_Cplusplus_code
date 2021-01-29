#include <bits/stdc++.h>
#define x first
#define y second
#define D double

using namespace std;

typedef long long ll;
typedef pair<ll,ll> p;
typedef pair<double,double> pd;

p a,b,c,d;
pd ap,bp,cp,dp,ans;

int ccw(p p1, p p2, p p3){
    ll ret = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y - (p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
    if(ret > 0LL) return 1;
    else if(ret == 0LL) return 0;
    else return -1; 
}

bool checkRange(p p1, p p2, pd target){
    p temp;
    if(p2 < p1){temp = p2; p2 = p1; p1 = temp;}

    return (p1.x != target.x ? p1.x < target.x : p1.y <= target.y) && (p2.x != target.x ? p2.x > target.x : p2.y >= target.y);
}

int main(){
    p temp;

    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    ll check = (b.x - a.x)*(d.y - c.y)-(d.x - c.x)*(b.y - a.y);

    if(check == 0LL){
        if(b < a){temp = b; b = a; a = temp;}
        if(d < c){temp = d; d = c; c = temp;}
        if(ccw(a,b,c)!=0 || b < c || d < a){
            cout << "0" << endl;
        }
        else if(b == c){
            cout << "1" << endl;
            cout << b.x << " " << b.y << endl;
        }
        else if(d == a && b != c){
            cout << "1" << endl;
            cout << d.x << " " << d.y << endl;
        }
        else{
            cout << "1" << endl;
        }
    }
    else{

        /*
        ap.x = (D)a.x;
        ap.y = (D)a.y;
        bp.x = (D)b.x;
        bp.y = (D)b.y;
        cp.x = (D)c.x;
        cp.y = (D)c.y;
        dp.x = (D)d.x;
        dp.y = (D)d.y;
        */
        
        ans.x = a.x + (b.x - a.x) * (((c.x - a.x)*(d.y - c.y)-(d.x - c.x)*(c.y - a.y))/(D)check);
        ans.y = a.y + (b.y - a.y) * (((c.x - a.x)*(d.y - c.y)-(d.x - c.x)*(c.y - a.y))/(D)check);

        if(checkRange(a,b,ans)&&checkRange(c,d,ans)){
            cout << "1" << endl;
            cout << fixed;
            cout.precision(16);
            cout << ans.x << " " << ans.y <<endl;
        }
        else{
            cout << "0" << endl;
        }
    }

    return 0;
}