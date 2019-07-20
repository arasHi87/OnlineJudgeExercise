#include <iostream>
using namespace std;

int main() {
    char input[5][5];
    bool A, B, J;
    A = B = J = false;
    for ( int i = 0; i < 3; i++ ) {
        for ( int j = 0; j < 3; j++ ) {
            char s = getchar();
            if ( s == '#' ) J = true;
            input[i][j] = s;
        }
        getchar();
    }
    // for ( int i = 0; i < 3; i++ ) {
    //     for ( int j = 0; j < 3; j++ ) {
    //         cout << input[i][j];
    //     }
    //     cout << '\n';
    // }
    bool flag = true;
    // 掃橫排
    for ( int i = 0; i < 3; i++) {
        flag = true;
        for ( int j = 0; j < 3; j++ ) {
            if ( input[i][j] != input[i][0] ) {
                // cout << "I:" << i << ":j:" << j << endl;
                // cout << input[i][j] << endl;
                flag = false;
                break;
            }
        }
        if ( flag ) {
            if ( input[i][0] == 'O' ) A = true;
            else if ( input[i][0] == 'X' ) B = true; 
        }
    }
    // 掃直排
    for ( int i = 0; i < 3; i++ ) {
        flag = true;
        for ( int j = 0; j < 3; j++) {
            if ( input[j][i] != input[0][i] ) {
                // cout << "I:" << i << ":j:" << j << endl;
                // cout << input[j][i] << endl;
                flag = false;
                break;
            }
        }
        if ( flag ) {
            if ( input[i][0] == 'O' ) A = true;
            else if ( input[i][0] == 'X' ) B = true; 
        }
    }
    // 掃交叉
    if ( input[0][0] == input[1][1] && input[1][1] == input[2][2]) {
        if ( input[0][0] == 'O' ) A = true;
        else if ( input[0][0] == 'X' ) B = true; 
    }
    if ( input[0][2] == input[1][1] && input[1][1] == input[2][0]) {
        if ( input[0][2] == 'O' ) A = true;
        else if ( input[0][2] == 'X' ) B = true; 
    }

    if ( A && B) cout << "A wins." << '\n'; 
    else if ( A ) cout << "A wins." << '\n';
    else if ( B ) cout << "B wins." << '\n';
    else if ( J ) cout << "Playing" << '\n';
    else cout << "Draw" << '\n';
    return 0;
}