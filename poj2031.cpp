#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
using namespace std;
const int maxN=1e2+10;
const int INF=0x3f3f3f3f;
struct Edge {
    int to;
    double val;
    Edge(int a, double b): to(a), val(b) {};
    bool operator < (const Edge &rhs) const {
        return val>rhs.val;
    }
};
struct Node {
    double x, y, z, r;
    Node(double _x, double _y, double _z, double _r):
        x(_x), y(_y), z(_z), r(_r) {}; 
};
int n, vis[maxN];
double a, b, c, d, ans, cnt;
double G[maxN][maxN];
vector<Node> v;
priority_queue<Edge> pq;
double prim(int st) {
    for (int i=0;i<=n;i++) vis[i]=0;
    while (!pq.empty()) pq.pop();
    ans=0, vis[st]=1;
    for (int i=0;i<n-1;i++) {
        for (int j=1;j<=n;j++)
            if (!vis[j])
                pq.push(Edge(j, G[st][j]));
        while (!pq.empty() && vis[pq.top().to]) pq.pop();
        if (pq.empty()) break;
        st=pq.top().to, ans+=pq.top().val, vis[pq.top().to]=1, pq.pop();
    }
    return ans;
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d", &n) && n) {
        v.clear(), cnt=0;
        for (int i=0;i<=n;i++)
            for (int j=0;j<=n;j++)
                G[i][j]=INF;
        for (int i=1;i<=n;i++) {
            scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
            v.push_back(Node(a, b, c, d));
        }
        for (int i=0;i<(int)v.size();i++) {
            for (int j=0;j<(int)v.size();j++) {
                if (i==j) continue;
                double tmp=sqrt(pow(v[i].x-v[j].x, 2)+pow(v[i].y-v[j].y, 2)+pow(v[i].z-v[j].z, 2))-v[i].r-v[j].r;
                // printf("%d to %d is %lf\n", i+1, j+1, tmp),
                G[i+1][j+1]=G[j+1][i+1]=max(tmp, 0.0);
            }
        }
        printf("%0.03f\n", prim(1));
    }
}