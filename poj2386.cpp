#include <iostream>
using namespace std;
#define MAX_M 100
#define MAX_N 100

int m, n;
char field[MAX_N + 5][MAX_M + 5];

void dfs( int x, int y ) {
    field[x][y] = '.';
    for ( int dx = -1; dx <= 1; dx++ ) {
        for ( int dy = -1; dy <= 1; dy++ ) {
            int nx = x + dx, ny = y + dy;
            if ( 0 <= nx && nx < n && 0 <= ny && ny < m && field[nx][ny] == 'W' ) dfs(nx, ny);
        }
    }
    return;
}

void solve() {
    int res = 0;
    for ( int i = 0; i < n; i++ ) {
        for ( int j = 0; j < m; j++ ) {
            if ( field[i][j] == 'W' ) {
                dfs(i, j);
                res++;
            }
        }
    }
    cout << res << '\n';
}

int main() {
    cin >> n >> m;
    for ( int i = 0; i < n; i++ ) { 
        for ( int j = 0; j < m; j++ ) {
            field[i][j] = getchar();
        }
        getchar();
    }
    solve();
}