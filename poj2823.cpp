#include <cstdio>
using namespace std;
const int maxN=1e6+10;
int n, k, arr[maxN], que[maxN];
inline void FindMin() {
    int L=1, R=0;
    for (int i=0;i<k-1;i++) {
        while (L<=R && arr[que[R]]>arr[i]) R--;
        que[++R]=i;
    }
    for (int i=k-1;i<n;i++) {
        if (que[L]<=i-k) L++;
        while (L<=R && arr[que[R]]>arr[i]) R--;
        que[++R]=i;
        printf("%d ", arr[que[L]]);
    }
    puts("");
}
inline void FindMax() {
    int L=1, R=0;
    for (int i=0;i<k-1;i++) {
        while (L<=R && arr[que[R]]<arr[i]) R--;
        que[++R]=i;
    }
    for (int i=k-1;i<n;i++) {
        if (que[L]<=i-k) L++;
        while (L<=R && arr[que[R]]<arr[i]) R--;
        que[++R]=i;
        printf("%d ", arr[que[L]]);
    }
    puts("");
}
int main() {
    #ifdef local
        freopen("in", "r", stdin);
    #endif
    while (~scanf("%d%d", &n, &k)) {
        for (int i=0;i<n;i++)
            scanf("%d", arr+i);
        FindMin(), FindMax();
    }
}