#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) return 0;
        map<int, int> stud;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            stud[a]--; stud[b]++;
        }
        bool flag = true;
        for (auto it = stud.begin(); it != stud.end(); it++) {
            if (it->second < 0) {
                flag = !flag;
                break;
            }
        }
        if (flag) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}