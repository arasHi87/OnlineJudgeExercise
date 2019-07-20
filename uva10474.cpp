#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> input;

int main() {
    int n, q, x, y, kase = 1;
    while (cin >> n >> q) {
        if (n == 0 && q == 0) return 0;
        cout << "CASE# " << kase << ":" << '\n';
        for (int i = 0; i < n; i++) {
            cin >> x;
            input.push_back(x);
        }
        sort(input.begin(), input.end());
        // for (auto it = input.begin(); it != input.end(); it++) {
        //     cout << *it << " ";
        // }
        // cout << '\n';
        for (int i = 0; i < q; i++) {
            cin >> x;
            y = lower_bound(input.begin(), input.end(), x) - input.begin();
            // cout << "y:" << y << '\n';
            if (x == input[y]) cout << x << " found at " << y+1 << '\n';
            else cout << x << " not found" << '\n';
        }
        kase++;
        input.clear();
    }
}