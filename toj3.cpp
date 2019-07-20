#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for ( int i = 0; i < n; i++ ) {
        int a, b, t;
        cin >> a >> b;
        while ( b != 0 ) {
            t = b;
            b = a%b;
            a = t;
        }
        cout << a << '\n';
    }
}