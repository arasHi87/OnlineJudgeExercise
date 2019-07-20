#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long double x1, y1, r1, x2, y2, r2, dis;
    while ( cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 ) {
        dis = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
        if ( dis <= r1 + r2) cout << "Quick in" << '\n';
        else cout << "Nearly" << '\n';
    }
    return 0;
}