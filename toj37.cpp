#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int cnt=0;
        string s;
        stringstream ss(line);
        while (ss>>s) cnt++;
        printf("%d\n", cnt);
    }
}