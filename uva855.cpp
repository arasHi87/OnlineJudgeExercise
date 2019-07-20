#include <iostream>
#include <algorithm>
using namespace std;
const int maxN=5e4+10;

int x[maxN], y[maxN];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int s, a, f;
        scanf("%d%d%d", &s, &a, &f);
        for (int i=0;i<f;i++) scanf("%d%d", &x[i], &y[i]);
        sort(x, x+f);
        sort(y, y+f);
        printf("(Street: %d, Avenue: %d)\n", x[(f-1)/2], y[(f-1)/2]);
    }
}