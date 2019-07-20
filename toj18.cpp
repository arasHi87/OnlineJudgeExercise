#include <iostream>
#include <cctype>
#include <vector>
using namespace std;

vector<string> a;
vector<char> t;

int main () {
    string s;

    while ( getline(cin, s) ) {
        if ( s == "EOF" ) break;
        a.push_back(s);
    }
    for ( vector<string>::iterator it = a.begin(); it != a.end(); it++ ) {
        string s = *it;
        for ( int i = 0; i < s.length(); i++ ) {
            char t1 = s[i];
            if ( isalpha(t1) ) t.push_back(tolower(t1));
        }
        int b = t.size() / 2;
        int c = t.size() - 1;
        bool flag = true;
        for ( int i = 0; i < b; i++ ) {
            if ( t[i] != t[c] ){
                flag = false;
                break;
            }
            c--;
        }
        t.clear();
        if ( flag ) {
            cout << "SETUP! " << s << '\n';
        } else {
            flag = true;
            cout << s << '\n';
        }
    }
    return 0;
}