#include <iostream>
#include <cstring>
#define maxN 10005
using namespace std;

int main() {
    int n, a[maxN], b[10];
    memset(a, 0, sizeof(a));

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        int input;
        memset(b, 0, sizeof(b));

        cin >> input;

        for ( int j = 1; j <= input; j++ ) {
            a[j] = j;
            do {
                int k = a[j] % 10;
                b[k] += 1;
                a[j]  = a[j] / 10;
            } while ( a[j] != 0 );
        }
        for ( int j = 0; j < 10; j++ ) {
            cout << b[j];
            if ( j != 9 ) {
                cout << ' ';
            }
        }
        cout << endl;
    }
}