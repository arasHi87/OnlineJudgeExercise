#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;

int main () {
    string input[5];
    bool flag = true;
    int k = 1;

    // memset(input, 0, sizeof(input));

    while ( flag ) {
        int x, y;

        for (int i = 0; i < 5; i++)
        {
            cin >> input[i];
        }

        // if (input[0][0] == 'Z')
        //     return 0;

        // for (int i = 0; i < 5; i++)
        // {
        //     for ( int j = 0; j < 5; j++) {
        //         if ( input[i][j] == ' ' ) {
        //             x = j, y = i;
        //             cout << x << i << endl;
        //         }
        //     }
        // }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << input[i][j] << " ";
            }
            cout << endl;
        }

        // string cmd;
        // bool jg = true;

        // cin >> cmd;

        // for (int i = 0; i < cmd.length(); i++)
        // {
        //     if ( jg )
        //     {
        //         switch (cmd[i])
        //         {
        //             case 'A':
        //                 if (y - 1 < 0)
        //                 {
        //                     jg = false;
        //                     break;
        //                 }
        //                 swap(input[y][x], input[y - 1][x]);
        //                 y = y - 1;
        //                 break;

        //             case 'B':
        //                 if (y + 1 > 4)
        //                 {
        //                     jg = false;
        //                     break;
        //                 }
        //                 swap(input[y][x], input[y + 1][x]);
        //                 y = y + 1;
        //                 break;

        //             case 'L':
        //                 if (x - 1 < 0)
        //                 {
        //                     jg = false;
        //                     break;
        //                 }
        //                 swap(input[y][x], input[y][x - 1]);
        //                 x = x - 1;
        //                 break;

        //             case 'R':
        //                 if (x + 1 > 4)
        //                 {
        //                     jg = false;
        //                     break;
        //                 }
        //                 swap(input[y][x], input[y][x + 1]);
        //                 x = x + 1;
        //                 break;

        //             default:
        //                 jg = false;
        //                 break;
        //         }
        //     }
        // }

        // cout << "Puzzle #" << k << ":" << endl;
        // for (int i = 0; i < 5; i++)
        // {
        //     for (int j = 0; j < 5; j++)
        //     {
        //         cout << input[i][j] << " ";
        //     }
        //     cout << endl;
        // }
    }
}