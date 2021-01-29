#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;

typedef pair<ll,ll> dot;

dot p[4];

double slope1, slope2, ansx, ansy;

void calculation(){
    slope1 = (double)(p[1].y-p[0].y)/(double)(p[1].x-p[0].x);
    slope2 = (double)(p[3].y-p[2].y)/(double)(p[3].x-p[2].x);
    if(p[1].x-p[0].x == 0){
        ansx = p[0].x;
        ansy = slope2*(ansx - (double)p[2].x)+p[2].y;
    }
    else if(p[3].x-p[2].x == 0){
        ansx = p[2].x;
        ansy = slope1*(ansx - (double)p[0].x) + (double)p[0].y;
    }
    else{
        ansx = (double)(p[0].y - p[2].y)+ (double)p[2].x * slope2 - (double)p[0].x * slope1;
        ansx /= (slope2 - slope1);
        ansy = slope1*(ansx - (double)p[0].x) + (double)p[0].y;
    }

    cout << fixed;
    cout.precision(16);
    cout << ansx << " " << ansy << endl;
}

int ccw(dot p1,dot p2,dot p3){
    ll temp = p1.x*p2.y+p2.x*p3.y+p3.x*p1.y - (p1.y*p2.x+p2.y*p3.x+p3.y*p1.x);
    if(temp > 0) return 1;
    else if(temp < 0)   return -1;
    else return 0;
}

int main(){
    dot temp;

    cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y;
    cin >> p[2].x >> p[2].y >> p[3].x >> p[3].y;

    int check1 = ccw(p[0],p[2],p[1])*ccw(p[0],p[3],p[1]);
    int check2 = ccw(p[2],p[0],p[3])*ccw(p[2],p[1],p[3]);

    if(ccw(p[0],p[2],p[1])*ccw(p[0],p[3],p[1]) == 0 && ccw(p[2],p[0],p[3])*ccw(p[2],p[1],p[3]) == 0){
        if(ccw(p[0],p[2],p[1])==0 && ccw(p[0],p[3],p[1]) == 0 && ccw(p[2],p[0],p[3]) == 0 && ccw(p[2],p[1],p[3]) == 0){
            if(p[1]<p[0]){
                temp = p[1];
                p[1] = p[0];
                p[0] = temp;
            }
            if(p[3] < p[2]){
                temp = p[3];
                p[3] = p[2];
                p[2] = temp;
            }

            if(p[1] < p[2] || p[3] < p[0]){
                cout << "0" << endl;
            }
            else if(p[1] == p[2] && p[0] != p[3]){
                cout << "1" << endl;
                cout << p[1].x << " " << p[1].y << endl;
            }
            else if(p[0] == p[3] && p[1] != p[2]){
                cout << "1" << endl;
                cout << p[3].x << " " << p[3].y << endl;
            }
            else if(p[0] == p[1] && p[1] == p[2] && p[2] == p[3]){
                cout << "1" << endl;
                cout << p[0].x << " " << p[0].y << endl;
            }
            else{
                cout << "1" << endl;
            }
        }
        else{
            cout << "1" << endl;
            calculation();
        }
        
    }
    else if(check1 <= 0 && check2 <= 0){
        cout << "1" << endl;
        calculation();
    }
    else cout << "0" << endl;
    return 0;
}