#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	// Adjacency list of (neighbour, edge weight)
	vector<vector<pair<int, int>>> neighbors(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		neighbors[a - 1].push_back({b - 1, c});
	}

	// Initially set all distances to infinity
	vector<long long> dist(n, LLONG_MAX);

	// Dijkstra's algorithm
	using T = pair<long long, int>;
	priority_queue<T, vector<T>, greater<T>> pq;

	int start = 0;
	dist[start] = 0;  // The shortest path from a node to itself is 0
	pq.push({0, start});

	while (!pq.empty()) {
		const auto [cdist, node] = pq.top();
		pq.pop();
		if (cdist != dist[node]) { continue; }
		for (const pair<int, int> &i : neighbors[node]) {
			// If we can reach a neighbouring node faster,
			// we update its minimum distance
			if (cdist + i.second < dist[i.first]) {
				pq.push({dist[i.first] = cdist + i.second, i.first});
			}
		}
	}

	for (int i = 0; i < n - 1; i++) { cout << dist[i] << ' '; }
	cout << dist[n - 1] << endl;
}