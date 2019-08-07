#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n;                // max number of nodes
vi D;                 // D[i] is distance from source to each node i
vector<vector<ii>> G; // graph, adjacency list i -> pair<int, int>, where first
                      // is weight, second is node index

void dijkstra(int src) {
    // Initialize distance to special value, -1.  Better to do this rather than
    // a large value for "infinity"; it's easy to get wrong.
    D.assign(n, -1);

    // By default, priority queue in C++ implemented as a max heap, but we want
    // the smallest at the top (i.e. shortest distance/weight)
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, src);
    while (!pq.empty()) {
        int u = pq.top().second, d = pq.top().first;
        pq.pop();

        // Very important, if we've seen this node before, skip checking its
        // children. Otherwise complexity will be wrong!
        if (D[u] != -1) continue;

        // Update the distance, push neighbors onto the priority queue
        D[u] = d;
        for (auto &i : G[u]) {
            int v = i.second, w = i.first;
            pq.emplace(d + w, v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}
