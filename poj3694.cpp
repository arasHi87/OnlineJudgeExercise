#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxN=1e5+10;
struct Edge {
    int to, next;
};
int n, m, a, b, q, cnt, idx;
int low[maxN], dfn[maxN], head[maxN];