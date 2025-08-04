// Link to the Question (Copy this in browser) : https://cses.fi/problemset/task/1675
// Concepts Used : Minimum Spanning Tree , DSU , UNION-FIND

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> dsu_rank;

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);  // Path compression
}

//Union by Rank
void UNION(int x, int y) {
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent != y_parent) {
        if (dsu_rank[x_parent] > dsu_rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (dsu_rank[y_parent] > dsu_rank[x_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[y_parent] = x_parent;
            dsu_rank[x_parent]++;
        }
    }
}

long long kruskal(vector<vector<int>> &edges, int n) {
    long long totalCost = 0;
    int countEdges = 0;

    for (const vector<int>& edge : edges) {
        int a = edge[0];
        int b = edge[1];
        int cost = edge[2];

        if (find(a) != find(b)) {
            UNION(a, b);
            totalCost += cost;
            countEdges++;
        }

        if (countEdges == n - 1) break;  // MST completed
    }

    return (countEdges == n - 1) ? totalCost : -1;  // If not connected
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    // Initialize DSU
    parent.resize(n + 1);
    dsu_rank.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Sort edges by cost
    sort(edges.begin(), edges.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
    });

    long long minCost = kruskal(edges, n);

    if (minCost == -1) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    cout << minCost << "\n";
    return 0;
}
