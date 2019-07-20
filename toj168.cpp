#include <cstdio>
#include <stack>

std::stack<int> st;

int main() {
    int n, x;
    while (~scanf("%d", &n)) {
        while (n--) {
            scanf("%d", &x);
            while (!st.empty() && x>=st.top()) st.pop();
            st.push(x);
        }
        printf("%lu\n", st.size());
    }
}