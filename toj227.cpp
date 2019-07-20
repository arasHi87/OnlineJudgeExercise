#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> water;

int main() {
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ ) {
        int n, x, m, pa, pb;
        cin >> n;
        for ( int j = 0; j < n; j++ ) {
            cin >> x;
            water.push_back(x);
        }
        if ( water.size()%2 == 0 ) m = water.size()/2;
        else m = (water.size() + 1)/2;
        cout << "m : " << m << '\n';
        sort( water.begin(), water.end() );
        pa = water[m -1];
        pb = water[m];
        cout << pa << " " << pb << '\n';
        water.clear();
    }
}