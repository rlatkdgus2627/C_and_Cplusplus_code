#include <bits/stdc++.h>

using namespace std;

int n;
double dot[1001][2];
double mindist = 1e32;
double ansX, ansY;

double distance(double x1, double x2, double y1, double y2){
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> dot[i][0] >> dot[i][1];
    }

    double dist;
    for(int i = 0; i < n; i++){
        dist = 0.0;
        for(int j = 0; j < n; j++){
            if(i == j)  continue;
            if(dist < distance(dot[i][0], dot[j][0], dot[i][1], dot[j][1])){
                dist = distance(dot[i][0], dot[j][0], dot[i][1], dot[j][1]);
            }
        }
            
        if(mindist > dist){
            mindist = dist;
            ansX = dot[i][0];
            ansY = dot[i][1];
        }
    }
    cout.precision(9);
    cout << ansX << " " << ansY;
    return 0;
}