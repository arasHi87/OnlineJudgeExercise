#include <iostream>
#include <queue>
using namespace std;

queue<int> que;

int main() {
    int a;
    while (cin >> a) {
        if (a == 0) break;
        for (int i = 1; i <= a; i++) que.push(i);
        cout << "Discarded cards:";
        bool jg = false;
        while (que.size() != 1) {
            if (jg) cout << ",";
            jg = true;
            cout << " " << que.front();
            que.pop();
            que.push(que.front());
            que.pop();
        }
        cout << '\n' << "Remaining card: " << que.front() << '\n';
        que.pop();
    }
}