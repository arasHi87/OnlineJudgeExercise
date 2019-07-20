#include <iostream>
#include <memory.h>
#include <queue>
#define maxN 1000 + 5
#define INF = -1
using namespace std;
typedef pair<int, int> P;

int maze[maxN][maxN]; // x, y
int n, m, ans = -1; // n => 列, m =>行
int s1, s2, e1, e2;
int dtx[4] = {-1, 1, 0, 0}, dty[4] = {0, 0, -1, 1};
int d[maxN][maxN];
queue<P> path;

void bfs() {
    P start(s1, s2);
    d[s1][s2] = 0;
    path.push(start);
    // cout << "s1 : " << s1 << " s2 : " << s2 << '\n';
    while (!path.empty()) {
        int dx = path.front().first, dy = path.front().second;
        // cout << "dx " << dx << " dy : " << dy << '\n';
        path.pop();
        for (int i = 0; i < 4; i++) {
            int nx = dx + dtx[i], ny = dy + dty[i];
            // cout << "jx : " << nx << " jy : " << ny << '\n';
            // cout << "It's distance : " << d[nx][ny] << '\n';
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                if(maze[nx][ny] != 0 || d[nx][ny] != -1) continue;
                // cout << "nx : " << nx << " ny : " << ny << '\n';
                P next(nx, ny);
                path.push(next);
                d[nx][ny] = d[dx][dy] + 1;
                if (nx == e1 && ny == e2) { ans = d[nx][ny]; return;}
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
    cin >> s1 >> s2 >> e1 >> e2;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++){
    //         cout << maze[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    memset(d, -1, sizeof(d));
    bfs();
    cout << ans << '\n';
}