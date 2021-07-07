#include <bits/stdc++.h>
#define INF 1e9

using namespace std;

int n, m, x;
vector<pair<int, int> > graph[1001];
int ans = 0;

class cmp{
public:
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        return a.second > b.second;
    }
};

int dijkstra(int s, int e){
    priority_queue<pair<int,int>, vector<pair<int,int> >, cmp> pq;
    int u, d, x, y;
	vector<int> dist(n + 1, INF);
	dist[s] = 0;
	pq.push(make_pair(s, 0));
	for (int i = 1; i <= n; i++) {
		pq.push(make_pair(i, INF));
	}
	while (!pq.empty()) {
		u = pq.top().first; d = pq.top().second;
		pq.pop();
		if (d > dist[u])	continue;
		for (int i = 0; i < graph[u].size(); i++) {
			x = graph[u][i].first;
			y = graph[u][i].second;
			if (dist[x] > dist[u] + y) {
				dist[x] = dist[u] + y;
				pq.push(make_pair(x, dist[x]));
			}
		}
	}
	return dist[e];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int s, e, w;
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++){
        cin >> s >> e >> w;
        graph[s].push_back(make_pair(e,w));
    }

    for(int i = 1; i <= n; i++){
        int path1 = dijkstra(i,x);
        int path2 = dijkstra(x,i);
        if(ans < path1 + path2) ans = path1 + path2;
    }
    cout << ans;
    return 0;
}