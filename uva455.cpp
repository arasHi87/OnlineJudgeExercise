#include <iostream>
#include <cstring>
using namespace std;

bool check( char ans[85], int k ) {
    for ( int i = 0; i < strlen(ans) / k; i++ ) {
        for ( int j = i*k; j < (i+1)*k; j++) {
            if (ans[j] != ans[j%k]) {
                 return false;
            }
        }
    }
    if (strlen(ans) / k * k != strlen(ans)) return false;
    return true;
}

int main() {
    int n;
    char input[85];

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        cin >> input;
        for ( int j = 0; j < strlen(input); j++ ) {
            if ( check(input, j + 1 ) ) {
                cout << j + 1 << endl;
                if ( i+1 != n) {
                    cout << endl;
                }
                j = strlen(input);
            }
        }
    } 
}