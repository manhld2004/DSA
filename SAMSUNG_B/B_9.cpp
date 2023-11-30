#include <bits/stdc++.h>
using namespace std;

int n, m;
set<int> adj[100001];
int inDegree[100001];
int outDegree[100001];

bool isConnected() {
    vector<bool> visited(n + 1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && (inDegree[i] > 0 || outDegree[i] > 0)) {
            return false;
        }
    }
    return true;
}

bool hasEulerianPath() {
    int startNodes = 0, endNodes = 0;
    for (int i = 1; i <= n; i++) {
        int diff = inDegree[i] - outDegree[i];
        if (abs(diff) > 1) {
            return false;
        } else if (diff == 1) {
            startNodes++;
        } else if (diff == -1) {
            endNodes++;
        }
    }
    return (startNodes == endNodes) || (startNodes == 1 && endNodes == 1);
}

void eulerianPath(int v) {
    stack<int> st;
    vector<int> EP;

    st.push(v);
    while (!st.empty()) {
        int x = st.top();
        if (!adj[x].empty()) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            inDegree[y]--;
            outDegree[x]--;
        } else {
            st.pop();
            EP.push_back(x);
        }
    }
    reverse(begin(EP), end(EP));
    for (int x : EP) {
        cout << x << " ";
    }
}

int main() {

    return 0;
}
