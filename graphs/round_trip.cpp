#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long

int start, cycleEnd;
vector<int> cycle;

bool dfs(int v, int parent, vector<vector<int>>& adj, vector<int>& vis, vector<int>& par) {
    vis[v] = 1;
    par[v] = parent;
    
    for (int u : adj[v]) {
        if (u == parent) continue;
        if (vis[u]) {
            start = u;
            cycleEnd = v;
            return true;
        }
        par[u] = v;
        if (dfs(u, v, adj, vis, par)) return true;
    }
    return false;
}

void printCycle(int start, int end, vector<int>& par) {
    vector<int> path;
    path.push_back(start);
    for (int v = end; v != start; v = par[v]) {
        path.push_back(v);
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    
    cout << path.size() << endl;
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;
}

signed main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<int> vis(n + 1, 0);
    vector<int> par(n + 1, -1);
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            if (dfs(i, -1, adj, vis, par)) {
                printCycle(start, cycleEnd, par);
                return 0;
            }
        }
    }
    
    cout << "IMPOSSIBLE" << endl;
    return 0;
}
