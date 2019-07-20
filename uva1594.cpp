#include <iostream>
#include <set>
using namespace std;

int input[20], b[20];

int abs (int x) {
    return x < 0 ? -x : x;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        set<int> s;
        cin >> t;
        for (int j = 0; j < t; j++)  cin >> input[j];
        input[t] = input[0];

        while (true) {
            int hash = 0, seed = 131;
            for (int j = 0; j < t; j++) hash = hash * seed + input[j];
            if (hash == 0) { cout << "ZERO" << '\n'; break; }
            if (s.count(hash) == 1) { cout << "LOOP" << '\n'; break; }
            s.insert(hash);
            for (int j = 0; j < t; j++) {
                b[j] = abs(input[j] - input[j+1]);
            }
            b[t] = b[0];
            for (int j = 0; j <= t; j++) {
                input[j] = b[j];
            }
        }
    }
}