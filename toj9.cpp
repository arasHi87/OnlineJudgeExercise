#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;
typedef pair<int, int> P;

struct Node {
    int high;
    int already = INF;
    vector<int> to;
};

int min_high = 0;
vector<struct Node> node;
queue<P> path;

int dfs(int s, int time_) {
    int now_high = node[s].high, next_node = -1;
    for (auto it = node[s].to.begin(); it != node[s].to.end(); it++) {
        if (node[*it].already != INF) continue;
        node[*it].already = 0;
        if (node[*it].high < now_high) { now_high = node[*it].high; next_node = *it; }
    }
    if (next_node < 0 && node[s].high == min_high) return time_;
    if (next_node < 0 && node[s].high != min_high) return -1;
    time_++;
    if (node[next_node].high == min_high) return time_;
    dfs(next_node, time_);
}

int bfs(int s) {
    P start(s, 0);
    path.push(start);
    while (path.size()) {
        int now_node = path.front().first;
        int time_ = path.front().second;
        path.pop();
        if (node[now_node].high == min_high) return time_;
        for (auto it = node[now_node].to.begin(); it != node[now_node].to.end(); it++) {
            if (node[*it].already != INF) continue;
            node[*it].already = 0;
            P next(*it, time_+6);
            path.push(next);
        }
    } 
    return -1;
}

void init_node() {
    for (int i = 0; i < node.size(); i++) {
        node[i].already = INF;
    }
}

void clear_que (queue<P> & que) {
    queue<P> emp;
    swap(que, emp);
}

int abs(int x) {
    return x < 0 ? -x : x;
}

int main() {
    int t;
    cin >> t;
    for (int j = 1; j <= t; j++) {
        int n, m , s;
        Node input;
        cin >> n >> m >> s;
        if (!n) return 0;
        for (int i = 0; i < n; i++) {
            cin >> input.high;
            node.push_back(input);
            if (i == 0) min_high = input.high;
            else if (input.high < min_high) min_high = input.high;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            node[a].to.push_back(b);
            node[b].to.push_back(a);
        }
        int dfs_time = dfs(s, -1);
        init_node();
        int bfs_time = bfs(s);
        init_node();
        if (dfs_time > -1) dfs_time++;
        node.clear();
        clear_que(path);
        cout << "Case #" << j << ": ";
        if (bfs_time == -1 && dfs_time == -1) cout << "Call 119!" << '\n';
        if (dfs_time == -1) dfs_time = 0;
        if (bfs_time == -1) bfs_time = 0;
        else cout << abs(bfs_time - dfs_time) << '\n';
    }
    return 0;
}