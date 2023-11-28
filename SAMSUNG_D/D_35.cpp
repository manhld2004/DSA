#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair<int, int> ii;

const int INF = numeric_limits<int>::max();

// Định nghĩa một đỉnh trong đồ thị
struct Vertex {
    int id;
    vector<ii> adj; // {destination, weight}
};

// Hàm Dijkstra để tính toán đường đi ngắn nhất
void dijkstra(const vector<Vertex>& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();
    distances.assign(numVertices, INF);
    distances[source] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().se;
        int distU = pq.top().fi;
        pq.pop();

        if (distU > distances[u]) {
            continue;
        }

        for (const auto& edge : graph[u].adj) {
            int v = edge.fi;
            int weight = edge.se;

            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

// Hàm để tính toán đường đi bitonic ngắn nhất
void bitonicShortestPath(const vector<Vertex>& graph, int source) {
    int numVertices = graph.size();

    // Tính toán đường đi ngắn nhất với các cạnh tăng dần
    vector<int> increasingDistances;
    dijkstra(graph, source, increasingDistances);

    vector<int> decreasingDistances;
    dijkstra(graph, source, decreasingDistances);

    cout << "Bitonic shortest paths from vertex " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        if (i != source) {
            if (increasingDistances[i] == INF || decreasingDistances[i] == INF) {
                cout << "No bitonic path to vertex " << i << "\n";
            } else {
                cout << "To vertex " << i << ": " << increasingDistances[i] + decreasingDistances[i] << "\n";
            }
        }
    }
}

int main() {
}
