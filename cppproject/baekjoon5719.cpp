#include <bits/stdc++.h>

#define INF 2000000000

#define p pair<int, int>

using namespace std;

struct cmp {
	bool operator()(p a, p b) {
		return a.second > b.second;
	}
};

int n, m;
int s, g;

vector<vector<p> >edge(501);
priority_queue<p, vector<p>, cmp> pq;
vector<int>track [501];
bool deleted[501][501];
bool visited[501];
bool impossible;
int ans;
int shortcut;

void input() {
	int x, y, d;

    //init
	for (int i = 0; i < 501; i++) {
		track[i].clear();
	}
	memset(deleted, 0, sizeof(deleted));
    memset(visited, 0, sizeof(visited));
	impossible = false;
	edge.clear();
	edge = vector<vector<p> >(501);

    //input
	scanf("%d %d", &n, &m);
	if (n == 0 && m == 0) {
		return;
	}
	scanf("%d %d", &s, &g);

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &d);

		edge[x].push_back(make_pair(y, d));
	}
}

int dijkstra(int start, int goal) {
	int u, d, x, y;
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	pq.push(make_pair(start, 0));

	for (int i = 0; i < n; i++) {
		if(i != start) pq.push(make_pair(i, INF));
	}
	while (!pq.empty()) {
		u = pq.top().first; d = pq.top().second;
		pq.pop();
		if (d > dist[u])	continue;
		for (int i = 0; i < edge[u].size(); i++) {
			x = edge[u][i].first;
			y = edge[u][i].second;
			if (dist[x] > dist[u] + y && !deleted[u][x]) {
				dist[x] = dist[u] + y;
				track[x].clear();
				track[x].push_back(u);
				pq.push(make_pair(x, dist[x]));
			}
			if (dist[x] == dist[u] + y && !deleted[u][x]) {
				track[x].push_back(u);
			}
		}
	}
	
	return dist[goal];
}

void remove(int x) {
	if (x == s || visited[x] == true)	return;
    visited[x] = true;
	for (int i = 0; i < track[x].size(); i++) {
        deleted[track[x][i]][x]=true;
		remove(track[x][i]);
	}
}

void solve() {
	if (dijkstra(s, g) == INF) {
		impossible = true;
		return;
	}
	remove(g);
	ans = dijkstra(s, g);
}

void output() {
	if (impossible)	printf("-1\n");
	else printf("%d\n", ans == INF ? -1 : ans);
}

int main()
{
	while(true){
		input();
		if (n == 0 && m == 0) {
			break;
		}
		solve();
		output();
	}
	return 0;
}