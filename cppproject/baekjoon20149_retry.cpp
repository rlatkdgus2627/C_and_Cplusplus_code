#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<double,double> p;

p a,b,c,d,ans;

int ccw(p p1, p p2, p p3){
    double ret = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y - (p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
    if(ret > 0) return 1;
    else if(ret == 0) return 0;
    else return -1; 
}

bool checkRange(p p1, p p2, p target){
    p temp;
    if(p2 < p1){temp = p2; p2 = p1; p1 = temp;}
    return target == p1 || target == p2 || (p1 < target && target < p2);
}

int main(){

    p temp;

    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    double check = (b.x - a.x)*(d.y - c.y)-(d.x - c.x)*(b.y - a.y);

    if(check == 0){
        if(b < a){temp = b; b = a; a = temp;}
        if(d < c){temp = d; d = c; c = temp;}
        if(ccw(a,b,c)!=0 || b < c || d < a){
            cout << "0" << endl;
        }
        else if(b == c){
            cout << "1" << endl;
            cout << b.x << " " << b.y << endl;
        }
        else if(d == a){
            cout << "1" << endl;
            cout << d.x << " " << d.y << endl;
        }
        else{
            cout << "1" << endl;
        }
    }
    else{
        ans.x = a.x + (b.x - a.x) * (((c.x - a.x)*(d.y - c.y)-(d.x - c.x)*(c.y - a.y))/check);
        ans.y = a.y + (b.y - a.y) * (((c.x - a.x)*(d.y - c.y)-(d.x - c.x)*(c.y - a.y))/check);

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