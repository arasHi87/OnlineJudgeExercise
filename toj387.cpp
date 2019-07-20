#include <cstdio>
using namespace std;
typedef long long LL;

int main() {
    LL A, L, cnt=0;
    scanf("%lld%lld", &A, &L);
    L*=L;
    while (A<L)
        A<<=1, cnt++;
    printf("%lld\n", cnt);
}