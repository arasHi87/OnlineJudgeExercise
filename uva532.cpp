#include <iostream>
#include <sstream>
#include <cstring>
#include <tuple>
#include <algorithm>
// #define local 
using namespace std;
int mp[35][35][35], ans=0;
int d=[6][3]={{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
auto st = make_tuple(0, 0, 0);
auto ed = make_tuple(0, 0, 0);
char opt[1];
void bfs(int x, int y, int z) {
	for (int i=0;i<6;i++) {
		int nx=x+d[0]
	}
}
int main() {
	#ifdef local
		freopen("in.in", "r", stdin);
	#endif
	int L, R, C;
	scanf("%d%d%d", &L, &R, &C);
	cout<<L<<R<<C<<endl; 
	memset(mp, 0, sizeof mp);
	for (int i = 1; i <= L; i++) {
		for (int j = 1; j <= R; j++) {
			for (int k=1;k<=C;k++) {
				scanf("%1s", opt);
				auto tmp=make_tuple(i, j, k);
				if (opt[0]=='S') st=tmp;
				else if (opt[0]=='E') ed=tmp;
				else if (opt[0]=='#') mp[i][j][k]=0;
				else mp[i][j][k]=1;
			}
		}
	}
	printf("hi\n");
	printf("%d %d %d\n", get<0>(st), get<1>(st), get<2>(st));
	printf("%d %d %d\n", get<0>(ed), get<1>(ed), get<2>(ed));
}