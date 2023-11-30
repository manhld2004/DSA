#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Subset {
    int parent, rank;
};

class Graph {
private:
    int V, E;
    vector<Edge> edges;
    Subset* subsets;  

public:
    Graph(int v, int ed);
    void addEdge(int src, int dest, int weight);
    int find(int i);
    void Union(int x, int y);
    void kruskal();
    void DFS(int u, vector<bool>& visited, vector<vector<int>>& adj);
    void findCE();
};

Graph::Graph(int v, int ed) {
    V = v;
    E = ed;
    subsets = new Subset[V];
}

void Graph::addEdge(int src, int dest, int weight) {
    Edge edge = {src, dest, weight};
    edges.push_back(edge);
}

int Graph::find(int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets[i].parent);

    return subsets[i].parent;
}

void Graph::Union(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Graph::kruskal() {
    vector<Edge> result;

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });

    int i = 0, e = 0;

    while (e < V - 1 && i < E) {
        Edge next_edge = edges[i++];
        int x = find(next_edge.src);
        int y = find(next_edge.dest);

        if (x != y) {
            result.push_back(next_edge);
            Union(x, y);
            e++;
        }
    }

    for (Edge edge : result) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
}

void Graph::DFS(int u, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            DFS(v, visited, adj);
        }
    }
}

void Graph::findCE() {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight < b.weight;
    });
    vector<int> lastid(V, -1);
    for (int i = 0; i < E; i++) {
        int set1 = find(edges[i].src);
        int set2 = find(edges[i].dest);

        if (set1 != set2) {
            lastid[set1] = i;
            lastid[set2] = i;
            Union(set1, set2);
        }
    }

    vector<vector<int>> adj(V);
    for (Edge edge : edges) {
        adj[edge.src].push_back(edge.dest);
        adj[edge.dest].push_back(edge.src);
    }

    for (int i = 0; i < E; i++) {
        if (i == lastid[i]) {
            vector<bool> visited(V, false);
            DFS(edges[i].src, visited, adj);

            if (!visited[edges[i].dest]) {
                cout << edges[i].src << " - " << edges[i].dest << " : " << edges[i].weight << endl;
            }
        }
    }
}

int main() {

    return 0;
}
