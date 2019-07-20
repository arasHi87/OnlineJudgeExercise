#include <iostream>
#include <vector>
using namespace std;

vector<int> up;
vector<int> down;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    for ( int i = 0; i < n; i++ )
    {
        if ( s1[i] == '0' )
        {
        if ( s2[i] == '0' || s2[i+1] == '0' || s2[i-1] == '0' ) { cout << "FENESTRATION FORTIFICATION FAILURE!" << '\n'; return 0; }
        }
    }
    cout << "FENDED OFF!" << endl;
    return 0;
}