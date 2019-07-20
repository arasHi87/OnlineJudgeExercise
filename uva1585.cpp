#include <iostream>
using namespace std;

int main() {
    int now_score, total_score, string_length, n;
    bool judge = false;
    string input;
    now_score = total_score = 0;

    cin >> n;

    for ( int i = 0; i < n; i++ ) {
        cin >> input;
        string_length = input.length();
        for ( int j = 0; j < string_length; j++ ) {
            if ( input[j] == 'O') {
                now_score += 1;
                total_score += now_score;
            } else {
                now_score = 0;
            }
        }
        cout << total_score << endl;
        now_score = 0;
        total_score = 0;
    }
}