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

public:
    Graph(int v, int ed);
    void add(int src, int dest, int weight);
    int find(Subset subsets[], int i);
    void Union(Subset subsets[], int x, int y);
    void boruvka();
};

Graph::Graph(int v, int ed) {
    V = v;
    E = ed;
}

void Graph::add(int src, int dest, int weight) {
    Edge edge = {src, dest, weight};
    edges.push_back(edge);
}

int Graph::find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Graph::Union(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void Graph::boruvka() {
    vector<Edge> ans;
    Subset* subsets = new Subset[V];
   

    for (int v = 0; v < V; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int numTrees = V;

    while (numTrees > 1) {
        vector<int> lowest(V, -1);

        for (int i = 0; i < E; i++) {
            int set1 = find(subsets, edges[i].src);
            int set2 = find(subsets, edges[i].dest);

            if (set1 != set2) {
                if (lowest[set1] == -1 || edges[lowest[set1]].weight > edges[i].weight)
                    lowest[set1] = i;

                if (lowest[set2] == -1 || edges[lowest[set2]].weight > edges[i].weight)
                    lowest[set2] = i;
            }
        }

        for (int i = 0; i < V; i++) {
            if (lowest[i] != -1) {
                int set1 = find(subsets, edges[lowest[i]].src);
                int set2 = find(subsets, edges[lowest[i]].dest);

                if (set1 != set2) {
                    ans.push_back(edges[lowest[i]]);
                    Union(subsets, set1, set2);
                    numTrees--;
                }
            }
        }
    }

    for (Edge edge : ans) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }

    delete[] subsets;
}

int main() {

    return 0;
}