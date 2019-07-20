#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 1000005

int a[maxn];

int main() {
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ )
        cin >> a[i];
    sort(a, a + n);
    int k, q;
    cin >> k;
    for ( int i = 0; i < k; i++ )
    {
        cin >> q;
        cout << lower_bound ( a, a + n, q + 1)-lower_bound ( a, a + n, q) << '\n';
    }
    return 0;
}