#include <bits/stdc++.h>
using namespace std;
void Dbg() { puts(""); }
template<typename T, typename ...Args> void Dbg(T x, Args ...args) {
    printf("%d ", x);
    Dbg(args...);
}