#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int maxN=1e5+1;

map<int, int> mp;
queue<int> que;

int main() {
    int n;
    while (~scanf("%d", &n)) {
        auto f = mp.find(n);
        if (f == mp.end()) { mp[n] = 1; que.push(n); }
        else { mp[n]++; }
    }
    while (!que.empty()) {
        int t = que.front(); que.pop();
        printf("%d %d\n", t, mp[t]);
    }
}