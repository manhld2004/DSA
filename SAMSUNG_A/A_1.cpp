#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<set<int>> adj;
vector<int> degree;

void euler(int v) {
    stack<int> st;
    vector<int> vt;
    st.push(v);
    while (!st.empty()) {
        int x = st.top();
        if (!adj[x].empty()) {
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        } else {
            st.pop();
            vt.push_back(x);
        }
    }
    reverse(begin(vt), end(vt));
    for (int x : vt) {
        cout << x << " ";
    }
}

bool checkInOut() {
    return all_of(begin(degree) + 1, end(degree), [](int d) { return d % 2 == 0; });
}

bool isConnected() {
    queue<int> q;
    vector<bool> check(n + 1, false);
    
    q.push(1);
    check[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        if (!check[v]) 
        {
            check[v] = true;
            q.push(v);    
        }        
    }
    return all_of(begin(check) + 1, end(check), [](bool v) { return v; });
}

bool hasEuler() {
    return isConnected() && checkInOut();
}

bool hasHamilton() {
    return isConnected() && all_of(begin(degree) + 1, end(degree), [&](int d) { return d >= n / 2; });
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    degree.resize(n + 1, 0);

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
        degree[x]++;
        degree[y]++;
    }

    if (hasEuler()) {
        euler(1);
    } else {
        cout << "Khong ton tai chu trinh Euler";
    }
    cout << endl;

    if (hasHamilton()) {
        cout << "Co ton tai chu trinh Hamilton";
    } else {
        cout << "Khong ton tai chu trinh Hamilton";
    }

    return 0;
}
