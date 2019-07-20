#include <iostream>
using namespace std;

int main() {
    int a[10][10];
    for ( int i = 0; i < 5; i++ )
        for ( int j = 0; j< 6; j++ )
        cin >> a[i][j];
    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            if ( a[i][j] == a[i][j+1] && a[i][j] == a[i][j+2] ) { cout << "Yes" << endl; return 0; }
            if ( a[i][j] == a[i+1][j] && a[i][j] == a[i+2][j] ) { cout << "Yes" << endl; return 0; }
        }
    }
    cout << "No" << endl;
}