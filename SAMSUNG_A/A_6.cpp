#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10002];
bool ktra = 1;

void DFS(int node, vector<bool>& visited, vector<int>& discovery, vector<int>& low, vector<int>& parent) {
    static int cnt = 0;
    int children = 0;

    visited[node] = 1;
    discovery[node] = low[node] = cnt++;

    for (auto neighbor : graph[node]) {
        if (!visited[neighbor]) {
            children++;
            parent[neighbor] = node;
            DFS(neighbor, visited, discovery, low, parent);

            low[node] = min(low[node], low[neighbor]);

            if (low[neighbor] > discovery[node]) {
                ktra = 0;
                cout << node << " - " << neighbor << endl;
            }
        } else if (neighbor != parent[node]) {
            low[node] = min(low[node], discovery[neighbor]);
        }
    }
}

void findBridges(int vertices) {
    vector<bool> visited(vertices, false);
    vector<int> discovery(vertices, 0);
    vector<int> low(vertices, 0);
    vector<int> parent(vertices, -1);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i, visited, discovery, low, parent);
        }
    }
}

int main() {
    graph[1].push_back(2);
    graph[2].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[4].push_back(5);
    graph[5].push_back(4);
    graph[5].push_back(6);
    graph[6].push_back(5);
 
    vector<bool> visited(7, false);
    vector<int> discovery(7, 0);
    vector<int> low(7, 0);
    vector<int> parent(7, -1);
 
    for (int i = 1; i <= 6; i++) {
        if (!visited[i]) {
            DFS(i, visited, discovery, low, parent);
        }
    }
    return 0;
}
