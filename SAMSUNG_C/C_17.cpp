#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int V; 
    int E; 
    vector<vector<int>> edges;

public:
    Graph(int v, int e) : V(v), E(e) {
        edges.resize(E, vector<int>(3, 0));
    }

    void addEdge(int id, int u, int v, int w) {
        edges[id][0] = u;
        edges[id][1] = v;
        edges[id][2] = w;
    }

    int find(vector<int>& parent, int i)
    {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int>& parent, int x, int y) 
    {
        parent[find(parent, x)] = find(parent, y);
    }

    vector<vector<int>> vyssotsky() 
    {
        vector<vector<int>> ans;
        int i = 0, cnt = 0;

        sort(edges.begin(), edges.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[2] < b[2];
             });

        vector<int> parent(V);
        iota(parent.begin(), parent.end(), 0);  // Initialize parent array

        while (cnt < V - 1 && i < E) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            i++;

            int x = find(parent, u);
            int y = find(parent, v);

            if (x != y) {
                cnt++;
                ans.push_back({u, v, w});
                Union(parent, x, y);
            }
        }

        return ans;
    }
};


int main() {

    return 0;
}