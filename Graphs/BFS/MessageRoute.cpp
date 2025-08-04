// Link to the Question (Copy this in browser) : https://cses.fi/problemset/task/1667
// Concepts Used : Breadth first Search




#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

// BFS function to find shortest path from node 1 to node n
bool findRoute(unordered_map<int, vector<int>> &adj, int n, int &minComputers, vector<int> &result) {
    vector<bool> visited(n+1, false);
    vector<int> parent(n+1, -1);
    queue<int> que;

    que.push(1);
    visited[1] = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = node;
                que.push(neighbor);
            }
        }
    }

    // If destination node n is not visited
    if (!visited[n]) return false;

    // Reconstruct path from n to 1 using parent[]
    int current = n;
    while (current != -1) {
        result.push_back(current);
        current = parent[current];
    }

    reverse(result.begin(), result.end()); // reverse path to go from 1 → n
    minComputers = result.size() - 1; // edges (or steps taken)
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a); // undirected graph
    }

    vector<int> result;
    int minComputers = 0;

    if (findRoute(adj, n, minComputers, result)) {
        cout << 1 + minComputers << endl;
        for (int res : result) {
            cout << res << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}
