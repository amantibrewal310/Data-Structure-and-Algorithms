#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#define DEBUG(...) debug(#__VA_ARGS__, __VA_ARGS__);
#else
#define DEBUG(...) 6;
#endif

template <typename T, typename S>
ostream &operator<<(ostream &os, const pair<T, S> &p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename C, typename T = decay<decltype(*begin(declval<C>()))>, typename enable_if<!is_same<C, string>::value>::type * = nullptr>
ostream &operator<<(ostream &os, const C &c) {
    bool f = true;
    os << "[";
    for (const auto &x : c) {
        if (!f) os << ", ";
        f = false;
        os << x;
    }
    return os << "]";
}
template <typename T>
void debug(string s, T x) { cerr << s << " = " << x << "\n"; }
template <typename T, typename... Args>
void debug(string s, T x, Args... args) {
    cerr << s.substr(0, s.find(',')) << " = " << x << " | ";
    debug(s.substr(s.find(',') + 2), args...);
}

vector<string> v;
vector<pair<int, int>> swaps;
unordered_map<string, int> mp;

vector<int> bfs(int s) {
    vector<int> dist(v.size(), -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (dist[u] == 8)
            continue;
        string cur = v[u];
        for (auto [i, j] : swaps) {
            swap(cur[i], cur[j]);
            int x = mp[cur];
            if (dist[x] == -1) {
                dist[x] = dist[u] + 1;
                q.push(x);
            }
            swap(cur[i], cur[j]);
        }
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    for (int i = 0; i < 9; i++) {
        int x;
        cin >> x;
        a += (char)(x + '0');
    }

    string s = "123456789";
    do {
        mp[s] = v.size();
        v.push_back(s);
    } while (next_permutation(s.begin(), s.end()));
    int goal = mp[a];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++) {
            if (i < 2)
                swaps.emplace_back(3 * i + j, 3 * (i + 1) + j);
            if (j < 2)
                swaps.emplace_back(3 * i + j, 3 * i + j + 1);
        }

    vector<int> dist1 = bfs(0), dist2 = bfs(goal);
    int ret = INT_MAX;
    for (int i = 0; i < (int)dist1.size(); i++)
        if (dist1[i] != -1 && dist2[i] != -1)
            ret = min(ret, dist1[i] + dist2[i]);
    cout << ret << "\n";

    return 0;
}