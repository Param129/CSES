#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define int long long

using namespace std;

signed main() {
    int n, m;
    cin >> n >> m;

    // Initialize the distance vector with infinity
    vector<int> dist(n + 1, LLONG_MAX);
    vector<vector<pair<int, int>>> adj(n + 1);

    // Read the edges
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        // Store the edge in the adjacency list
        adj[a].push_back({b, c});
    }

    // Priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // Start from node 1 (assuming nodes are 1-indexed)
    pq.push({0, 1});
    dist[1] = 0;

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int node = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip if the distance is not optimal
        if (d > dist[node]) continue;

        for (auto it : adj[node]) {
            int adjn = it.first;
            int wt = it.second;
            if (dist[adjn] > d + wt) {
                dist[adjn] = d + wt;
                pq.push({dist[adjn], adjn});
            }
        }
    }

    // Print distances from node 1
    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) {
            cout << "INF ";
        } else {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
