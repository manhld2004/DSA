#include<bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int source, destination, weight;
};

void efficientDijkstra(const vector<Edge>& edges, int numVertices, int source, int C) {
    vector<int> distances(C + 1, INF);
    distances[0] = 0;

    for (int i = 0; i <= C; ++i) {
        int minDist = INF;
        int u = -1;

        // Tìm đỉnh tiếp theo có độ dài ngắn nhất
        for (int v = 0; v < numVertices; ++v) {
            if (distances[v] < minDist) {
                minDist = distances[v];
                u = v;
            }
        }

        // Nếu không còn đỉnh nào có thể thêm vào đường đi ngắn nhất, thoát khỏi vòng lặp
        if (u == -1) {
            break;
        }

        // Cập nhật đường đi ngắn nhất
        for (const Edge& edge : edges) {
            if (edge.source == u) {
                int newDist = distances[u] + edge.weight;
                if (newDist < distances[edge.destination] && newDist <= C) {
                    distances[edge.destination] = newDist;
                }
            }
        }

        // Đánh dấu đỉnh đã xét
        distances[u] = INF;
    }

    // In ra kết quả
    cout << "Shortest paths from vertex " << source << ":\n";
    for (int i = 0; i < numVertices; ++i) {
        if (i != source) {
            if (distances[i] == INF) {
                cout << "No path to vertex " << i << "\n";
            } else {
                cout << "To vertex " << i << ": " << distances[i] << "\n";
            }
        }
    }
}

int main() {

    return 0;
}
