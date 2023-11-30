#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int src, vector<vector<int>>& adj) {
    queue<int> q;
    vector<int> ans;
    vector<int> inCnt(src, 0);

    for (const vector<int>& neighbors : adj) {
        for (int neighbor : neighbors) {
            inCnt[neighbor]++;
        }
    }

    for (int i = 0; i < src; i++) {
        if (inCnt[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        ans.push_back(vertex);

        for (int neighbor : adj[vertex]) {
            inCnt[neighbor]--;
            if (inCnt[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return ans;
}

int main() {

    return 0;
}
