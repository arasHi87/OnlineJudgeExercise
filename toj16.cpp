#include <iostream>
#include <memory.h>
#include <vector>
#define maxN 30005
using namespace std;

bool found[maxN] = {false};
vector<int> stud;

int main()
{
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ ) {
        int s, m, q, w;
        cin >> s;
        for ( int j = 0; j < s; j++ ) {
            cin >> m;
            stud.push_back(m);
        }
        for ( auto it = stud.begin(); it != stud.end(); it++ ) {
            if ( *it != 0 ) {
                for (auto pre = it + 1; pre != stud.end(); pre++)
                    if (*pre != 0) {
                        found[*pre + *it] = true;
                    }
            }
        }
        cin >> q;
        for ( int j = 0; j < q; j++ ) {
            cin >> w;
            if ( found[w] ) cout << "Good!" << '\n';
            else cout << "So Bad!" << '\n';
        }
        stud.clear();
        memset(found, false, maxN);
    }
    return 0;
}