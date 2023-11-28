#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int source, destination, weight;
};

void bellmanFord(const vector<Edge>& edges, int numVertices, int source, vector<int>& distances) {
    distances.assign(numVertices, INF);
    distances[source] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (const Edge& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distances[u] != INF && distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
            }
        }
    }
}

int findCriticalEdge(const vector<Edge>& edges, int numVertices, int source, int target) {
    vector<int> distances;
    bellmanFord(edges, numVertices, source, distances);

    int maxIncrease = 0;
    int criticalEdge = -1;

    for (const Edge& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distances[u] != INF && distances[u] + weight < distances[v]) {
            int increase = distances[v] - (distances[u] + weight);
            if (increase > maxIncrease) {
                maxIncrease = increase;
                criticalEdge = v;
            }
        }
    }

    return criticalEdge;
}

int main() {

    return 0;
}
