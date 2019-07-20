#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    long long a, b;
    while (~scanf("%lld%lld", &a, &b)) {
        if (a>b) swap(a, b);
        printf("%lld\n", abs(b-a));
    }
}