#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> Edge; // {node, value}
typedef vector<vector<Edge>> Graph;

const int INF = INT_MAX;

void bellmanFord(const Graph& graph, int source, vector<int>& distances) {
    int numVertices = graph.size();
    distances.resize(numVertices, INF);
    distances[source] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        for (int u = 0; u < numVertices; ++u) {
            for (const Edge& edge : graph[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (distances[u] != INF && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                }
            }
        }
    }
}

void reweightGraph(Graph& graph, const vector<int>& pi) {
    int numVertices = graph.size();

    for (int u = 0; u < numVertices; ++u) {
        for (Edge& edge : graph[u]) {
            int v = edge.first;
            edge.second = edge.second + pi[u] - pi[v];
        }
    }
}

vector<vector<int>> dijkstraAllPairs(const Graph& graph) {
    int numVertices = graph.size();
    vector<vector<int>> allDistances(numVertices, vector<int>(numVertices, INF));

    for (int source = 0; source < numVertices; ++source) {
        vector<int> distances;
        bellmanFord(graph, source, distances);
        for (int target = 0; target < numVertices; ++target) {
            allDistances[source][target] = distances[target];
        }
    }

    return allDistances;
}

int main() {

    return 0;
}
