#include <iostream>
#include <vector>

using namespace std;
#define int long long
bool fl = false;

void dfs(int i, vector<int>& vis, vector<vector<int>>& adj, vector<int>& col) {
    vis[i] = 1;

    for (auto it : adj[i]) {
        if (vis[it] == 0) { // If not visited
            col[it] = 1 - col[i]; // Assign opposite color
            dfs(it, vis, adj, col); // Recur for the neighbor
        } else if (col[it] == col[i]) { // Check for color conflict
            fl = true;
            return;
        }
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> col(n + 1, -1); // -1 means uncolored

    // Read edges and construct the adjacency list
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Run DFS for each component of the graph
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) { // If not visited
            col[i] = 0; // Start coloring with 0
            dfs(i, vis, adj, col);
            if (fl) { // If a conflict is found
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
        }
    }

    // Output the color of each node (1-based index for output)
    for (int i = 1; i <= n; ++i) {
        cout << (col[i] + 1) << " "; // Convert 0-based index to 1-based output
    }
    cout << endl;

    return 0;
}
